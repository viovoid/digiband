#ifdef DEBUG
#include <iostream>
using namespace std;
#endif

#include "sndfilecodec.h"
using namespace Oswego::AL;

SndFileCodec::SndFileCodec() {
}

bool SndFileCodec::is_compatible(const string &fname) {
	bool compat;

	memset(&info, 0, sizeof(SF_INFO));
	sndfile = sf_open(fname.c_str(), SFM_READ, &info);
	if (sndfile == NULL) {
		return false;
	} else {
		sf_close(sndfile);
		return true;
	}
}

int SndFileCodec::open(const string &fname) {
	memset(&info, 0, sizeof(SF_INFO));
	sndfile = sf_open(fname.c_str(), SFM_READ, &info);

	if (info.channels == 1) {
		format = AL_FORMAT_MONO16;
	} else {
		format = AL_FORMAT_STEREO16;
	}
	frequency = info.samplerate;
}

void SndFileCodec::restart() {
	sf_seek(sndfile, 0, SEEK_SET);
}

size_t SndFileCodec::fill_buffer(void *data, ALsizei size) {
	size_t totalread = sf_read_short(sndfile, (short *)data, size / 2) * 2;

	return totalread;
}

void SndFileCodec::close() {
	sf_close(sndfile);
}
