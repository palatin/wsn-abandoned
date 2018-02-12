
#ifndef WSN_OBSERVER_H
#define WSN_OBSERVER_H



#include "../notification/event/event.h"

namespace wsn {

    namespace notification {


        class Observer {

        public:
            Observer() {}
            virtual void handleEvent(const Event &event) = 0;

        };
    }
}

#endif //WSN_OBSERVER_H
