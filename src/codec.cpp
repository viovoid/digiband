#include "codec.h"
using namespace Oswego::AL;

list< codec_ctor > Codec::available_codec_ctors;

Codec *Codec::find_codec(const string &fname) {
	return NULL;
	/*
	for (list< codec_ctor >::iterator i = available_codec_ctors.start(); i != available_codec_ctors.end(); i++) {
		
	}
	*/
}

Codec::Codec() {
}

Codec::Codec(Codec &copy) {
}

Codec::~Codec() {
}
