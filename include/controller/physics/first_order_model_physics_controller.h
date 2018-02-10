
#ifndef WSN_FIRST_ORDER_MODEL_PHYSICS_CONTROLLER_H
#define WSN_FIRST_ORDER_MODEL_PHYSICS_CONTROLLER_H


#include "physics_controller.h"
#include <cmath>
#include "../../util/euclid_geometry.h"
#include "../../model/node/radio_node.h"


namespace wsn {


    namespace controller {

        namespace physics {

            using model::Data;
            using model::RadioNode;

            class FirstOrderModelPhysicsController : public PhysicsController<RadioNode> {

            public:
                explicit FirstOrderModelPhysicsController(std::shared_ptr<util::Geometry> geometryPtr = std::make_shared<wsn::util::EuclidGeometry>()) : PhysicsController(std::move(geometryPtr)) {}

            public:

                bool sendData(const Data &data, RadioNode &sender, RadioNode &receiver) const override {

                    double d0 = sqrt(sender.getEfs() / sender.getEamp());
                    double d = geometryPtr.get()->distanceBetweenPoints(sender.getLocation(), receiver.getLocation());
                    double L = data.getDataLength();
                    double Etx = sender.getEelec() + L * sender.getEfs() * pow(d, d < d0 ? 2 : 4);
                    return spendEnergy(sender, Etx);
                }


                bool receiveData(const Data &data, RadioNode &receiver) const override {
                    return spendEnergy(receiver, data.getDataLength() * receiver.getEelec()) && receiveDataByNode(data, receiver);
                }


            };

        }
    }
}




#endif //WSN_FIRST_ORDER_MODEL_PHYSICS_CONTROLLER_H
