
#ifndef WSN_ONE_POINT_CROSSOVER_H
#define WSN_ONE_POINT_CROSSOVER_H

#include "../../../util/random.h"
#include "ga.h"

namespace wsn {

    namespace tools {

        namespace clustering {

            namespace ga {
                class OnePointCrossover : public CrossoverStrategy {

                public:
                    void crossover(Chromosome &firstParent, Chromosome &secondParent) const override;

                private:
                    wsn::util::Random random;

                };
            }

        }
    }
}
#endif //WSN_ONE_POINT_CROSSOVER_H
