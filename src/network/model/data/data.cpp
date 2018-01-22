#include <cstring>
#include "data.h"



/*wsn::model::Data::Data(wsn::model::Node *sender, wsn::model::Node *receiver, const unsigned char *const data, size_t dataLength) :sender(sender), receiver(receiver) {
    this->length = dataLength;
    this->data = new unsigned char[length];
    memcpy(this->data, data, sizeof(unsigned char) * dataLength);
}

wsn::model::Data::Data(const wsn::model::Data &data) :sender(data.sender), receiver(data.receiver) {
    this->length = data.length;
    this->data = new unsigned char[data.length];
    memcpy(this->data, data.data, sizeof(unsigned char) * data.length);
}

wsn::model::Data::~Data()  {
    delete[] this->data;
}*/

wsn::model::Data::Data(const wsn::model::Node *sender, const wsn::model::Node *receiver, double dataLength) :sender(sender), receiver(receiver), length(dataLength) {
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










