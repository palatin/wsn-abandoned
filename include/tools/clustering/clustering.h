

#ifndef WSN_CLUSTERING_H
#define WSN_CLUSTERING_H


#include "../../model/nodes.h"
#include "../../util/array_helper.h"
#include "../../model/node/node.h"

namespace wsn {

    namespace tools {

        namespace clustering {



            class Clusters {

            public:
                explicit Clusters() {
                }

                Clusters(unsigned int count) {
                    clusters.resize(count);
                }

                const std::multimap<double, unsigned long>& clusterAt(unsigned int index) const {
                    return clusters.at(index);
                }




                unsigned int size() const  { return clusters.size(); }

                void clearClusters() {
                    for (auto &cluster : clusters) {
                        cluster.clear();
                    }
                }

                void clearClusterAt(unsigned int index) {
                    clusters.at(index).clear();
                }

                void addNodeToCluster(unsigned int cluster, unsigned long node, double distance) {
                    if(cluster + 1 > clusters.size())
                        clusters.resize(cluster + 1);
                    clusters.at(cluster).insert(std::pair<double, unsigned long>(distance, node));
                }



            private:
                std::vector<std::multimap<double , unsigned long>> clusters;

            };

            class Clustering {

            public:
                explicit Clustering(wsn::util::GeometryPtr geometryPtr) : geometryPtr(std::move(geometryPtr)) {}
                virtual Clusters buildClusters(const wsn::model::NodeList &nodes) = 0;
                std::pair<unsigned long, double> findNearestPoint(const wsn::model::Point &point, std::vector<wsn::model::Point> &points) const {
                    
                    wsn::util::ArrayHelper arrayHelper;

                    std::vector<double> distances(points.size());

                    for (unsigned int i = 0; i < points.size(); ++i) {
                        distances.at(i) = geometryPtr->distanceBetweenPoints(points.at(i), point);
                    }

                    auto value = arrayHelper.getSmallestElement(&distances[0], points.size());
                    return std::pair(value.first, *value.second);
                }

                void assignNodesToClusters(std::vector<wsn::model::Point> &centers,
                                           wsn::tools::clustering::Clusters &clusters,
                                           const wsn::model::NodeList &nodes) const {


                    for (unsigned long i = 0; i < nodes.size(); ++i) {
                        auto nearest = findNearestPoint(nodes.at(i)->getLocation(), centers);
                        //put node's index to nearest cluster with distance
                        clusters.addNodeToCluster(nearest.first, i, nearest.second);
                    }

                }

            protected:
                wsn::util::GeometryPtr geometryPtr;

            };

        }
    }
}



#endif //WSN_CLUSTERING_H
