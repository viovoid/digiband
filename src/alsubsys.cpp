#include <iostream>
using namespace std;

#include <AL/al.h>
#include <AL/alc.h>
#include <pthread.h>

#include "alsubsys.h"
using namespace Oswego::AL;

static bool al_up = false;
static list< string > consumers;
static pthread_mutex_t subsys_mutex;

static ALCdevice *al_device;
static ALCcontext *al_context;

void Oswego::AL::alsubsys_setup() {
	pthread_mutex_init(&subsys_mutex, NULL);
}

void Oswego::AL::register_consumer(const string &name) {
	pthread_mutex_lock(&subsys_mutex);

	if (!al_up) {
		al_init();
	}

	consumers.push_back(name);

	pthread_mutex_unlock(&subsys_mutex);
}

void Oswego::AL::free_consumer(const string &name) {
	pthread_mutex_lock(&subsys_mutex);

	consumers.remove(name);

	if (al_up && consumers.empty()) {
		al_cleanup();
	}

	pthread_mutex_unlock(&subsys_mutex);
}

void Oswego::AL::al_init() {
	al_device = alcOpenDevice(NULL);
	al_context = alcCreateContext(al_device, NULL);
	alcMakeContextCurrent(al_context);

#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << ": al has init'ed" << endl;
#endif

	al_up = true;
}

void Oswego::AL::al_cleanup() {
	alcMakeContextCurrent(NULL);
	alcDestroyContext(al_context);
	alcCloseDevice(al_device);

#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << ": al has exited" << endl;
#endif

	al_up = false;
}
