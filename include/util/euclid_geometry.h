

#ifndef WSN_EUCLID_GEOMETRY_H
#define WSN_EUCLID_GEOMETRY_H

#include "geometry.h"

namespace wsn {

    namespace util {


        class EuclidGeometry : public Geometry {

        public:
            EuclidGeometry() = default;
            double distanceBetweenPoints(const wsn::model::Point &first, const wsn::model::Point &second) const override;
        };

    }
}

#endif //WSN_EUCLID_GEOMETRY_H
