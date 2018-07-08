
#include "tools/clustering/ga/two_point_crossover.h"


using wsn::tools::clustering::ga::Chromosome;
using wsn::tools::clustering::ga::TwoPointCrossover;




void TwoPointCrossover::crossover(Chromosome &firstParent, Chromosome &secondParent) const {

    long firstPoint = random.randomLongInRange(1, firstParent.genes.size() - 1);
    long secondPoint = random.randomLongInRange(1, firstParent.genes.size() - 1);

    if(secondPoint < firstPoint) {
        auto temp = secondPoint;
        secondPoint = firstPoint;
        firstPoint = temp;
    }

    auto it1 = firstParent.genes.begin() + firstPoint;
    auto it2 =  secondParent.genes.begin() + firstPoint;

    for (long i  = firstPoint;  i < secondPoint; ++i, ++it1, ++it2) {
        std::iter_swap(it1, it2);
    }

}