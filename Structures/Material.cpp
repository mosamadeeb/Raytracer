#include "Material.h"

Eigen::Array3d Material::calcAmbient(const Eigen::Array3d& ambientLight) const {
    // AMB * CA
    return ambientReflectance * ambientLight;
}

Eigen::Array3d Material::calcDiffuseSpecular(const Eigen::Vector3d& point, const Eigen::Vector3d& normal, const PointLight& light, const Eigen::Vector3d& eye) const {
    // Vector from object to light
    Eigen::Vector3d lightVec = (light.pos - point);

    // h: vector halfway between eye and I
    Eigen::Vector3d halfwayVec = (eye + lightVec).normalized();

    // DIF * CL/(r^2) * n.I
    Eigen::Array3d diffuse = diffuseReflectance * light.calcIntensityAtDistance(lightVec.norm()) * fmax(0, normal.dot(lightVec));

    // SPE * CL * (n.h)^p
    Eigen::Array3d specular = specularReflectance * light.calcIntensityAtDistance(lightVec.norm()) * pow(fmax(0, normal.dot(halfwayVec)), phongExponent);

    return diffuse + specular;
}

Eigen::Array3d Material::calcMirror(const Eigen::Array3d& reflectedColor) const {
    // MIR * CM
    return mirrorReflectance * reflectedColor;
}
