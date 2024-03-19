#ifndef PROJECT_MATERIAL_H
#define PROJECT_MATERIAL_H

#include "../Eigen/Dense"

class Material {
public:
    Eigen::Array3d ambientReflectance;
    Eigen::Array3d diffuseReflectance;
    Eigen::Array3d specularReflectance;

    double phongExponent;
    Eigen::Array3d mirrorReflectance;

    Eigen::Array3d calcAmbient(const Eigen::Array3d& ambientLight) const;
    Eigen::Array3d calcDiffuse(const Eigen::Vector3d& point, const Eigen::Vector3d& normal, const PointLight& light) const;
    Eigen::Array3d calcSpecular(const Eigen::Vector3d& point, const Eigen::Vector3d& normal, const PointLight& light, const Eigen::Vector3d& eye) const;
    Eigen::Array3d calcMirror(const Eigen::Array3d& reflectedColor) const;
};


#endif //PROJECT_MATERIAL_H
