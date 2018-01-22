#include <iostream>
#include "network_protocol.h"
#include "../model/node/node.h"





wsn::protocol::network::NetworkProtocol::NetworkProtocol() {

}

bool wsn::protocol::network::NetworkProtocol::sendData(const Data &data,  const Node *receiver) const {
    return receiver->receiveData(data);
}

const std::vector<wsn::model::Command> &
wsn::protocol::network::NetworkProtocol::getCommands(const wsn::model::Node *node) {
    return node->getCommands();
}

const std::deque<wsn::model::Data> &wsn::protocol::network::NetworkProtocol::getData(const wsn::model::Node *node) {
    return node->getData();
}


