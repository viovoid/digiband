#ifndef OSWEGO__AL__MADCODEC
#define OSWEGO__AL__MADCODEC

#include <mad.h>

#include "codec.h"

namespace Oswego {
	namespace AL {
		// adapted from mpg321 source
		class MadAudioDither {
			public:
				mad_fixed_t error[3];
				mad_fixed_t random;

				static mad_fixed_t prng(mad_fixed_t state);

				MadAudioDither();
		};

		class MadCodec: public Codec {
			public:
				MadCodec();
				virtual ~MadCodec();

				virtual bool is_compatible(const string &fname);
				virtual int open(const string &fname);
				virtual void restart();
				virtual size_t fill_buffer(void *data, const ALsizei size);
				virtual void close();
			private:
				FILE *mp3file;
				unsigned char *mp3file_start;
				size_t mp3file_length;
				mad_frame *mp3_frame;
				mad_stream *mp3_stream;
				mad_synth *mp3_synth;
				MadAudioDither *dither;

				int channels;

				unsigned char *decoded_queue;
				size_t decoded_queue_size;

				void fill_decoded_queue(mad_header &header, mad_pcm &pcm);
				inline signed int scale(mad_fixed_t sample);
				//void scan_format();				
				bool scan_decode();

				// manage the decoded queue
				bool shift_decoded_queue(void *output, size_t length);
				bool push_decoded_queue(unsigned char *input, size_t length);
		};

		Codec *madcodec_ctor();
	}
}

#endif
