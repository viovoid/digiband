#ifndef OSWEGO__AL__ALSUBSYS
#define OSWEGO__AL__ALSUBSYS

#include <string>
#include <list>
using namespace std;

namespace Oswego {
	namespace AL {
		void register_consumer(const string &name);	// FIXME: This doesn't check if the consumer's already been added
		void free_consumer(const string &name);

		void al_init();
		void al_cleanup();

		void alsubsys_setup() __attribute__((constructor));
	}
}

#endif
