#include "PointLight.h"

Eigen::Array3d PointLight::calcIntensityAtDistance(double distance) const {
    return intensity / (distance * distance);
}
