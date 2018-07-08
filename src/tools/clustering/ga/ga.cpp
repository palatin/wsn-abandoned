

#include "tools/clustering/ga/ga.h"

using wsn::tools::clustering::ga::GAClustering;

using wsn::tools::clustering::ga::SelectionStrategyPtr;
using wsn::tools::clustering::ga::FitnessStrategyPtr;
using wsn::tools::clustering::ga::CrossoverStrategyPtr;
using wsn::tools::clustering::ga::MutationStrategyPtr;
using wsn::tools::clustering::ga::Chromosome;
using wsn::tools::clustering::ga::Chromosomes;
using wsn::tools::clustering::ga::GAClustering;
using wsn::tools::clustering::ga::GAConfiguration;



GAClustering::GAClustering(GAConfiguration& configuration, wsn::util::GeometryPtr geometryPtr,  unsigned int populationSize)
        : Clustering(std::move(geometryPtr)), configuration(std::move(configuration)),
          populationSize(populationSize) {

}



wsn::tools::clustering::Clusters GAClustering::buildClusters(const wsn::model::NodeList &nodes) {

    crossoverProbability = 0.6;

    Chromosomes populations = init(nodes);

    calculateFitnesses(populations, nodes);
    do {

        populations = configuration.selectionStrategyPtr->select(populations, configuration.fitnessStrategyPtr->isMaximize(), 1);

        crossover(populations);

        configuration.mutationStrategyPtr->mutate(populations);

        calculateFitnesses(populations, nodes);

    } while(!configuration.fitnessStrategyPtr->stopCriteria(populations));


    wsn::util::ArrayHelper arrayHelper;



    return chromosomeToClusters(populations.at(arrayHelper.getLargestElement(&populations.at(0), populations.size()).first), nodes);

}

Chromosomes GAClustering::init(const wsn::model::NodeList &nodes) const {

    Chromosomes chromosomes(populationSize);

    unsigned int startIndex = 0;


    if(clusterPtr != nullptr) {
        chromosomes.at(0) = Chromosome(clustersToChromosome(clusterPtr->buildClusters(nodes)));
        startIndex++;
    }

    for (unsigned int i = startIndex; i < populationSize; ++i) {
        chromosomes.at(i) = Chromosome(Chromosome::randomize(nodes.size(), 15));
    }

    return chromosomes;
}

void GAClustering::calculateFitnesses(Chromosomes &populations, const wsn::model::NodeList &nodes) const {

    for(auto &chromosome : populations) {
        chromosome.fitness = configuration.fitnessStrategyPtr->calculateFitness(chromosomeToClusters(chromosome, nodes));
    }
}

void GAClustering::crossover(Chromosomes &populations) const {
    //if populations has odd parents - ignore last
    unsigned long count = populations.size() % 2 == 0 ? populations.size() : populations.size() - 1;

    wsn::util::Random random;
    for(unsigned long i = 0 ; i < count - 1; i++) {
        if(random.randomFloatInRange(0, 1) >= crossoverProbability) {
            configuration.crossoverStrategyPtr->crossover(populations.at(i), populations.at(i + 1));
        }
    }

}

Chromosome GAClustering::clustersToChromosome(const wsn::tools::clustering::Clusters &clusters) const {

    Chromosome chromosome;

    unsigned long counts = 0;

    for (unsigned long i = 0; i < clusters.size(); ++i) {
        counts += clusters.clusterAt(i).size();
    }

    chromosome.genes.resize(counts, false);

    for (unsigned int i = 0; i < clusters.size(); ++i) {
        chromosome.genes.at(clusters.clusterAt(i).begin()->second) = true;
    }

    return chromosome;
}

wsn::tools::clustering::Clusters GAClustering::chromosomeToClusters(Chromosome &chromosome, const wsn::model::NodeList &nodes) const {

    std::vector<wsn::model::Point> centers;

    for (unsigned long i = 0; i < chromosome.genes.size(); ++i) {
        if(chromosome.genes.at(i))
            centers.push_back(nodes.at(i)->getLocation());

    }

    wsn::tools::clustering::Clusters clusters;

    Clustering::assignNodesToClusters(centers, clusters, nodes);

    return clusters;
}





