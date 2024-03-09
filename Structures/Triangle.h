#ifndef PROJECT_TRIANGLE_H
#define PROJECT_TRIANGLE_H

#include "../Eigen/Dense"
#include "Object.h"

class Triangle : public Object {
public:
    Eigen::Vector3d pos_a;
    Eigen::Vector3d pos_b;
    Eigen::Vector3d pos_c;

    Eigen::Vector3d normal;

    void precalcNormal();

    double calcIntersectionParameter(const Ray &distanceVec, int &objectSubId) override;
    void getNormalAtPoint(const Eigen::Vector3d &point, int objectSubId, Eigen::Vector3d &normalVec) override;
};


#endif //PROJECT_TRIANGLE_H
