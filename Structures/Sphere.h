#ifndef PROJECT_SPHERE_H
#define PROJECT_SPHERE_H

#include "../Eigen/Dense"
#include "Object.h"

class Sphere : public Object {
public:
    Eigen::Vector3d pos;
    double radius;

    double calcIntersectionParameter(const Ray &distanceVec, int &objectSubId) override;
    void getNormalAtPoint(const Eigen::Vector3d &point, int objectSubId, Eigen::Vector3d &normalVec) override;
};


#endif //PROJECT_SPHERE_H
