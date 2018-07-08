

#ifndef WSN_DBI_FITNESS_H
#define WSN_DBI_FITNESS_H

#include "ga.h"

namespace wsn {

    namespace tools {

        namespace clustering {

            namespace ga {

                class DBIFitness : public FitnessStrategy {


                public:
                    DBIFitness(const wsn::model::NodeList &list, wsn::util::GeometryPtr geometryPtr);

                    float calculateFitness(const Clusters &clusters) const override;

                    bool stopCriteria(const Chromosomes &populations) const override;

                    bool isMaximize() const override;

                private:
                    const wsn::model::NodeList &nodes;
                    const wsn::util::GeometryPtr geometryPtr;

                };
            }
        }
    }
}
#endif //WSN_DBI_FITNESS_H
