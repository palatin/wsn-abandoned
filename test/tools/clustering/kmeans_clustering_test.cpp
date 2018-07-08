

#include <gtest/gtest.h>
#include <factory/random_location_nodes_factory.h>
#include <tools/clustering/kmeans_clustering.h>
#include <util/euclid_geometry.h>
#include <tools/clustering/ga/dbi_fitness.h>

namespace wsn {

    namespace tools {


        namespace clustering {


            TEST(KMeansClusteringTest, ClusterCount) {

                wsn::factory::RandomNodesFactory<wsn::model::Node> nodesFactory(10000, wsn::factory::RandomNodeArea(wsn::model::Point(0,0,0), wsn::model::Point(100,100,0)));

                auto nodes = nodesFactory.buildNodes();


                unsigned int chs = 15;

                auto *kMeansClustering = new wsn::tools::clustering::KMeansClustering(std::make_shared<wsn::util::EuclidGeometry>(), chs, 20061996);
                auto clusters = kMeansClustering->buildClusters(nodes->getList());

                ASSERT_EQ(clusters.size(), chs);

                delete(kMeansClustering);
            }

            TEST(KMeansClusteringTest, UniqueClusters) {

                wsn::factory::RandomNodesFactory<wsn::model::Node> nodesFactory(1000, wsn::factory::RandomNodeArea(wsn::model::Point(0,0,0), wsn::model::Point(100,100,0)));

                auto nodes = nodesFactory.buildNodes();


                unsigned int chs = 15;

                auto *kMeansClustering = new wsn::tools::clustering::KMeansClustering(std::make_shared<wsn::util::EuclidGeometry>(), chs, 20061996);
                auto clusters = kMeansClustering->buildClusters(nodes->getList());

                bool unique = true;

                std::set<unsigned long> nodes_indexes;

                for(unsigned int i = 0; i < clusters.size(); i++ ) {
                    auto &cluster = clusters.clusterAt(i);

                    for(auto &node : cluster) {
                        if(!nodes_indexes.insert(node.second).second)
                            unique = false;
                    }
                }

                ASSERT_TRUE(unique);

                delete(kMeansClustering);
            }

        }

    }

}

