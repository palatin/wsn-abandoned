

#ifndef WSN_NETWORK_PROTOCOL_H
#define WSN_NETWORK_PROTOCOL_H


#include <vector>
#include <queue>
#include <memory>

#include "../model/data/data.h"
#include "../model/data/command.h"
#include "../controller/physics/physics_controller.h"

namespace wsn {

    namespace model {
        //forward declaration to wsn::model::Node
        class Node;


    }

    namespace protocol {

        namespace network {

            using model::Data;
            using model::Node;

            template <typename NodeType>
            class NetworkProtocol {

            public:

                explicit NetworkProtocol(std::shared_ptr<wsn::controller::physics::PhysicsController<NodeType>> physicsController) : physicsControllerPtr(std::move(physicsController)) {}
                virtual ~NetworkProtocol() = default;

                virtual void step(long time) = 0;


            protected:
                bool sendData(const Data &data, NodeType &sender, NodeType &receiver) const {
                    return this->physicsControllerPtr.get()->sendData(data, sender, receiver);
                }

                bool receiveData(const Data &data, NodeType &sender, NodeType &receiver) const {
                    return this->physicsControllerPtr.get()->receiveData(data, receiver);
                }

                const std::vector<wsn::model::Command>& getCommands(const Node *node) const {
                    return node->getCommands();
                }

                const std::deque<wsn::model::Data>& getData(const Node *node) const {
                    return node->getData();
                }


            private:
                const std::shared_ptr<wsn::controller::physics::PhysicsController<NodeType>> physicsControllerPtr;
            };


        }
    }
}



#endif //WSN_NETWORK_PROTOCOL_H
