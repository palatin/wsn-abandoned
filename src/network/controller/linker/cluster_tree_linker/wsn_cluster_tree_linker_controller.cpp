

#include "wsn_cluster_tree_linker_controller.h"
#include "../../../util/array_helper.h"



wsn::controller::linker::WSNClusterTreeLinkerController::WSNClusterTreeLinkerController(linker::ClusteringController *clusteringController,
                                                                                        std::shared_ptr<util::Geometry> geometry) : clusteringController(clusteringController), geometry(geometry) {}

void wsn::controller::linker::WSNClusterTreeLinkerController::linkNodes(wsn::model::Nodes &nodes) {

    //clusterize nodes
    auto clusters = clusteringController->clusterize(nodes);

    for(auto &cluster : clusters) {
        wsn::model::Node *ch = cluster.ch;
        for(auto node : cluster.nodes.getNodes()) {
            node->setLink(wsn::model::NodeLink(ch, geometry.get()->distanceBetweenPoints(node->getPoint(), ch->getPoint())));
        }
    }
}

/*void wsn::controller::linker::WSNClusterTreeLinkerController::clustering(wsn::model::Nodes &nodes) {

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
        auto index =  std::get<0>(wsn::util::ArrayHelper::getSmallestElement(ptr , clusterHeadNodesArray.size()));
        wsn::model::NodeLink link(clusterHeadNodesArray.at(index), distances[index]);
        node.setLink(link);

    }
}*/







