#include <gtest/gtest.h>


#include <model/node/node.h>
#include <factory/nodes_factory.h>
#include <factory/random_location_nodes_factory.h>
#include <model/node/radio_node.h>


namespace wsn {

    namespace factory {



        TEST(RandomLocationNodesFactoryTest, NodeCounts) {
            RandomNodeArea area(wsn::model::Point(0,0,0), wsn::model::Point(10,10,0));
            RandomNodesFactory<wsn::model::RadioNode> factory(area);
            auto nodes = factory.buildNodes(30);
            ASSERT_EQ(30, nodes->nodeCounts());

        }

        TEST(RandomLocationNodesFactoryTest, UniqueNodesLocations) {
            RandomNodeArea area(wsn::model::Point(0,0,0), wsn::model::Point(10,10,0));
            RandomNodesFactory<wsn::model::RadioNode> factory(area);
            auto nodes = factory.buildNodes(1000);
            std::set<wsn::model::Point> points;
            bool unique = true;
            for (unsigned int i = 0; i < nodes->nodeCounts(); ++i) {
                if(!points.insert(nodes->at(i).getLocation()).second)
                    unique = false;
            }

            ASSERT_TRUE(unique);


        }
    }
}

