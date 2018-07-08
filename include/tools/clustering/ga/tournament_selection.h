//
// Created by palatin on 6/16/18.
//

#ifndef WSN_TOURNAMENT_SELECTION_H
#define WSN_TOURNAMENT_SELECTION_H

#include "ga.h"

namespace wsn {

    namespace tools {

        namespace clustering {

            namespace ga {

                class TournamentSelection : public SelectionStrategy  {


                public:
                    explicit TournamentSelection(int tournamentSize) : k(tournamentSize) {}
                    Chromosomes select(Chromosomes &chromosomes, bool maximize, unsigned int elitism) const;


                private:
                    int k = 0;
                };

            }
        }
    }
}

#endif //WSN_TOURNAMENT_SELECTION_H
