#include <iostream>
using namespace std;

#include <unistd.h>

#include "alsubsys.h"
#include "stream.h"
#include "madcodec.h"
#include "vorbisfilecodec.h"
#include "sndfilecodec.h"
using namespace Oswego::AL;

const ALsizei Stream::BUFFER_SIZE = 32 * 1024;	// seems to work well
const int Stream::NUM_BUFFERS = 4;				// ditto
const int Stream::MAX_SOURCES = 256;			// ditto

list< Stream * > Stream::playing_streams;
pthread_mutex_t Stream::playing_streams_mutex;
map< ALuint, Stream * > Stream::allocated_sources;
pthread_mutex_t Stream::allocated_sources_mutex;
pthread_t Stream::monitor_thread;
list< Stream * > *Stream::all_instances = NULL;
bool Stream::run_monitor_thread = false;

void *Oswego::AL::buffer_monitor(void *data);

void Stream::class_init() {
	ALuint src;

	Oswego::AL::register_consumer("Oswego::AL::Stream");
		
	alGetError();
	alGenSources(1, &src);
	while (alGetError() == AL_NO_ERROR && allocated_sources.size() < MAX_SOURCES) {

		allocated_sources[src] = NULL;
		alGenSources(1, &src);
	}
		
#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << ": I managed to gen " << allocated_sources.size() << " sources" << endl;
#endif
		
	pthread_mutex_init(&allocated_sources_mutex, NULL);
	pthread_mutex_init(&playing_streams_mutex, NULL);

	run_monitor_thread = true;
	pthread_create(&monitor_thread, NULL, &Oswego::AL::buffer_monitor, NULL);
}

void Stream::class_shutdown() {
	for (list< Stream * >::iterator i = all_instances->begin(); i != all_instances->end(); i++) {
		(*i)->stop();
	}

	// shut down the monitor thread
	run_monitor_thread = false;
	pthread_join(monitor_thread, NULL);

	// clean up our sources
	for (map< ALuint, Stream * >::iterator i = allocated_sources.begin(); i != allocated_sources.end(); i++) {
		alSourceStop(i->first);
		alSourcei(i->first, AL_BUFFER, 0);
		alDeleteSources(1, &(i->first));
	}

	Oswego::AL::free_consumer("Oswego::AL::Stream");
}

Stream::Stream() {
	// this may not be thread-safe, but i'd rather do this than mess around with __attribute__((init_priority()))
	if (all_instances == NULL)
		all_instances = new list< Stream * >;

	all_instances->push_back(this);

	state = STATE_CLOSED;
	vis_callback = NULL;
	vis_param = NULL;
	src_gain = 1.0;
}

Stream::~Stream() {
	if (state != STATE_CLOSED) {
		close();
	}

	all_instances->remove(this);
}

int Stream::open(const string &file) {
	if (state != STATE_CLOSED) {
		close();
	}

	eof = false;

	codec = new VorbisFileCodec();
	if (codec->is_compatible(file)) {
#ifdef DEBUG
		cout << __PRETTY_FUNCTION__ << ": Looks like a vorbis file." << endl;
#endif
		if (codec->open(file) == -1) {
#ifdef DEBUG
			cout << __PRETTY_FUNCTION__ << ": Code monkey not feeling so great." << endl;
#endif
		}
	} else {
		delete codec;
		codec = new SndFileCodec();
		if (codec->is_compatible(file)) {
#ifdef DEBUG
			cout << __PRETTY_FUNCTION__ << ": Looks like a sndfile file." << endl;
#endif
			if (codec->open(file) == -1) {
#ifdef DEBUG
				cout << __PRETTY_FUNCTION__ << ": Code monkey not feeling so great." << endl;
#endif
			}
		} else {
			delete codec;
			codec = new MadCodec();
			if (codec->is_compatible(file)) {
#ifdef DEBUG
				cout << __PRETTY_FUNCTION__ << ": Looks like an mp3 file." << endl;
#endif
				if (codec->open(file) == -1) {
#ifdef DEBUG
					cout << __PRETTY_FUNCTION__ << ": Code monkey not feeling so great." << endl;
#endif
				}
			} else {
#ifdef DEBUG
				cout << __PRETTY_FUNCTION__ << ": Code monkey have long walk back to cubicle." << endl;
#endif
				return -1;
			}
		}
	}

	buffers = (ALuint *)malloc(sizeof(ALuint) * NUM_BUFFERS);
	alGenBuffers(NUM_BUFFERS, buffers);
	queue_albuffer(buffers[0]);
	active_buffers = 1;

	state = STATE_STOPPED;

	return 0;
}

int Stream::play(bool loop, const string &file) {
	if (file != "") {
		open(file);
	}

	bool needs_prefill = state == STATE_STOPPED;

	if (state == STATE_STOPPED || state == STATE_PAUSED) {
		looping = loop;
		state = STATE_PLAYING;
	} else if (state == STATE_PLAYING) {
		stop();
		state = STATE_PLAYING;
		needs_prefill = true;
	} else {
		return -1;
	}

	// play right away while we fill up extra buffers
	if (needs_prefill) {
		source = get_source();
#ifdef DEBUG0
		cout << __PRETTY_FUNCTION__ << ": instance #" << (uint32_t)this << " is using source " << source << endl;
#endif
		alSourceQueueBuffers(source, 1, buffers + 0);
	}
	
	alSourcef(source, AL_GAIN, src_gain);
	alSourcePlay(source);

	if (needs_prefill) {
		for (int i = 1; i < NUM_BUFFERS && !eof; i++, active_buffers++) {
			queue_albuffer(buffers[i]);
			alSourceQueueBuffers(source, 1, buffers + i);
		}
	}

	subscribe_monitor();

	return 0;
}

int Stream::repeat() {
	if (state == STATE_CLOSED) {
		return -1;
	}

	eof = false;

	codec->restart();

	return 0;
}

int Stream::pause() {
	if (state == STATE_PLAYING) {
		state = STATE_PAUSED;
	} else {
		return -1;
	}

	unsubscribe_monitor();
	alSourcePause(source);

	return 0;
}

int Stream::stop() {
	if (state == STATE_PLAYING || state == STATE_PAUSED) {
		state = STATE_STOPPED;
	} else {
		return -1;
	}

	unsubscribe_monitor();
	alSourceStop(source);
	alSourcei(source, AL_BUFFER, 0);
	release_source(source);

	// get it ready to play again
	repeat();
	queue_albuffer(buffers[0]);
	active_buffers = 1;

	return 0;
}

int Stream::close() {
	if (state == STATE_CLOSED) {
		return -1;
	} else if (state != STATE_STOPPED) {
		stop();
	}

	codec->close();
	delete codec;

	alDeleteBuffers(NUM_BUFFERS, buffers);
	free(buffers);

	state = STATE_CLOSED;

	return 0;
}

void Stream::set_vis_callback(stream_vis_callback cb, void *cb_data) {
	vis_callback = cb;
	vis_param = cb_data;
}

void Stream::set_gain(ALfloat gain) {
	src_gain = gain;
	
	if (state == STATE_PLAYING || state == STATE_PAUSED) {
		alSourcef(source, AL_GAIN, src_gain);
	}
}

StreamState Stream::get_state() {
	return state;
}

void Stream::queue_albuffer(ALuint target_buffer) {
	size_t amount_read;
	void *data = malloc(BUFFER_SIZE);

	eof = (amount_read = codec->fill_buffer(data, BUFFER_SIZE)) < BUFFER_SIZE;

	alBufferData(target_buffer, codec->format, data, amount_read, codec->frequency);

	if (vis_callback) {
		vis_callback(data, amount_read, vis_param);
	}

	free(data);
}

void Stream::subscribe_monitor() {
	pthread_mutex_lock(&playing_streams_mutex);
	playing_streams.push_back(this);
	pthread_mutex_unlock(&playing_streams_mutex);
}

void Stream::unsubscribe_monitor() {
	pthread_mutex_lock(&playing_streams_mutex);
	playing_streams.remove(this);
	pthread_mutex_unlock(&playing_streams_mutex);
}

void *Oswego::AL::buffer_monitor(void *data) {
	ALint bufs_avail;
	ALenum state;
	Stream *cur_stream;
	list< Stream * > stopped_streams;

#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << ": Starting" << endl;
#endif

	Oswego::AL::register_consumer("Oswego::AL::Stream::buffer_monitor");

	while (Stream::run_monitor_thread) {
		pthread_mutex_lock(&Stream::playing_streams_mutex);

		for (list< Stream * >::iterator i = Stream::playing_streams.begin(); i != Stream::playing_streams.end(); i++) {
			cur_stream = *i;

			if (!cur_stream->eof) {
				alGetSourcei(cur_stream->source, AL_BUFFERS_PROCESSED, &bufs_avail);
#ifdef DEBUG
				if (bufs_avail > 1) {
					cout << __PRETTY_FUNCTION__ << ": " << bufs_avail << " buffers are empty!" << endl;
				}
#endif
				for (int i = 0; i < bufs_avail && !cur_stream->eof; i++) {
					ALuint curbuf;
					alSourceUnqueueBuffers(cur_stream->source, 1, &curbuf);

					cur_stream->queue_albuffer(curbuf);
					alSourceQueueBuffers(cur_stream->source, 1, &curbuf);
				}

				alGetSourcei(cur_stream->source, AL_SOURCE_STATE, &state);
				if (state != AL_PLAYING) {
					alSourcePlay(cur_stream->source);
				}
			}
			if (cur_stream->eof) {
				if (cur_stream->state == STATE_PLAYING && !cur_stream->looping) {
					alGetSourcei(cur_stream->source, AL_BUFFERS_PROCESSED, &bufs_avail);
					if (bufs_avail == cur_stream->active_buffers) {
						stopped_streams.push_back(cur_stream);
					}
				} else if (cur_stream->state == STATE_PLAYING && cur_stream->looping) {
					cur_stream->repeat();
				} else {
					cerr << __PRETTY_FUNCTION__ << "GIT-R-DONE DRIVER!" << endl;
				}
			}
		}

		pthread_mutex_unlock(&Stream::playing_streams_mutex);

		for (; !stopped_streams.empty(); stopped_streams.pop_front()) {
			stopped_streams.front()->stop();
		}

		usleep(10000);
	}

	Oswego::AL::free_consumer("Oswego::AL::Stream::buffer_monitor");

#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << ": Exiting" << endl;
#endif

	return NULL;
}

ALuint Stream::get_source() {
	pthread_mutex_lock(&Stream::allocated_sources_mutex);
	
	bool winrar = false;
	ALuint ret;
	while (winrar == false) {
		for (map< ALuint, Stream *>::iterator i = allocated_sources.begin(); i != allocated_sources.end() && !winrar; i++) {
			if (i->second == NULL) {
				ret = i->first;
				winrar = true;
			}
		}
		
		if (winrar == true) {
			allocated_sources[ret] = this;
		}
		
		pthread_mutex_unlock(&Stream::allocated_sources_mutex);
		
		if (winrar == false) {
			usleep(10000);
			pthread_mutex_lock(&Stream::allocated_sources_mutex);
		}
	}

	return ret;
}

void Stream::release_source(ALuint src) {
	pthread_mutex_lock(&Stream::allocated_sources_mutex);
	
	allocated_sources[src] = NULL;
	
	pthread_mutex_unlock(&Stream::allocated_sources_mutex);
}
