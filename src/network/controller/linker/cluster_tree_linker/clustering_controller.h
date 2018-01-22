

#ifndef WSN_CLUSTERING_CONTROLLER_H
#define WSN_CLUSTERING_CONTROLLER_H

#include "../../../model/nodes.h"

namespace wsn {

    namespace controller {

        namespace linker {

            struct WSNCluster {
                const wsn::model::Node *ch;
                const wsn::model::Nodes nodes;
            };

            class ClusteringController {

            public:
                virtual std::vector<WSNCluster> clusterize(const wsn::model::Nodes &nodes) = 0;

            };
        }
    }
}


#endif //WSN_CLUSTERING_CONTROLLER_H
