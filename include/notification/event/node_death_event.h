

#ifndef WSN_NODEDEATHEVENT_H
#define WSN_NODEDEATHEVENT_H

#include "model/node/node.h"
#include "event.h"

namespace wsn {

    namespace notification {


        class NodeDeathEvent : public Event {

        public:
            explicit NodeDeathEvent(const wsn::model::Node *node);
            EventType getEventType() const override;
            const wsn::model::Node * const getDeathNode() const ;


        private:
            const wsn::model::Node * const node;
        };

    }
}

#endif //WSN_NODEDEATHEVENT_H
