

#ifndef WSN_GA_BUILDER_H
#define WSN_GA_BUILDER_H

#include "ga.h"

namespace wsn {

    namespace tools {

        namespace clustering {

            namespace ga {

                class GAClusteringBuilder {

                    GAClusteringBuilder(GAConfiguration configuration);

                    void populationSize(unsigned int populationSize);

                    GAClustering build();

                };
            }
        }
    }
}

#endif //WSN_GA_BUILDER_H
