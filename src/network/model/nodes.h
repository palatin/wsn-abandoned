

#ifndef WSN_NODES_H
#define WSN_NODES_H


#include <vector>
#include "node.h"

namespace wsn {

    namespace model {

        struct Nodes {

            Nodes(std::vector<Node*> &nodes);

            unsigned long nodeCounts();

            Node& getNodeById(unsigned long id);

            Nodes getNodesByType(NodeType type);

            std::vector<Node> &getNodes();

        private:
            std::vector<Node> &nodes;

        };

    }
}

#endif //WSN_NODES_H
