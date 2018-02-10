

#ifndef WSN_RADIO_NODE_H
#define WSN_RADIO_NODE_H

#include "node.h"

namespace wsn {

    namespace model {


        class RadioNode : public Node {
        public:
            RadioNode(unsigned long id, const Point &location, double energyJ,
                      float memoryLimit, double Eelec = 0.00000005, double Eamp = 0.00000000000000013,
                      double Efs = 0.00000000001);

        public:
            //return E(elec) in nJ/bit
            double getEelec() const;
            //return E(amp) in pJ/(bit*m^4)
            double getEamp() const;
            //return E(amp) in pJ/(bit*m^2)
            double getEfs() const;

        private:
            const double Eelec;
            const double Eamp;
            const double Efc;

        };

    }
}

#endif //WSN_RADIO_NODE_H
