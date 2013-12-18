#ifndef OSWEGO__AL__CODEC
#define OSWEGO__AL__CODEC

#include <string>
#include <list>
using namespace std;

#include <AL/al.h>

namespace Oswego {
	namespace AL {
		class Codec;
		typedef Codec *(*codec_ctor)();

		/**
		 * Abstract interface to define a way to decode audio from a file.
		 * For now, we'll make the assumption that this file contains one
		 * and only one audio stream.
		 */
		class Codec {
			public:
				static Codec *find_codec(const string &fname);

				ALenum format;
				ALsizei frequency;

				virtual ~Codec();

				/**
				 * Returns whether or not this codec can be used to
				 * decode this file.
				 */
				virtual bool is_compatible(const string &fname) = 0;

				/**
				 * Opens a file and allocates any internal structures
				 * needed to decode the file.
				 */
				virtual int open(const string &fname) = 0;

				virtual void restart() = 0;

				/**
				 * Attempts to fill $data with $size bytes of audio.
				 * Returns the number of bytes that were read.  If it
				 * returns a smaller number than you were expecting,
				 * that means the file is most likely at EOF
				 */
				virtual size_t fill_buffer(void *data, const ALsizei size) = 0;

				/**
				 * Closes the file and cleans up.
				 */
				virtual void close() = 0;
			protected:
				Codec();
				Codec(Codec &copy);
			private:
				static list< codec_ctor > available_codec_ctors;
		};
	}
}

#endif
