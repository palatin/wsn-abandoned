

#ifndef WSN_NODES_H
#define WSN_NODES_H


#include <vector>
#include <memory>
#include "node/node.h"



namespace wsn {

    namespace model {


        template <typename NodeType>
        struct Nodes {

        public:

            Nodes() = default;

             explicit Nodes(std::vector<std::unique_ptr<NodeType>> &node) : nodes(std::move(nodes)) {}

            ~Nodes() {

            }


            void addNode(std::unique_ptr<NodeType> node) {
                nodes.push_back(std::move(node));
            }

            unsigned long nodeCounts() {
                return nodes.size();
            }

            NodeType& getNodeById(unsigned long id) {
                return *nodes.at(id);
            }

            NodeType &at(unsigned long number) {
                return *nodes.at(number);
            }

            const NodeType &at(unsigned long number) const {
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
            std::vector<std::unique_ptr<NodeType>> nodes;


        };

        typedef std::vector<wsn::model::Node*> NodeList;

    }
}

#endif //WSN_NODES_H
