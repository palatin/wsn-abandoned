#include <gtest/gtest.h>

#include "../../include/model/node/node.h"
#include "../../include/model/nodes.h"

namespace wsn {

    namespace model {

        class NodesTest : public testing::Test {


        protected:
            void SetUp() override {
                this->nodes = new Nodes();
            }

            void TearDown() override {
                delete nodes;
            }

            Nodes *nodes;

        };


        TEST_F(NodesTest, AddNodes) {
            nodes->addNode(std::make_unique<Node>(1, Point(1, 3, 0), 1000, 1000, nullptr));
            nodes->addNode(std::make_unique<Node>(2, Point(1, 3, 0), 1000, 1000, nullptr));
            ASSERT_EQ(1, nodes->at(0).getID());
            ASSERT_EQ(2, nodes->at(1).getID());
        }

        TEST_F(NodesTest, NodesCounts) {
            nodes->addNode(std::make_unique<Node>(1, Point(1, 3, 0), 1000, 1000, nullptr));
            nodes->addNode(std::make_unique<Node>(2, Point(1, 3, 0), 1000, 1000, nullptr));
            ASSERT_EQ(nodes->nodeCounts(), 2);
        }
    }
}

