

#include <util/random.h>
#include "tools/clustering/ga/binary_mutation.h"


using wsn::tools::clustering::ga::Chromosomes;
using wsn::tools::clustering::ga::Chromosome;
using wsn::tools::clustering::ga::BinaryMutation;


void BinaryMutation::mutate(Chromosomes &chromosomes) const {

    wsn::util::Random random;

    unsigned long gens = chromosomes.at(0).genes.size();

    for (unsigned long i = 0; i < chromosomes.size(); ++i) {
        auto mutationGen = random.randomLongInRange(0, gens);
        chromosomes.at(i).genes.at(mutationGen) = !chromosomes.at(i).genes.at(mutationGen);
    }
}
