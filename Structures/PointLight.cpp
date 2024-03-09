#include "PointLight.h"

void PointLight::calcIntensityAtDistance(double distance, Eigen::Vector3d &outIntensity) const {
    outIntensity = intensity / (distance * distance);
}
