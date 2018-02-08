#include <gtest/gtest.h>
#include "../../../../src/network/model/point.h"
#include "../../../../src/network/model/node/node.h"
#include "../../../../src/network/util/euclid_geometry.h"
#include "../../../../src/network/protocol/network_protocol.h"


namespace wsn {

    namespace model {

        class NetworkProtocolTest : public wsn::protocol::network::NetworkProtocol<Node> {

        public:
            explicit NetworkProtocolTest(const std::shared_ptr<controller::physics::PhysicsController<Node>> physicsController)
                    : NetworkProtocol(physicsController, nullptr) {
            }

            bool testSend(const Data &data, Node &sender, Node &receiver) {
                return this->sendData(data, sender, receiver) && this->receiveData(data, receiver);
            }

            bool testAddLink(Node &node, const wsn::model::NodeLink &link) {
                return addLink(node, link);
            }

            const Links& getLinksTest(const Node &node) {
                return getLinks(node);
            }

            void removeLinkTest(Node &node, unsigned long position) {
                removeLink(node, 1);
            }

            const std::vector<Command> getCommandsTest(const Node &node) {
                return this->getCommands(node);
            }

            const std::deque<Data> getDataTest(const Node &node) {
                return this->getData(node);
            }

            void update() override {

            }

        };

        class PhysicsControllerStub : public wsn::controller::physics::PhysicsController<Node> {

        public:
            explicit PhysicsControllerStub(const std::shared_ptr<util::Geometry> &geometryPtr) : PhysicsController(geometryPtr) {}

            bool sendData(const Data &data, Node &sender, Node &receiver) const override {
                return true;
            }

            bool receiveData(const Data &data, Node &receiver) const override {
                return receiveDataByNode(data, receiver);
            }
        };

        class NodeTest : public testing::Test {

        protected:
             void SetUp() override {
                this->node = new Node(1, Point(1, 3, 0), 1000, 1000);

                auto physicsControllerStub = std::make_shared<PhysicsControllerStub>(std::make_shared<util::EuclidGeometry>());
                this->networkProtocolTest = new NetworkProtocolTest(physicsControllerStub);
            }

            void TearDown() override {
                delete node;
                delete networkProtocolTest;
            }

            Node *node;
            NetworkProtocolTest *networkProtocolTest;
        };

        TEST_F(NodeTest, GetNodeLocation) {
            auto point = node->getLocation();
            ASSERT_EQ(point.x, 1);
            ASSERT_EQ(point.y, 3);
        }

        TEST_F(NodeTest, NodeEqualityTest) {

            Node *secondNode = new Node(1, Point(1, 3, 0), 1000, 1000);
            ASSERT_TRUE(*node == *secondNode);
            delete secondNode;
        }


        TEST_F(NodeTest, ReceiveDataWithEnoughMemory) {

            ASSERT_TRUE(networkProtocolTest->testSend(Data(node, node, 15), *node, *node));
            ASSERT_EQ(networkProtocolTest->getDataTest(*node).size(), 1);
            ASSERT_EQ(node->getCurrentMemory(), 15);
        }

        TEST_F(NodeTest, ReceiveDataWithNotEnoughMemory) {
            ASSERT_FALSE(networkProtocolTest->testSend(Data(node, node, 2000), *node, *node));
            ASSERT_EQ(networkProtocolTest->getDataTest(*node).size(), 0);
            ASSERT_EQ(node->getCurrentMemory(), 0);
        }

        TEST_F(NodeTest, ReceiveCommandWithEnoughMemory) {
            ASSERT_TRUE(networkProtocolTest->testSend(Command(node, node, 15), *node, *node));
            ASSERT_EQ(networkProtocolTest->getCommandsTest(*node).capacity(), 1);
            ASSERT_EQ(node->getCurrentMemory(), 15);
        }

        TEST_F(NodeTest, ReceiveCommandWithNotEnoughMemory) {
            ASSERT_FALSE(networkProtocolTest->testSend(Command(node, node, 2000), *node, *node));
            ASSERT_EQ(networkProtocolTest->getCommandsTest(*node).capacity(), 0);
            ASSERT_EQ(node->getCurrentMemory(), 0);
        }

        TEST_F(NodeTest, AddLink) {
            ASSERT_TRUE(networkProtocolTest->testAddLink(*node, NodeLink(node, 0)));
            ASSERT_EQ(networkProtocolTest->getLinksTest(*node).size(), 1);
        }

        TEST_F(NodeTest, AddLinkWithNotEnoughMemory) {
            ASSERT_TRUE(networkProtocolTest->testSend(Data(node, node, 1000), *node, *node));
            ASSERT_FALSE(networkProtocolTest->testAddLink(*node, NodeLink(node, 0)));
            ASSERT_EQ(networkProtocolTest->getLinksTest(*node).size(), 0);
        }

        TEST_F(NodeTest, RemoveLink) {
            ASSERT_TRUE(networkProtocolTest->testAddLink(*node, NodeLink(node, 0)));
            networkProtocolTest->removeLinkTest(*node, 0);
            ASSERT_EQ(networkProtocolTest->getLinksTest(*node).size(), 0);
        }

    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
