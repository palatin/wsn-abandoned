

#ifndef WSN_WSN_CLUSTER_TREE_LINKER_CONTROLLER_H
#define WSN_WSN_CLUSTER_TREE_LINKER_CONTROLLER_H


#include <memory>
#include "../wsn_linker_controller.h"
#include "clustering_controller.h"


namespace linker = wsn::controller::linker;
namespace util = wsn::util;

namespace wsn {

    namespace controller {

        namespace linker {

            class WSNClusterTreeLinkerController : WSNLinkerController {



            public:
                WSNClusterTreeLinkerController(linker::ClusteringController *clusteringController,  std::shared_ptr<util::Geometry>  geometry);
                void linkNodes(wsn::model::Nodes &nodes);

            private:
                linker::ClusteringController *clusteringController;
                std::shared_ptr<util::Geometry>  geometry;

            };

        }
    }
}


#endif //WSN_WSN_CLUSTER_TREE_LINKER_CONTROLLER_H
