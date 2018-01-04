

#ifndef WSN_NODES_H
#define WSN_NODES_H


#include <vector>
#include "node.h"

namespace wsn {

    namespace model {

        struct Nodes {



            unsigned long nodeCounts();

            Node* getNodeById(unsigned int id);



            std::vector<Node*> &nodes;

        };

    }
}

#endif //WSN_NODES_H
