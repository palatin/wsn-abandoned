

#include <gtest/gtest.h>
#include <factory/random_location_nodes_factory.h>
#include <tools/clustering/kmeans_clustering.h>
#include <util/euclid_geometry.h>

namespace wsn {

    namespace tools {


        namespace clustering {


            TEST(KMeansClusteringTest, ClusterCount) {

                wsn::factory::RandomNodesFactory<wsn::model::Node> nodesFactory(wsn::factory::RandomNodeArea(wsn::model::Point(0,0,0), wsn::model::Point(100,100,0)));

                auto nodes = nodesFactory.buildNodes(1000);


                unsigned int chs = 15;

                auto *kMeansClustering = new wsn::tools::clustering::KMeansClustering(std::make_shared<wsn::util::EuclidGeometry>(), chs, 20061996);
                auto clusters = kMeansClustering->buildClusters(nodes->getList());

                ASSERT_EQ(clusters.size(), chs);

                delete(kMeansClustering);
            }

            TEST(KMeansClusteringTest, UniqueCHs) {

                wsn::factory::RandomNodesFactory<wsn::model::Node> nodesFactory(wsn::factory::RandomNodeArea(wsn::model::Point(0,0,0), wsn::model::Point(100,100,0)));

                auto nodes = nodesFactory.buildNodes(1000);


                unsigned int chs = 15;

                auto *kMeansClustering = new wsn::tools::clustering::KMeansClustering(std::make_shared<wsn::util::EuclidGeometry>(), chs, 20061996);
                auto clusters = kMeansClustering->buildClusters(nodes->getList());

                bool unique = true;

                for (unsigned int i = 0; i < chs - 1; ++i) {
                    if(clusters.at(i).CH == clusters.at(i+1).CH)
                        unique = false;
                    for(auto node1 : clusters.at(i).nodes) {
                        for(auto node2 : clusters.at(i+1).nodes) {
                            if(node1 == node2)
                                unique = false;
                        }
                    }
                }

                ASSERT_TRUE(unique);

                delete(kMeansClustering);
            }

        }

    }

}

