#ifndef OSWEGO__AL__SNDFILECODEC
#define OSWEGO__AL__SNDFILECODEC

#include <sndfile.h>

#include "codec.h"

namespace Oswego {
	namespace AL {
		class SndFileCodec: public Codec {
			public:
				SndFileCodec();

				virtual bool is_compatible(const string &fname);
				virtual int open(const string &fname);
				virtual void restart();
				virtual size_t fill_buffer(void *data, const ALsizei size);
				virtual void close();
			private:
				SNDFILE *sndfile;
				SF_INFO info;
		};

		Codec *sndfilecodec_ctor();
	}
}

#endif
