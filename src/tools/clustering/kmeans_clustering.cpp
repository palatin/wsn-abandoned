
#include <cassert>
#include <numeric>
#include <random>
#include <algorithm>
#include <util/array_helper.h>
#include <util/random.h>
#include "tools/clustering/kmeans_clustering.h"

using wsn::tools::clustering::KMeansClustering;


KMeansClustering::KMeansClustering(wsn::util::GeometryPtr geometry, unsigned int clusters) : Clustering(std::move(geometry)), clusterCount(clusters) {
    seed = time(nullptr);
}

KMeansClustering::KMeansClustering(wsn::util::GeometryPtr geometry, unsigned int clusters, long seed) : Clustering(std::move(geometry)), clusterCount(clusters), seed(seed) {

}

wsn::tools::clustering::Clusters KMeansClustering::buildClusters(const wsn::model::NodeList &nodes) {

    assert(nodes.size() >= clusterCount);

    wsn::tools::clustering::Clusters clusters(clusterCount);

    auto centers = initClusters(nodes, clusterCount);


    bool stop = false;

    while(!stop) {
        clusters.clearClusters();
        Clustering::assignNodesToClusters(centers, clusters, nodes);
        stop = calculateNewCenters(clusters, centers, nodes);
    }


    //change centers to nearest nodes
    for (unsigned int i = 0; i < clusters.size(); ++i) {
        centers.at(i) = nodes.at(clusters.clusterAt(i).begin()->second)->getLocation();
    }

    clusters.clearClusters();
    Clustering::assignNodesToClusters(centers, clusters, nodes);

    return clusters;
}

std::vector<wsn::model::Point> KMeansClustering::initClusters(const wsn::model::NodeList &nodes, unsigned int clusterCount) {

    std::vector<wsn::model::Point> clusters(clusterCount);

    wsn::util::Random random;

    auto numbers = random.uniqueRandomLongsInRange(0, nodes.size(), clusterCount);

    for (unsigned int i = 0; i < clusterCount; ++i) {
        clusters[i] = nodes.at(numbers[i])->getLocation();
    }

    return clusters;
}



bool KMeansClustering::calculateNewCenters(wsn::tools::clustering::Clusters &clusters,
                                           std::vector<wsn::model::Point> &centers,
                                           const wsn::model::NodeList &nodes) {

    bool isSameCentroids = true;
    for (unsigned int i = 0; i < clusters.size(); ++i) {
        auto oldCenter = centers.at(i);

        wsn::model::Point point(0, 0, 0);
        for (auto &node : clusters.clusterAt(i)) {
            point += nodes.at(node.second)->getLocation();
        }

        point /= clusters.clusterAt(i).size();

        centers.at(i) = point;

        if (point != oldCenter)
            isSameCentroids = false;
    }


    return isSameCentroids;
}









