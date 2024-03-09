#include "Triangle.h"

void Triangle::precalcNormal() {
    normal = (pos_b - pos_a).cross(pos_c - pos_a);
    normal.normalize();
}

double Triangle::calcIntersectionParameter(const Ray &distanceVec, int &objectSubId) {
    return 0;
}

void Triangle::getNormalAtPoint(const Eigen::Vector3d &point, int objectSubId, Eigen::Vector3d &normalVec) {

}
