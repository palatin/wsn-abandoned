#include <gtest/gtest.h>
#include <model/node/physics/first_order_radio_transmitter.h>
#include "../../../include/model/point.h"
#include "../../../include/model/node/node.h"
#include "../../../include/util/euclid_geometry.h"
#include "../../../include/protocol/network_protocol.h"


namespace wsn {

    namespace model {

        class NetworkProtocolTest : public wsn::protocol::network::NetworkProtocol {

        public:
            explicit NetworkProtocolTest() : NetworkProtocol(nullptr) {
            }

            bool testSend(const Data &data, Node &sender, Node &receiver) {
                return this->sendData(data, sender, receiver) && this->receiveData(data, receiver);
            }

            bool testAddLink(Node &node, const wsn::model::NodeLink &link) {
                return addLink(node, link);
            }



            void removeLinkTest(Node &node, unsigned long position) {
                removeLink(node, 1);
            }



            void update() override {

            }

        };

        class TransmitterStub : public wsn::model::Transmitter {

        public:
            bool sendData(const Data &data, Node &sender, const Node &receiver) const override {
                return true;
            };


            bool receiveData(const Data &data, Node &receiver) const override {
                return true;
            };

        };



        class NodeTest : public testing::Test {

        protected:
             void SetUp() override {
                this->node = new Node(1, Point(1, 3, 0), 1000, 1000, std::make_unique<TransmitterStub>());

                this->networkProtocolTest = new NetworkProtocolTest();
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

            Node *secondNode = new Node(1, Point(1, 3, 0), 1000, 1000, std::make_unique<TransmitterStub>());
            ASSERT_TRUE(*node == *secondNode);
            delete secondNode;
        }


        TEST_F(NodeTest, ReceiveDataWithEnoughMemory) {

            ASSERT_TRUE(networkProtocolTest->testSend(Data(node, node, 15), *node, *node));
            ASSERT_EQ(node->getData().size(), 1);
            ASSERT_EQ(node->getCurrentMemory(), 15);
        }

        TEST_F(NodeTest, ReceiveDataWithNotEnoughMemory) {
            ASSERT_FALSE(networkProtocolTest->testSend(Data(node, node, 2000), *node, *node));
            ASSERT_EQ(node->getData().size(), 0);
            ASSERT_EQ(node->getCurrentMemory(), 0);
        }

        TEST_F(NodeTest, ReceiveCommandWithEnoughMemory) {
            ASSERT_TRUE(networkProtocolTest->testSend(Command(node, node, 15), *node, *node));
            ASSERT_EQ(node->getCommands().size(), 1);
            ASSERT_EQ(node->getCurrentMemory(), 15);
        }

        TEST_F(NodeTest, ReceiveCommandWithNotEnoughMemory) {
            ASSERT_FALSE(networkProtocolTest->testSend(Command(node, node, 2000), *node, *node));
            ASSERT_EQ(node->getCommands().size(), 0);
            ASSERT_EQ(node->getCurrentMemory(), 0);
        }

        TEST_F(NodeTest, AddLink) {
            ASSERT_TRUE(networkProtocolTest->testAddLink(*node, NodeLink(node, 0)));
            ASSERT_EQ(node->getLinks().size(), 1);
        }

        TEST_F(NodeTest, AddLinkWithNotEnoughMemory) {
            ASSERT_TRUE(networkProtocolTest->testSend(Data(node, node, 1000), *node, *node));
            ASSERT_FALSE(networkProtocolTest->testAddLink(*node, NodeLink(node, 0)));
            ASSERT_EQ(node->getLinks().size(), 0);
        }

        TEST_F(NodeTest, RemoveLink) {
            ASSERT_TRUE(networkProtocolTest->testAddLink(*node, NodeLink(node, 0)));
            networkProtocolTest->removeLinkTest(*node, 0);
            ASSERT_EQ(node->getLinks().size(), 0);
        }

    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
