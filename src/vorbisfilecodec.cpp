#ifdef DEBUG
#include <iostream>
using namespace std;
#endif

#include "vorbisfilecodec.h"
using namespace Oswego::AL;

VorbisFileCodec::VorbisFileCodec() {
}

bool VorbisFileCodec::is_compatible(const string &fname) {
	if (!(file = fopen(fname.c_str(), "rb"))) {
		return false;
	}

	oggfile = (OggVorbis_File *)malloc(sizeof(OggVorbis_File));
	bool compat = (ov_test(file, oggfile, NULL, 0) == 0);

	if (compat) {
		ov_clear(oggfile);	// frees oggfile and fcloses file
	} else {
		fclose(file);
	}

	free(oggfile);

	return compat;
}

int VorbisFileCodec::open(const string &fname) {
	if (!(file = fopen(fname.c_str(), "rb"))) {
		return -1;
	}

	oggfile = (OggVorbis_File *)malloc(sizeof(OggVorbis_File));
	if (ov_open(file, oggfile, NULL, 0) < 0) {
		return -1;
	}

	info = ov_info(oggfile, -1);
	if (info->channels == 1) {
		format = AL_FORMAT_MONO16;
	} else {
		format = AL_FORMAT_STEREO16;
	}
	frequency = info->rate;

	return 0;
}

void VorbisFileCodec::restart() {
	ov_time_seek(oggfile, 0);
}

size_t VorbisFileCodec::fill_buffer(void *data, ALsizei size) {
	size_t totalread = 0;
	int read = -1;
	int section;

	while (totalread < size && read != 0) {
		read = ov_read(oggfile, (char *)data + totalread, size - totalread, 0, 2, 1, &section);

		if (read < 0) {
			return 0;
		} else {
			totalread += read;
		}
	}

	return totalread;
}

void VorbisFileCodec::close() {
	ov_clear(oggfile);	// frees oggfile, info and fcloses file
	free(oggfile);
}
