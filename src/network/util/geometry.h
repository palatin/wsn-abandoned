

#ifndef WSN_GEOMETRY_H
#define WSN_GEOMETRY_H


#include "../model/point.h"

namespace wsn {

    namespace util {

        class Geometry {

        public:
            Geometry() = default;
            virtual double distanceBetweenPoints(const wsn::model::Point &first, const wsn::model::Point &second) const = 0;

        };
    }
}

#endif //WSN_GEOMETRY_H
