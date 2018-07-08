

#include <notification/event/data_receive_event.h>
#include "model/node/sink.h"
#include "model/node/physics/transmitter.h"

wsn::model::Sink::Sink(unsigned long id, const wsn::model::Point &location) : Node(id, location, 0, 0,
                                                                                   nullptr) {}

bool wsn::model::Sink::sendData(const wsn::model::Data &data, const wsn::model::Node &receiver) {
    return true;
}

bool wsn::model::Sink::receiveData(const wsn::model::Data &data) {
    wsn::notification::NotificationCenter::getInstance().notify(wsn::notification::DataReceiveEvent(this, data));
    return true;
}
