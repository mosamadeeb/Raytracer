#ifndef PROJECT_POINTLIGHT_H
#define PROJECT_POINTLIGHT_H

#include "../Eigen/Dense"

class PointLight {
public:
    Eigen::Vector3d pos;
    Eigen::Vector3d intensity;

    void calcIntensityAtDistance(double distance, Eigen::Vector3d& outIntensity) const;
};


#endif //PROJECT_POINTLIGHT_H
