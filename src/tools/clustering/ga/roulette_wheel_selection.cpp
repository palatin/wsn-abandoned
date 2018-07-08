

#include <util/random.h>
#include "tools/clustering/ga/roulette_wheel_selection.h"

using wsn::tools::clustering::ga::Chromosomes;
using wsn::tools::clustering::ga::Chromosome;
using wsn::tools::clustering::ga::RouletteWheelSelection;

Chromosomes RouletteWheelSelection::select(Chromosomes &chromosomes, bool maximize, unsigned int elitism = 0) const {


    unsigned int count = chromosomes.size();


    wsn::util::Random random;

    Chromosomes selected(count);

    wsn::util::ArrayHelper arrayHelper;


    float fitnessSum = 0;

    std::vector<float> fitnesses;

    for(auto &chromosome : chromosomes) {
        fitnesses.push_back(chromosome.fitness);
    }

    //reverse fitnesses
    if(!maximize) {
        arrayHelper.normalize(&fitnesses[0], fitnesses.size());

        for (auto &fitness : fitnesses) {
            fitness = 1 - fitness;
        }
    }

    for(auto &fitness : fitnesses) {
        fitnessSum += fitness;
    }


    for(unsigned int i = 0; i < elitism; i++) {
        selected[i] = chromosomes.at(arrayHelper.getLargestElement(&fitnesses[0], fitnesses.size()).first);
    }


    for(unsigned long i = elitism; i < count; i++) {
        float value = random.randomFloatInRange(0, 1) * fitnessSum;

        for(unsigned int j = 0; j < fitnesses.size(); ++j) {

            value -= fitnesses.at(j);

            if(value <= 0) {
                selected.at(i) = chromosomes.at(j);
                break;
            }
        }

    }

    return selected;
}
