

#include <cmath>
#include <controller/physics/physics_controller.h>
#include "util/geometry.h"
#include "controller/physics/physics_controller.h"

#include "model/node/node.h"


//using wsn::controller::physics::PhysicsController;


namespace wsn {

    namespace controller {

        namespace physics {


            PhysicsController::PhysicsController(const wsn::util::GeometryPtr &geometryPtr) : geometryPtr(geometryPtr) {
            }


            bool PhysicsController::receiveDataByNode(const Data &data, Node &receiver) const {
                return receiver.receiveData(data);
            }

            bool PhysicsController::spendEnergy(wsn::model::Node &node, double energy) const {

                bool enoughEnergy = node.getEnergy() > energy;
                node.setEnergy(node.getEnergy() - energy);
                return enoughEnergy;
            }


            //TODO change all to virtual and create another child to test https://www.ncbi.nlm.nih.gov/pmc/articles/PMC3230965/
            bool PhysicsController::sendData(const wsn::model::Data &data, wsn::model::Node &sender,
                                             wsn::model::Node &receiver) const {

                double d0 = sqrt(sender.getEfs() / sender.getEamp());
                double d = geometryPtr.get()->distanceBetweenPoints(sender.getLocation(), receiver.getLocation());
                double L = data.getDataLength();
                double Etx = sender.getEelec() + L * sender.getEfs() * pow(d, d < d0 ? 2 : 4);
                return spendEnergy(sender, Etx);
            }

            bool PhysicsController::receiveData(const wsn::model::Data &data,
                                                wsn::model::Node &receiver) const {
                return spendEnergy(receiver, data.getDataLength() * receiver.getEelec()) && receiveDataByNode(data, receiver);
            }


        }

    }
}


