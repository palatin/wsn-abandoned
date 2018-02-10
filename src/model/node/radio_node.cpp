
#include "model/node/radio_node.h"


namespace wsn {

    namespace model {

        RadioNode::RadioNode(unsigned long id, const wsn::model::Point &location, double energyJ,
                                         float memoryLimit, double Eelec, double Eamp,
                                         double Efs)
                : Node(id, location, energyJ, memoryLimit), Eelec(Eelec), Eamp(Eamp), Efc(Efs) {}


        double RadioNode::getEelec() const {
            return Eelec;
        }

        double RadioNode::getEamp() const {
            return Eamp;
        }

        double RadioNode::getEfs() const {
            return Efc;
        }
    }

}