#include <gtest/gtest.h>
#include "../../../../src/network/model/point.h"
#include "../../../../src/network/model/node/node.h"


namespace wsn {

    namespace model {

        class NetworkProtocolTest : public wsn::protocol::network::NetworkProtocol {

        public:
            bool testSend(const Data &data, const Node *receiver) {
                return this->sendData(data, receiver);

            }

            const std::vector<Command> getCommandsTest(const Node *node) {
                return this->getCommands(node);
            }

            const std::deque<Data> getDataTest(const Node *node) {
                return this->getData(node);
            }

            void step(long time) override {

            }

        };

        class NodeTest : public testing::Test {

        protected:
            void SetUp() {
                this->node = new Node(1, Point(1, 3), 1000, 1000);
                this->networkProtocolTest = new NetworkProtocolTest();
            }

            void TearDown() {
                delete node;
                delete networkProtocolTest;
            }

            Node *node;
            NetworkProtocolTest *networkProtocolTest;
        };

        TEST_F(NodeTest, GetNodeLocation) {
            auto point = node->getPoint();
            ASSERT_EQ(point.x, 1);
            ASSERT_EQ(point.y, 3);
        }

        TEST_F(NodeTest, NodeEqualityTest) {

            Node *secondNode = new Node(1, Point(1, 3), 1000, 1000);
            ASSERT_TRUE(*node == *secondNode);
            delete secondNode;
        }


        TEST_F(NodeTest, ReceiveDataWithEnoughMemory) {

            ASSERT_TRUE(networkProtocolTest->testSend(Data(node, node, 15), node));
            ASSERT_EQ(networkProtocolTest->getDataTest(node).size(), 1);
            ASSERT_EQ(node->getCurrentMemory(), 15);
        }

        TEST_F(NodeTest, ReceiveDataWithNotEnoughMemory) {
            ASSERT_FALSE(networkProtocolTest->testSend(Data(node, node, 2000), node));
            ASSERT_EQ(networkProtocolTest->getDataTest(node).size(), 0);
            ASSERT_EQ(node->getCurrentMemory(), 0);
        }

        TEST_F(NodeTest, ReceiveCommandWithEnoughMemory) {
            ASSERT_TRUE(networkProtocolTest->testSend(Command(node, node, 15), node));
            ASSERT_EQ(networkProtocolTest->getCommandsTest(node).capacity(), 1);
            ASSERT_EQ(node->getCurrentMemory(), 15);
        }

        TEST_F(NodeTest, ReceiveCommandWithNotEnoughMemory) {
            ASSERT_FALSE(networkProtocolTest->testSend(Command(node, node, 2000), node));
            ASSERT_EQ(networkProtocolTest->getCommandsTest(node).capacity(), 0);
            ASSERT_EQ(node->getCurrentMemory(), 0);
        }
    }
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
