

#include <cmath>
#include "util/euclid_geometry.h"

double wsn::util::EuclidGeometry::distanceBetweenPoints(const wsn::model::Point &first, const wsn::model::Point &second) const {
    return sqrt(pow((first.x - second.x), 2) + pow((first.y - second.y), 2) + pow((first.z - second.z), 2));
}
