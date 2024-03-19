#include "Material.h"

Eigen::Array3d Material::calcAmbient(const Eigen::Array3d& ambientLight) const {
    // AMB * CA
    return ambientReflectance * ambientLight;
}

Eigen::Array3d Material::calcDiffuse(const Eigen::Vector3d& point, const Eigen::Vector3d& normal, const PointLight& light) const {
    // Vector from object to light
    Eigen::Vector3d lightVec = light.pos - point;

    // DIF * CL/(r^2) * n.I
    return diffuseReflectance * light.calcIntensityAtDistance(lightVec.norm()) * normal.dot(lightVec);
}

Eigen::Array3d Material::calcSpecular(const Eigen::Vector3d& point, const Eigen::Vector3d& normal, const PointLight& light, const Eigen::Vector3d& eye) const {
    Eigen::Vector3d lightVec = light.pos - point;

    // h: vector halfway between eye and I
    Eigen::Vector3d halfwayVec = (eye + lightVec).normalized();

    // SPE * CL * (n.h)^p
    return specularReflectance * light.intensity * pow(normal.dot(halfwayVec), phongExponent);
}

Eigen::Array3d Material::calcMirror(const Eigen::Array3d& reflectedColor) const {
    // MIR * CM
    return mirrorReflectance * reflectedColor;
}
