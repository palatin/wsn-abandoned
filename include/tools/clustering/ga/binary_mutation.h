

#ifndef WSN_BINARY_MUTATION_H
#define WSN_BINARY_MUTATION_H


#include "ga.h"

namespace wsn {

    namespace tools {

        namespace clustering {

            namespace ga {

                class BinaryMutation : public MutationStrategy {


                public:
                    void mutate(Chromosomes &chromosomes) const override;
                };

            }

        }
    }
}
#endif //WSN_BINARY_MUTATION_H
