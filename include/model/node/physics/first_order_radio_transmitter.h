//
// Created by palatin on 2/18/18.
//

#ifndef WSN_FIRST_ORDER_RADIO_TRANSMITTER_H
#define WSN_FIRST_ORDER_RADIO_TRANSMITTER_H

#include "transmitter.h"

namespace wsn {

    namespace model {


        class FirstOrderRadioTransmitter : public Transmitter {

        public:

            FirstOrderRadioTransmitter(wsn::util::GeometryPtr geometryPtr, double Eelec = 0.00000005, double Eamp = 0.00000000000000013,
                                       double Efs = 0.00000000001);

            bool sendData(const Data &data, Node &sender, const Node &receiver) const override;


            bool receiveData(const Data &data, Node &receiver) const override;


        private:
            const double Eelec;
            const double Eamp;
            const double Efc;
            wsn::util::GeometryPtr geometryPtr;


        };
    }
}

#endif //WSN_FIRST_ORDER_RADIO_TRANSMITTER_H
