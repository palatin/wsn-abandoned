

#ifndef WSN_NODES_H
#define WSN_NODES_H


#include <vector>
#include <memory>
#include "node/node.h"
#include "node/physics/transmitter.h"




namespace wsn {

    namespace model {


        class Nodes {

        public:

            Nodes() = default;

             explicit Nodes(std::vector<std::unique_ptr<Node>> &node) : nodes(std::move(nodes)) {}

            ~Nodes() {

            }


            void addNode(std::unique_ptr<Node> node) {
                nodes.push_back(std::move(node));
            }

            unsigned long nodeCounts() {
                return nodes.size();
            }

            Node& getNodeById(unsigned long id) {
                return *nodes.at(id);
            }

            Node &at(unsigned long number) {
                return *nodes.at(number);
            }

            const Node &at(unsigned long number) const {
                return *nodes.at(number);
            }

            std::vector<Node*> getList() {
                std::vector<Node*> nodes(nodeCounts());
                for (unsigned int i = 0; i < nodeCounts(); ++i) {
                    nodes[i] = this->nodes.at(i).get();
                }

                return nodes;
            }

        private:
            std::vector<std::unique_ptr<Node>> nodes;


        };

        typedef std::vector<wsn::model::Node*> NodeList;
        typedef std::shared_ptr<wsn::model::Nodes> NodesPtr;

    }
}

#endif //WSN_NODES_H
