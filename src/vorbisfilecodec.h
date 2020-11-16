#ifndef OSWEGO__AL__VORBISFILECODEC
#define OSWEGO__AL__VORBISFILECODEC

#include <vorbis/vorbisfile.h>

#include "codec.h"

namespace Oswego {
	namespace AL {
		class VorbisFileCodec: public Codec {
			public:
				VorbisFileCodec();

				virtual bool is_compatible(const string &fname);
				virtual int open(const string &fname);
				virtual void restart();
				virtual size_t fill_buffer(void *data, const ALsizei size);
				virtual void close();
			private:
				FILE *file;
				OggVorbis_File *oggfile;
				vorbis_info *info;
		};

		Codec *vorbisfilecodec_ctor();
	}
}

#endif
