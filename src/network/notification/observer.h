
#ifndef WSN_OBSERVER_H
#define WSN_OBSERVER_H



#include "event.h"

namespace wsn {

    namespace notification {


        class Observer {

        public:
            Observer() {}
            virtual void handleEvent(Event event, const void* const sender) = 0;

        };
    }
}

#endif //WSN_OBSERVER_H
