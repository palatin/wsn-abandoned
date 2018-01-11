

#ifndef WSN_NODES_H
#define WSN_NODES_H


#include <vector>
#include "node/node.h"


//struct that stored vector of node pointers
//this container is not responsible for release nodes memory
namespace wsn {

    namespace model {

        struct Nodes {

        public:
            Nodes(std::vector<Node*> &nodes);
            ~Nodes();

            unsigned long nodeCounts();

            Node& getNodeById(unsigned long id);

            //todo reference vs object
            Nodes getNodesByType(NodeType type);

            std::vector<Node*> &getNodes();

        private:
            std::vector<Node*> &nodes;

        };

    }
}

#endif //WSN_NODES_H
