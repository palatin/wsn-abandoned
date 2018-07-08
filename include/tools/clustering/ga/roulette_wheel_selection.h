

#ifndef WSN_ROULETTE_WHEEL_SELECTION_H
#define WSN_ROULETTE_WHEEL_SELECTION_H

#include "ga.h"

namespace wsn {

    namespace tools {

        namespace clustering {

            namespace ga {

                class RouletteWheelSelection : public SelectionStrategy {

                public:
                    Chromosomes select(Chromosomes &chromosomes, bool maximize, unsigned int elitism) const;
                };

            }
        }
    }
}
#endif //WSN_ROULETTE_WHEEL_SELECTION_H
