

#ifndef WSN_NODES_H
#define WSN_NODES_H


#include <vector>
#include <memory>
#include "node/node.h"



namespace wsn {

    namespace model {

        struct Nodes {

        public:
            Nodes() = default;

            explicit Nodes(std::vector<std::unique_ptr<Node>> &nodes);
            ~Nodes();


            void addNode(std::unique_ptr<Node> node);
            unsigned long nodeCounts();

            Node& getNodeById(unsigned long id);

            Node &at(unsigned long number);

            const Node &at(unsigned long number) const;

        private:
            std::vector<std::unique_ptr<Node>> nodes;


        };

    }
}

#endif //WSN_NODES_H
