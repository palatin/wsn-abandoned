

#include "wsn_cluster_tree_linker_controller.h"
#include "../util/array_helper.h"

void wsn::controller::WSNClusterTreeLinkerController::bindNodes(wsn::model::Nodes &nodes) {
    clustering(nodes);
}

void wsn::controller::WSNClusterTreeLinkerController::clustering(wsn::model::Nodes &nodes) {

    auto &simpleNodesArray = nodes.getNodesByType(wsn::model::NodeType::simple).getNodes();

    auto &clusterHeadNodesArray = nodes.getNodesByType(wsn::model::NodeType::cluster_head).getNodes();

    float distances[clusterHeadNodesArray.size()];
    for(auto &node : simpleNodesArray) {

        int i = 0;
        for(auto &cluster : clusterHeadNodesArray) {
            distances[i] = geometry->distanceBetweenPoints(node.getPoint(), cluster.getPoint());
            i++;
        }

        const auto *ptr = distances;
        auto index = wsn::util::ArrayHelper::getSmallestElementIndex(ptr , clusterHeadNodesArray.size());
        wsn::model::NodeLink link(&clusterHeadNodesArray.at(index), distances[index]);
        node.setLink(link);

        delete[]((distances - clusterHeadNodesArray.size()));
    }
}
