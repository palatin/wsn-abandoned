

#ifndef WSN_NETWORK_PROTOCOL_H
#define WSN_NETWORK_PROTOCOL_H


#include <vector>
#include <queue>
#include <memory>

#include "../model/data/data.h"
#include "../model/data/command.h"
#include "../controller/physics/physics_controller.h"
#include "../core/wsn_component.h"
#include "../model/nodes.h"

namespace wsn {

    namespace model {
        //forward declaration to wsn::model::Node
        class Node;
        class NodeLink;


    }

    namespace protocol {

        namespace network {



            using model::Data;
            using model::Node;
            using model::NodeLink;

            typedef std::vector<NodeLink> Links;
            typedef std::vector<wsn::model::Command> Commands;
            typedef std::deque<wsn::model::Data> DataList;

            template <typename NodeType>
            class NetworkProtocol : public wsn::core::WSNComponent {

                typedef std::shared_ptr<wsn::model::Nodes<NodeType>> NodesPtr;

            public:

                explicit NetworkProtocol(std::shared_ptr<wsn::controller::physics::PhysicsController<NodeType>> physicsController, NodesPtr nodesPtr)
                        : physicsControllerPtr(std::move(physicsController)), nodes(std::move(nodes)) {}
                virtual ~NetworkProtocol() = default;

                virtual void update() = 0;


            protected:
                NodesPtr nodes;

                bool sendData(const Data &data, NodeType &sender, NodeType &receiver) const {
                    return this->physicsControllerPtr.get()->sendData(data, sender, receiver);
                }

                bool receiveData(const Data &data, NodeType &receiver) const {
                    return this->physicsControllerPtr.get()->receiveData(data, receiver);
                }

                const Links& getLinks(const Node &node) const {
                    return node.getLinks();
                }

                bool addLink(Node &node, const wsn::model::NodeLink &link) {
                    return node.addLink(link);
                }

                void removeLink(Node &node, unsigned long position) {
                    return node.removeLink(position);
                }

                const Commands& getCommands(const Node &node) const {
                    return node.getCommands();
                }

                const DataList& getData(const Node &node) const {
                    return node.getData();
                }



            private:
                const std::shared_ptr<wsn::controller::physics::PhysicsController<NodeType>> physicsControllerPtr;
            };



        }
    }
}



#endif //WSN_NETWORK_PROTOCOL_H
