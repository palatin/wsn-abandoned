
#include <gtest/gtest.h>
#include "../../include/controller/physics/physics_controller.h"
#include "../../include/util/euclid_geometry.h"
#include "../../include/model/node/node.h"


namespace wsn {

    namespace controller {

        namespace physics {

            using wsn::model::Node;
            using wsn::model::Point;

            class PhysicsControllerStub : public PhysicsController<Node> {

            public:
                PhysicsControllerStub(std::shared_ptr<util::Geometry> geometryPtr) : PhysicsController(std::move(geometryPtr)) {}

                bool sendData(const Data &data, Node &sender, Node &receiver) const override {
                    return true;
                }


                bool receiveData(const Data &data, Node &receiver) const override {
                    return true;
                }

                bool testSpendEnergy(Node &node, float energy) {
                    return spendEnergy(node, energy);
                }


            };

            class PhysicsControllerTest : public testing::Test {

            protected:
                void SetUp() override {
                    this->physicsController =  new PhysicsControllerStub(std::make_shared<wsn::util::EuclidGeometry>());
                    this->node = new Node(1, Point(0, 0, 0), 1000, 1000);

                }

                void TearDown() override {

                    delete physicsController;
                    delete node;
                }

                PhysicsControllerStub *physicsController;
                Node *node;

            };

            TEST_F(PhysicsControllerTest, SpendEnergy) {
                ASSERT_TRUE(physicsController->testSpendEnergy(*node, 1000));
                ASSERT_EQ(node->getEnergy(), 0);
            }

            TEST_F(PhysicsControllerTest, SpendEnergyMoreThenNodeHas) {
                ASSERT_FALSE(physicsController->testSpendEnergy(*node, 1001));
                ASSERT_EQ(node->getEnergy(), 0);
            }

        }
    }
}