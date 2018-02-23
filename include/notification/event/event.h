

#ifndef WSN_EVENT_H
#define WSN_EVENT_H

namespace wsn {

    namespace notification {

        enum EventType {
            NodeDeath,
            DataReceive
        };

        class Event {


        public:
            Event() = default;
            virtual EventType getEventType() const = 0;


        };

    }
}
#endif //WSN_EVENT_H
