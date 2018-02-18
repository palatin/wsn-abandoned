

#ifndef WSN_PHYSICS_CONTROLLER_H
#define WSN_PHYSICS_CONTROLLER_H

#include <memory>
#include "../../model/node/node.h"
#include "../../model/data/data.h"
#include "../../util/geometry.h"

namespace wsn {

    namespace model {

        //forward declaration
        //class Node;
    }

    namespace controller {

        namespace physics {

            using model::Data;
            using wsn::model::Node;


            template <typename NodeType>
            class PhysicsController {

            public:
                explicit PhysicsController(wsn::util::GeometryPtr geometryPtr) : geometryPtr(std::move(geometryPtr)) {}
                virtual ~PhysicsController() = default;

                /// Method that calculate energy dissipation for sending data from sender to receiver
                /// and call @method receiveDataByNode
                /// @param data
                /// @param sender
                /// @param receiver
                /// @return
                virtual bool sendData(const Data &data, NodeType &sender, NodeType &receiver) const = 0;

                /// Method that calculate energy dissipation for receiving data
                /// @param data
                /// @param receiver
                /// @return
                virtual bool receiveData(const Data &data, NodeType &receiver) const = 0;

            protected:
                bool spendEnergy(Node &node, double energy) const {

                    bool enoughEnergy = node.getEnergy() >= energy;
                    node.setEnergy(enoughEnergy ? node.getEnergy() - energy : 0);
                    return enoughEnergy;
                }

                /// Method thar directly call bool wsn::model::Node::receiveData(const Data &data) in receiver
                /// without energy dissipation processing
                /// @param data - data that will received by @param receiver
                /// @param receiver - Node that will receive @param data
                /// @return the result of receive operation
                bool receiveDataByNode(const Data &data, Node &receiver) const {
                    return receiver.receiveData(data);
                }

                const wsn::util::GeometryPtr geometryPtr;

            };


        }
    }
}


#endif //WSN_PHYSICS_CONTROLLER_H
