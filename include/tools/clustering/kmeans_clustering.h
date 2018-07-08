

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

                Clusters buildClusters(const wsn::model::NodeList &nodes) override;


            private:
                unsigned int clusterCount;
                long seed;



                std::vector<wsn::model::Point> initClusters(const wsn::model::NodeList &nodes, unsigned int clusterCounts);
                bool calculateNewCenters(Clusters &clusters, std::vector<wsn::model::Point> &centres, const wsn::model::NodeList &nodes);

            };

        }
    }
}

#endif //WSN_KMEANS_CLUSTERING_H
