#include "Triangle.h"

void Triangle::precalcNormal() {
    normal = (pos_b - pos_a).cross(pos_c - pos_a);
    normal.normalize();
}

double Triangle::calcIntersectionParameter(const Ray &distanceVec, int &objectSubId) {
    // Formulas (p. 48-50): https://users.aalto.fi/~lehtinj7/CS-C3100/2021/slides/12.1.ray.tracing.intersections.pdf

    // Using barycentric coordinates, we can write
    // o + t*d = a + beta*(b-a) + gamma*(c-a)
    // We end up with 3 equations, one for each of x, y, z components of the vectors
    // We can find t, beta, and gamma by solving the system

    Eigen::Matrix3d A;
    A << pos_a - pos_b, pos_a - pos_c, distanceVec.direction();

    Eigen::Vector3d b = pos_a - distanceVec.origin();

    // x = [beta, gamma, t]
    Eigen::Vector3d x = A.lu().solve(b);

    if (    x[0] > 0            // beta > 0
            && x[1] > 0         // gamma > 0
            && x[0] + x[1] < 1  // beta + gamma < 1
            && x[2] > 0) {      // t > 0
        return x[2];
    }

    // No intersection
    return std::numeric_limits<double>::max();
}

void Triangle::getNormalAtPoint(const Eigen::Vector3d &point, int objectSubId, Eigen::Vector3d &normalVec) {
    // Same normal everywhere inside the triangle
    normalVec = normal;
}
