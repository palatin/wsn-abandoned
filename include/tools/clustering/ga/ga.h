

#ifndef WSN_GA_H
#define WSN_GA_H

#include "../../../util/random.h"

#include "../clustering.h"

namespace wsn {

    namespace tools {

        namespace clustering {

            namespace ga {


                struct Chromosome {
                    std::vector<bool> genes;
                    float fitness = 0;

                    bool operator>(const Chromosome &chromosome) {
                        return fitness > chromosome.fitness;
                    }

                    bool operator<(const Chromosome &chromosome) {
                        return fitness < chromosome.fitness;
                    }


                    static Chromosome randomize(unsigned long genCount, unsigned int clusters) {

                        wsn::util::Random random;
                        Chromosome chromosome;

                        chromosome.genes.resize(genCount, false);

                        for (auto &index : random.uniqueRandomLongsInRange(0, genCount, clusters)) {
                            chromosome.genes.at(index) = true;
                        }

                        return chromosome;
                    }
                };


                typedef std::vector<Chromosome> Chromosomes;

                class SelectionStrategy {

                public:
                    virtual Chromosomes select(Chromosomes &chromosomes, bool maximize, unsigned int elitism = 0) const = 0;
                };

                class CrossoverStrategy {

                public:
                    virtual void crossover(Chromosome &firstParent, Chromosome &secondParent) const = 0;
                };

                class MutationStrategy {

                public:
                    virtual void mutate(Chromosomes &chromosomes) const = 0;

                };

                class FitnessStrategy {

                public:
                    virtual float calculateFitness(const Clusters &clusters) const = 0;

                    virtual bool stopCriteria(const Chromosomes &populations) const = 0;

                    virtual bool isMaximize() const = 0;
                };

                typedef std::unique_ptr<SelectionStrategy> SelectionStrategyPtr;
                typedef std::unique_ptr<CrossoverStrategy> CrossoverStrategyPtr;
                typedef std::unique_ptr<FitnessStrategy> FitnessStrategyPtr;
                typedef std::unique_ptr<MutationStrategy> MutationStrategyPtr;


                class GAConfiguration {

                public:
                    GAConfiguration(SelectionStrategyPtr selectionStrategyPtr,
                                    CrossoverStrategyPtr crossoverStrategyPtr,
                                    MutationStrategyPtr mutationStrategyPtr, FitnessStrategyPtr fitnessStrategyPtr) :
                            selectionStrategyPtr(std::move(selectionStrategyPtr)),
                            crossoverStrategyPtr(std::move(crossoverStrategyPtr)),
                            mutationStrategyPtr(std::move(mutationStrategyPtr)),
                            fitnessStrategyPtr(std::move(fitnessStrategyPtr)) {
                    }


                    SelectionStrategyPtr selectionStrategyPtr;
                    FitnessStrategyPtr fitnessStrategyPtr;
                    CrossoverStrategyPtr crossoverStrategyPtr;
                    MutationStrategyPtr mutationStrategyPtr;

                };


                class GAClustering : public Clustering {


                public:
                    GAClustering(GAConfiguration& configuration, wsn::util::GeometryPtr geometryPtr, unsigned int populationSize);

                    GAClustering(GAConfiguration configuration, wsn::util::GeometryPtr geometry,
                                 unsigned int populationSize, std::shared_ptr<Clustering> clusterPtr);



                    Clusters buildClusters(const wsn::model::NodeList &nodes);

                protected:
                    GAConfiguration configuration;
                    unsigned int populationSize;
                    double crossoverProbability;
                    std::shared_ptr<Clustering> clusterPtr;


                    Chromosomes init(const wsn::model::NodeList &nodes) const;

                    void calculateFitnesses(Chromosomes &populations, const wsn::model::NodeList &nodes) const;

                    Clusters chromosomeToClusters(Chromosome &chromosome, const wsn::model::NodeList &nodes) const;

                    Chromosome clustersToChromosome(const Clusters &clusters) const;

                    void crossover(Chromosomes &populations) const;

                };
            }


        }
    }
}


#endif //WSN_GA_H
