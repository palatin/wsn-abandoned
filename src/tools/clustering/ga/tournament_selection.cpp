//
// Created by palatin on 6/16/18.
//

#include "tools/clustering/ga/tournament_selection.h"


using wsn::tools::clustering::ga::Chromosomes;
using wsn::tools::clustering::ga::TournamentSelection;

Chromosomes TournamentSelection::select(Chromosomes &chromosomes, bool maximize, unsigned int elitism) const {

    unsigned int size = chromosomes.size();

    Chromosomes newPopulation;
    newPopulation.reserve(size);

    wsn::util::Random random;
    wsn::util::ArrayHelper arrayHelper;

    for (int i = 0; i < size; ++i) {

        auto applicants = random.uniqueRandomLongsInRange(0 , size, k);
        std::vector<float> fitnesses(k);
        for(auto &index : applicants) {
            fitnesses.push_back(chromosomes.at(index).fitness);
        }
        int winner = 0;
        if(maximize)
            winner = arrayHelper.getLargestElement(&fitnesses[0], k).first;
        else
            winner = arrayHelper.getSmallestElement(&fitnesses[0], k).first;

        newPopulation.push_back(chromosomes.at(applicants.at(winner)));

    }

    return newPopulation;
}
