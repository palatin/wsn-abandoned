

#ifndef WSN_KMEANS_CLUSTERING_H
#define WSN_KMEANS_CLUSTERING_H


#include <util/geometry.h>
#include <memory>
#include "clustering.h"

namespace wsn {

    namespace tools {

        namespace clustering {

            class KMeansClustering : public Clustering {

            public:
                KMeansClustering(wsn::util::GeometryPtr geometry, unsigned int clusters);
                KMeansClustering(wsn::util::GeometryPtr geometry, unsigned int clusters, long seed);

                NodesClusters buildClusters(const wsn::model::NodeList &nodes) override;


            private:
                wsn::util::GeometryPtr geometry;
                unsigned int clusterCount;
                long seed;

                struct Cluster {

                    wsn::model::Point centroid;
                    std::vector<wsn::model::Node*> nodes;

                    wsn::model::Point calculateCenterOfMass() {

                        wsn::model::Point point(0,0,0);
                        for(auto &node : nodes) {
                            //avoid possible duplicates of centroid-node
                            //if(centroid != node->getLocation())
                            point += node->getLocation();
                        }

                        assert(nodes.size() > 0);
                        point /= nodes.size();

                        return point;
                    }

                    bool operator==(const Cluster &value) {
                        return centroid == value.centroid;
                    }

                };


                std::vector<Cluster> initClusters(const wsn::model::NodeList &nodes, unsigned int clusterCounts);
                void assignNodesToClusters(std::vector<Cluster> &clusters, const wsn::model::NodeList &nodes);
                unsigned int findNearestCentroid(std::vector<wsn::model::Point> &clusters, const wsn::model::Point &point);
                bool calculateNewCenters(std::vector<Cluster> &clusters);
                void clearCluster(std::vector<Cluster> &clusters);
            };

        }
    }
}

#endif //WSN_KMEANS_CLUSTERING_H
