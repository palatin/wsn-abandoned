//
// Created by palatin on 2/18/18.
//

#include <cmath>
#include "model/node/physics/first_order_radio_transmitter.h"
#include <model/node/node.h>

using wsn::model::FirstOrderRadioTransmitter;
using wsn::model::Node;
using wsn::model::Data;

FirstOrderRadioTransmitter::FirstOrderRadioTransmitter(wsn::util::GeometryPtr geometryPtr, double Eelec, double Eamp, double Efs)
        : Eelec(Eelec), Eamp(Eamp), Efc(Efs), geometryPtr(geometryPtr) {

}

bool FirstOrderRadioTransmitter::sendData(const Data &data,  Node &sender, const Node &receiver) const {
    double d0 = sqrt(Efc / Eamp);
    double d = geometryPtr.get()->distanceBetweenPoints(sender.getLocation(), receiver.getLocation());
    double L = data.getDataLength();
    double Etx = Eelec + L * Efc * pow(d, d < d0 ? 2 : 4);
    return spendEnergy(sender, Etx);
}

bool FirstOrderRadioTransmitter::receiveData(const Data &data, Node &receiver) const {
    return false;
}
