

#ifndef WSN_CLUSTERING_H
#define WSN_CLUSTERING_H


#include <model/nodes.h>
#include "../../model/node/node.h"

namespace wsn {

    namespace tools {

        namespace clustering {

            struct NodesCluster {

                wsn::model::Node *CH;
                std::vector<wsn::model::Node *> nodes;

                NodesCluster() = default;

                NodesCluster(NodesCluster &&cluster) noexcept {
                    this->CH = cluster.CH;
                    this->nodes = std::move(cluster.nodes);
                    cluster.CH = nullptr;
                }

            };

            class Clustering {

            public:
                Clustering() = default;
                virtual std::vector<NodesCluster> buildClusters(const wsn::model::NodeList &nodes) = 0;

            };

            typedef std::vector<wsn::tools::clustering::NodesCluster> NodesClusters;

        }
    }
}



#endif //WSN_CLUSTERING_H
