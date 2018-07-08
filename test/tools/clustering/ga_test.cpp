

#include <gtest/gtest.h>
#include <factory/random_location_nodes_factory.h>
#include <tools/clustering/kmeans_clustering.h>
#include <tools/clustering/ga/ga.h>
#include <util/euclid_geometry.h>
#include <tools/clustering/ga/roulette_wheel_selection.h>
#include <tools/clustering/ga/dbi_fitness.h>
#include <tools/clustering/ga/one_point_crossover.h>
#include <tools/clustering/ga/binary_mutation.h>
#include <tools/clustering/ga/two_point_crossover.h>
#include <tools/clustering/ga/tournament_selection.h>

namespace wsn {

    namespace tools {


        namespace clustering {

            namespace ga {


                TEST(GATest, ClusterCount) {

                    wsn::factory::RandomNodesFactory<wsn::model::Node> nodesFactory(10000, wsn::factory::RandomNodeArea(
                            wsn::model::Point(0, 0, 0), wsn::model::Point(100, 100, 0)));

                    auto nodes = nodesFactory.buildNodes();


                    unsigned int chs = 15;
                    auto geometry = std::make_shared<wsn::util::EuclidGeometry>();
                    auto kMeansClustering = std::make_shared<KMeansClustering>(geometry, chs, 20061996);

                    GAConfiguration config(std::make_unique<RouletteWheelSelection>(),
                                           std::make_unique<TwoPointCrossover>(),
                                           std::make_unique<BinaryMutation>(),
                                           std::make_unique<DBIFitness>(nodes->getList(), geometry));

                    /*GAConfiguration config(std::make_unique<TournamentSelection>(2),
                                           std::make_unique<TwoPointCrossover>(),
                                           std::make_unique<BinaryMutation>(),
                                           std::make_unique<DBIFitness>(nodes->getList(), geometry));*/

                    auto *ga = new GAClustering(config, std::make_shared<wsn::util::EuclidGeometry>(), 5);
                    auto clusters = ga->buildClusters(nodes->getList());

                    ASSERT_EQ(clusters.size(), chs);


                }


            }

        }
    }

}

