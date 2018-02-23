
#ifndef WSN_DATA_RECEIVE_EVENT_H
#define WSN_DATA_RECEIVE_EVENT_H


#include "../../model/node/node.h"
#include "event.h"

namespace wsn {

    namespace notification {

        class DataReceiveEvent : public Event {

        public:
            DataReceiveEvent(const wsn::model::Node *node, wsn::model::Data data);

            EventType getEventType() const;

            const wsn::model::Node * const getReceivedNode() const;
            const wsn::model::Data& getReceivedData() const;


        private:
            const wsn::model::Node * const node;
            const wsn::model::Data data;
        };

    }
}

#endif //WSN_DATA_RECEIVE_EVENT_H
