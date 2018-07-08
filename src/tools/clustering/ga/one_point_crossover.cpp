

#include "tools/clustering/ga/one_point_crossover.h"
#include <iterator>

using wsn::tools::clustering::ga::Chromosome;
using wsn::tools::clustering::ga::OnePointCrossover;




void OnePointCrossover::crossover(Chromosome &firstParent, Chromosome &secondParent) const {

    long crossoverPoint = random.randomLongInRange(1, firstParent.genes.size() - 1);


    auto it1 = firstParent.genes.begin() + crossoverPoint;
    auto it2 =  secondParent.genes.begin() + crossoverPoint;
    for (long i  = crossoverPoint;  i < firstParent.genes.size(); ++i, ++it1, ++it2) {
        std::iter_swap(it1, it2);
    }


}
