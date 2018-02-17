#include "notification/event/node_death_event.h"


wsn::notification::NodeDeathEvent::NodeDeathEvent(const wsn::model::Node *const node) : node(node) {

}

wsn::notification::EventType wsn::notification::NodeDeathEvent::getEventType() const {
    return EventType::NodeDeath;
}



const wsn::model::Node *const wsn::notification::NodeDeathEvent::getDeathNode() const {
    return node;
}
