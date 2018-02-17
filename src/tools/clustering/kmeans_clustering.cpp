
#include <cassert>
#include <numeric>
#include <random>
#include <algorithm>
#include <util/array_helper.h>
#include "tools/clustering/kmeans_clustering.h"

using wsn::tools::clustering::KMeansClustering;


KMeansClustering::KMeansClustering(wsn::util::GeometryPtr geometry, unsigned int clusters) : geometry(std::move(geometry)), clusterCount(clusters) {
    seed = time(NULL);
}

KMeansClustering::KMeansClustering(wsn::util::GeometryPtr geometry, unsigned int clusters, long seed) : geometry(std::move(geometry)), clusterCount(clusters), seed(seed) {

}

wsn::tools::clustering::NodesClusters KMeansClustering::buildClusters(const wsn::model::NodeList &nodes) {

    assert(nodes.size() >= clusterCount);


    auto clusters = initClusters(nodes, clusterCount);


    bool stop = false;
    unsigned long it = 0;
    while(!stop) {
        clearCluster(clusters);
        assignNodesToClusters(clusters, nodes);

        stop = calculateNewCenters(clusters);
        it++;
    }

    std::vector<wsn::tools::clustering::NodesCluster> chsCLusters(clusterCount);

    for (unsigned int i = 0; i < clusterCount; ++i) {
        auto &cluster = clusters.at(i);
        std::vector<wsn::model::Point> clusterNodesPoints(cluster.nodes.size());

        for (unsigned int j = 0; j < cluster.nodes.size(); ++j) {
            clusterNodesPoints[j] = cluster.nodes.at(j)->getLocation();
        }

        unsigned int ch = findNearestCentroid(clusterNodesPoints, cluster.centroid);

        chsCLusters[i].CH = cluster.nodes.at(ch);
        cluster.nodes.erase(cluster.nodes.begin() + ch);
        chsCLusters[i].nodes = std::move(cluster.nodes);

    }

    return chsCLusters;
}

std::vector<KMeansClustering::Cluster> KMeansClustering::initClusters(const wsn::model::NodeList &nodes, unsigned int clusterCount) {

    std::vector<Cluster> clusters(clusterCount);

    std::vector<unsigned long> numbers(nodes.size());

    //generate numbers from 0 - nodeCount to choose CHs
    std::iota(numbers.begin(), numbers.end(), 0);

    std::shuffle(numbers.begin(), numbers.end(), std::mt19937(seed));

    for (unsigned int i = 0; i < clusterCount; ++i) {
        clusters[i].centroid = nodes.at(numbers[i])->getLocation();
    }

    return clusters;
}

void KMeansClustering::assignNodesToClusters(std::vector<KMeansClustering::Cluster> &clusters,
                                             const wsn::model::NodeList &nodes) {

    std::vector<wsn::model::Point> clustersCentroids(clusterCount);
    for (unsigned int i = 0; i < clusterCount; ++i) {
        clustersCentroids[i] = clusters.at(i).centroid;
    }
    for (auto node : nodes) {
        clusters.at(findNearestCentroid(clustersCentroids, node->getLocation())).nodes.push_back(node);
    }
}


unsigned int KMeansClustering::findNearestCentroid(std::vector<wsn::model::Point> &clusters,
                                                   const wsn::model::Point &point) {
    wsn::util::ArrayHelper arrayHelper;

    std::vector<double> distances(clusters.size());

    for (unsigned int i = 0; i < clusters.size(); ++i) {
        distances.at(i) = geometry->distanceBetweenPoints(clusters.at(i), point);
    }

    return static_cast<unsigned int>(std::get<0>(arrayHelper.getSmallestElement(&distances[0], clusters.size())));
}

bool KMeansClustering::calculateNewCenters(std::vector<KMeansClustering::Cluster> &clusters)  {

    bool isSameCentroids = true;
    for (auto &cluster : clusters) {
        auto oldCenter = cluster.centroid;

        cluster.centroid = cluster.calculateCenterOfMass();
        if(cluster.centroid != oldCenter)
            isSameCentroids = false;
    }

    return isSameCentroids;

}

void KMeansClustering::clearCluster(std::vector<KMeansClustering::Cluster> &clusters)  {
    for(auto &cluster : clusters) {
        auto &nodes = cluster.nodes;
        nodes.erase(nodes.begin(), nodes.end());
    }
}




