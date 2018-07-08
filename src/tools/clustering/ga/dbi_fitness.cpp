
#include "util/array_helper.h"
#include "tools/clustering/ga/dbi_fitness.h"

using wsn::tools::clustering::ga::DBIFitness;
using wsn::tools::clustering::ga::Chromosome;


DBIFitness::DBIFitness(const wsn::model::NodeList &list, wsn::util::GeometryPtr geometryPtr) : nodes(list), geometryPtr(std::move(geometryPtr)) {

}

float DBIFitness::calculateFitness(const Clusters &clusters) const {

    wsn::util::ArrayHelper arrayHelper;


    float s[clusters.size()] = {};
    for (unsigned int i = 0; i < clusters.size(); ++i) {
        auto &cluster = clusters.clusterAt(i);
        for (auto &node : cluster) {
            s[i] += node.first;
        }
        if(cluster.size() > 1)
            s[i] /= (cluster.size() - 1);

    }

    double Rij[clusters.size()][clusters.size() - 1] = {};

    for (unsigned int i = 0; i < clusters.size(); ++i) {
        for (unsigned int j = 0; j < clusters.size(); ++j) {
            if(i != j)
                Rij[i][j] = (s[i] + s[j]) / geometryPtr->distanceBetweenPoints(nodes.at(clusters.clusterAt(i).begin()->second)->getLocation(),
                                                                               nodes.at(clusters.clusterAt(j).begin()->second)->getLocation());
        }
    }

    double Ri[clusters.size()] = {};
    for (unsigned int i = 0; i < clusters.size(); ++i) {
        Ri[i] = *arrayHelper.getLargestElement(&Rij[i][0], clusters.size()).second;
    }

    float DB = 0;

    for (unsigned int i = 0; i < clusters.size(); ++i) {
        DB += Ri[i];
    }
    DB /= clusters.size();

    return DB;
}

bool DBIFitness::stopCriteria(const Chromosomes &populations) const {

    
    return false;
}

bool DBIFitness::isMaximize() const {
    return false;
}

