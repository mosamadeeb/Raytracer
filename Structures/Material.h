#ifndef PROJECT_MATERIAL_H
#define PROJECT_MATERIAL_H

#include "../Eigen/Dense"

class Material {
public:
    Eigen::Vector3d ambientReflectance;
    Eigen::Vector3d diffuseReflectance;
    Eigen::Vector3d specularReflectance;

    double phongExponent;
    Eigen::Vector3d mirrorReflectance;
};


#endif //PROJECT_MATERIAL_H
