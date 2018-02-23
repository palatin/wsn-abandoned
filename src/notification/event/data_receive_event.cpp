

#include "notification/event/data_receive_event.h"

wsn::notification::DataReceiveEvent::DataReceiveEvent(const wsn::model::Node *node, const wsn::model::Data data) : data(data), node(node) {

}

wsn::notification::EventType wsn::notification::DataReceiveEvent::getEventType() const {
    return DataReceive;
}

const wsn::model::Node *const wsn::notification::DataReceiveEvent::getReceivedNode() const {
    return node;
}

const wsn::model::Data &wsn::notification::DataReceiveEvent::getReceivedData() const {
    return data;
}
