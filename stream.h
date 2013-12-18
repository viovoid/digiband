#ifndef OSWEGO__AL__STREAM
#define OSWEGO__AL__STREAM

#include <string>
#include <list>
#include <map>
using namespace std;

#include <AL/al.h>
#include <pthread.h>

#include "codec.h"

namespace Oswego {
	namespace AL {
		enum StreamState {
			STATE_CLOSED,
			STATE_STOPPED,
			STATE_PLAYING,
			STATE_PAUSED
		};

		typedef void (*stream_vis_callback)(void *pcm_data, size_t data_length, void *extra);

		class Stream {
			friend void *buffer_monitor(void *data);

			public:
				static const ALsizei BUFFER_SIZE;
				static const int NUM_BUFFERS;
				static const int MAX_SOURCES;
				
				static void class_init();
				static void class_shutdown();

				Stream();
				~Stream();

				int open(const string &file);
				int play(bool loop = false, const string &file = "");
				int repeat();
				int pause();
				int stop();
				int close();

				void set_vis_callback(stream_vis_callback cb, void *cb_data);
				
				void set_gain(ALfloat gain);
				StreamState get_state();

			protected:
				StreamState state;
				Codec *codec;
			private:
				ALuint *buffers;
				ALuint source;
				ALfloat src_gain;
				int active_buffers;
				bool eof;
				bool looping;

				stream_vis_callback vis_callback;
				void *vis_param;

				static list< Stream * > playing_streams;
				static pthread_mutex_t playing_streams_mutex;
				static map< ALuint, Stream * > allocated_sources;
				static pthread_mutex_t allocated_sources_mutex;
				static pthread_t monitor_thread;
				static bool run_monitor_thread;
				static list< Stream * > *all_instances;

				void queue_albuffer(ALuint target_buffer);
				void subscribe_monitor();
				void unsubscribe_monitor();
				ALuint get_source();
				void release_source(ALuint src);
		};
	}
}

#endif
