#include "model/data/data.h"


wsn::model::Data::Data(const wsn::model::Node *sender, const wsn::model::Node *receiver, unsigned long dataLength) :sender(sender), receiver(receiver), length(dataLength) {
}

double wsn::model::Data::getDataLength() const {
    return length;
}

const wsn::model::Node *wsn::model::Data::getReceiver() const {
    return this->receiver;
}

const wsn::model::Node *wsn::model::Data::getSender() const {
    return this->sender;
}










