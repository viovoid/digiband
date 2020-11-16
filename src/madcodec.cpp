// minimad.c from the mad tarball was used as an example

#ifdef DEBUG
#include <iostream>
using namespace std;
#endif

#include <sys/stat.h>
#ifndef WIN32
#include <sys/mman.h>
#endif

#include "madcodec.h"
using namespace Oswego::AL;

MadAudioDither::MadAudioDither() {
	error[0] = error[1] = error[2] = 0;
}

mad_fixed_t MadAudioDither::prng(mad_fixed_t state) {
	return (state * 0x0019660dL + 0x3c6ef35fL) & 0xffffffffL;
}

MadCodec::MadCodec() {
	decoded_queue = NULL;
	decoded_queue_size = 0;	

	mp3_stream = (mad_stream *)malloc(sizeof(mad_stream));
	mp3_frame = (mad_frame *)malloc(sizeof(mad_frame));
	mp3_synth = (mad_synth *)malloc(sizeof(mad_synth));
}

MadCodec::~MadCodec() {
	if (decoded_queue != NULL) {
		free((void *)decoded_queue);
	}

	free(mp3_stream);
	free(mp3_frame);
	free(mp3_synth);
}

bool MadCodec::is_compatible(const string &fname) {
	struct stat stats;
	bool compat;

	if (stat(fname.c_str(), &stats) == -1 || stats.st_size == 0) {
		return false;
	}

	if (!(mp3file = fopen(fname.c_str(), "rb"))) {
		return false;
	}

	mp3file_length = stats.st_size;
#ifndef WIN32
	mp3file_start = (unsigned char *)mmap(0, mp3file_length, PROT_READ, MAP_SHARED, fileno(mp3file), 0);
#else
	mp3file_start = (unsigned char *)malloc(stats.st_size);
	fread(mp3file_start, 1, stats.st_size, mp3file);
	fclose(mp3file);
#endif

	if (memcmp(mp3file_start, "ID3", 3) == 0) {
		compat = true;
	} else if (memcmp(mp3file_start, "OggS", 4) == 0) {
		compat = false;
	} else if (memcmp(mp3file_start, "RIFF", 4) == 0) {
		char mp3fmt[2] = {0x55, 0x00};
		if (memcmp(mp3file_start + 20, mp3fmt, 2) == 0) {
			compat = true;
		} else {
			compat = scan_decode();
		}
	} else {
		compat = scan_decode();
	}

#ifndef WIN32
	munmap(mp3file_start, mp3file_length);
	fclose(mp3file);
#else
	free(mp3file_start);
#endif

	return compat;
}

bool MadCodec::scan_decode() {
	mad_stream_init(mp3_stream);
	mad_frame_init(mp3_frame);
	mad_stream_buffer(mp3_stream, mp3file_start, mp3file_length);	

	bool eof = false, compat = true;

	frequency = 0;
	while (!eof) {
		if (mad_header_decode(&mp3_frame->header, mp3_stream) == -1) {
#ifdef DEBUG
			cout << __PRETTY_FUNCTION__ << ": libmad error parsing header at " << mp3_stream->this_frame - mp3file_start << ": " << mad_stream_errorstr(mp3_stream) << endl;
#endif
			if (mp3_stream->error == MAD_ERROR_LOSTSYNC) {
				// according to Audacious' sources, this is probably
				// an ID3 tag
			} else if (mp3_stream->error == MAD_ERROR_BUFLEN) {
				eof = true;
			} else {
				//eof = true;
				//compat = false;
			}
		} else {
			frequency = mp3_frame->header.samplerate;
			if (MAD_NCHANNELS(&mp3_frame->header) == 1) {
				format = AL_FORMAT_MONO16;
				channels = 1;
			} else if (MAD_NCHANNELS(&mp3_frame->header) == 2) {
				format = AL_FORMAT_STEREO16;
				channels = 2;
			} else {
				mad_frame_finish(mp3_frame);
				mad_stream_finish(mp3_stream);
				return false;
			}
		}
		/*
		if (mad_frame_decode(mp3_frame, mp3_stream) == -1) {
			eof = true;
			if (mp3_stream->error != MAD_ERROR_BUFLEN) {
				//compat = false;
			}
		}
		*/
	}

	mad_frame_finish(mp3_frame);
	mad_stream_finish(mp3_stream);

	if (frequency > 0) {
		return compat;
	} else {
		return false;
	}
}

int MadCodec::open(const string &fname) {
	struct stat stats;

	if (!(mp3file = fopen(fname.c_str(), "rb"))) {
		return -1;
	}

	if (fstat(fileno(mp3file), &stats) == -1 || stats.st_size == 0) {
		return -1;
	}

	mp3file_length = stats.st_size;
#ifndef WIN32
	mp3file_start = (unsigned char *)mmap(0, mp3file_length, PROT_READ, MAP_SHARED, fileno(mp3file), 0);
#else
	mp3file_start = (unsigned char *)malloc(stats.st_size);
	fread(mp3file_start, 1, stats.st_size, mp3file);
	fclose(mp3file);
#endif

	if (!scan_decode()) {
#ifndef WIN32
		munmap(mp3file_start, mp3file_length);
		fclose(mp3file);
#else
		free(mp3file_start);
#endif
		return -1;
	}
	
	dither = new MadAudioDither();

	mad_stream_init(mp3_stream);
	mad_frame_init(mp3_frame);
	mad_synth_init(mp3_synth);
	mad_stream_options(mp3_stream, 0);
	mad_stream_buffer(mp3_stream, mp3file_start, mp3file_length);
	
	return 0;
}

void MadCodec::restart() {
	mad_stream_buffer(mp3_stream, mp3file_start, mp3file_length);	
}

size_t MadCodec::fill_buffer(void *data, ALsizei size) {
	bool eof = false;

	while (!shift_decoded_queue(data, size) && !eof) {
		if (mad_header_decode(&mp3_frame->header, mp3_stream) == -1) {
#ifdef DEBUG
			cout << __PRETTY_FUNCTION__ << ": libmad error parsing header at " << mp3_stream->this_frame - mp3file_start << ": " << mad_stream_errorstr(mp3_stream) << endl;
#endif
			if (mp3_stream->error == MAD_ERROR_LOSTSYNC) {
				// according to Audacious' sources, this is probably
				// an ID3 tag
			} else if (mp3_stream->error == MAD_ERROR_BUFLEN) {
					eof = true;
			}
		}

		if (mad_frame_decode(mp3_frame, mp3_stream) == -1) {
			if (mp3_stream->error == MAD_ERROR_BUFLEN) {
				eof = true;
			} else {
				//mad_frame_mute(mp3_frame);
		//		cout << "Skipping" << endl;
		//		mad_stream_skip(&mp3_stream, mp3_stream.next_frame - mp3_stream.this_frame);
			}
#ifdef DEBUG
			cout << __PRETTY_FUNCTION__ << ": libmad error decoding frame at " << mp3_stream->this_frame - mp3file_start << ": " << mad_stream_errorstr(mp3_stream) << endl;
#endif
		}
		
		mad_synth_frame(mp3_synth, mp3_frame);
		fill_decoded_queue(mp3_frame->header, mp3_synth->pcm);
	}

	if (!eof) {
		return size;
	} else {
		size_t finalsize = decoded_queue_size;
		shift_decoded_queue(data, finalsize);
		return finalsize;
	}	
}

void MadCodec::close() {
	mad_frame_finish(mp3_frame);
	mad_stream_finish(mp3_stream);
	mad_synth_finish(mp3_synth);
#ifndef WIN32
	munmap(mp3file_start, mp3file_length);
	fclose(mp3file);
#else
	free(mp3file_start);
#endif

	delete dither;
}

void MadCodec::fill_decoded_queue(mad_header &header, mad_pcm &pcm) {
	unsigned char *buffer = (unsigned char *)malloc(pcm.length * 2 * channels);
	signed int sample;

	unsigned char *buffer_off = buffer;
	for (int i = 0; i < pcm.length; i++, buffer_off += 2 * channels) {
		sample = scale(pcm.samples[0][i]);
		buffer_off[0] = sample & 0xFF;
		buffer_off[1] = (sample >> 8) & 0xFF;
		if (channels > 1) {
			sample = scale(pcm.samples[1][i]);
			buffer_off[2] = sample & 0xFF;
			buffer_off[3] = (sample >> 8) & 0xFF;
		}
	}

	push_decoded_queue(buffer, pcm.length * 2 * channels);
	free(buffer);
}

// taken from mpg321's source (0.2.10)
signed int MadCodec::scale(mad_fixed_t sample) {
	unsigned int scalebits;
	mad_fixed_t output, mask, random;

	enum {
		MIN = -MAD_F_ONE,
		MAX =  MAD_F_ONE - 1
	};

	/* noise shape */
	sample += dither->error[0] - dither->error[1] + dither->error[2];

	dither->error[2] = dither->error[1];
	dither->error[1] = dither->error[0] / 2;

	/* bias */
	output = sample + (1L << (MAD_F_FRACBITS - 16));

	scalebits = MAD_F_FRACBITS + 1 - 16;
	mask = (1L << scalebits) - 1;

	/* dither */
	random  = MadAudioDither::prng(dither->random);
	output += (random & mask) - (dither->random & mask);

	dither->random = random;

	/* clip */
	if (output > MAX) {
		output = MAX;

		if (sample > MAX)
			sample = MAX;
	}
	else if (output < MIN) {
		output = MIN;

		if (sample < MIN)
			sample = MIN;
	}

	/* quantize */
	output &= ~mask;

	/* error feedback */
	dither->error[0] = sample - output;

	/* scale */
	return output >> scalebits;
}

bool MadCodec::shift_decoded_queue(void *output, size_t length) {
	if (decoded_queue_size < length) {
		return false;
	}

	memcpy(output, (void *)decoded_queue, length);
	if (decoded_queue_size - length == 0) {
		free((unsigned char *)decoded_queue);
		decoded_queue = NULL;
		decoded_queue_size = 0;
	} else {
		unsigned char *newq = (unsigned char *)malloc(decoded_queue_size - length);
		memcpy(newq, (unsigned char *)decoded_queue + length, decoded_queue_size - length);
		free((unsigned char *)decoded_queue);
		decoded_queue = newq;
		decoded_queue_size -= length;
	}

	return true;
}

bool MadCodec::push_decoded_queue(unsigned char *input, size_t length) {
	unsigned char *newq = (unsigned char *)malloc(decoded_queue_size + length);
	if (decoded_queue != NULL) {
		memcpy((unsigned char *)newq, (unsigned char *)decoded_queue, decoded_queue_size);
		free((unsigned char *)decoded_queue);
	}
	memcpy((unsigned char *)newq + decoded_queue_size, input, length);
	decoded_queue = newq;
	decoded_queue_size += length;

	return true;
}
