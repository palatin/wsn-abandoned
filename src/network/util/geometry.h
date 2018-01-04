

#ifndef WSN_GEOMETRY_H
#define WSN_GEOMETRY_H


#include "../model/point.h"

namespace wsn {

    namespace util {

        class Geometry {

        public:
            virtual float distanceBetweenPoints(const wsn::model::Point &first, const wsn::model::Point &second);

        };
    }
}

#endif //WSN_GEOMETRY_H
