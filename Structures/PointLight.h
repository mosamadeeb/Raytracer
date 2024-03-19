#ifndef PROJECT_POINTLIGHT_H
#define PROJECT_POINTLIGHT_H

#include "../Eigen/Dense"

class PointLight {
public:
    Eigen::Vector3d pos;
    Eigen::Array3d intensity;

    Eigen::Array3d calcIntensityAtDistance(double distance) const;
};


#endif //PROJECT_POINTLIGHT_H
