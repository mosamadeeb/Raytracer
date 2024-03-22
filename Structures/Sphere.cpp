#include "Sphere.h"

double Sphere::calcIntersectionParameter(const Ray &distanceVec, int &objectSubId) {
    const Eigen::Vector3d& o = distanceVec.origin();
    const Eigen::Vector3d& d = distanceVec.direction();
    Eigen::Vector3d c = pos;

    double A = d.dot(d);
    double B = 2 * d.dot(o - c);
    double C = (o - c).dot(o - c) - radius * radius;

    double D = (B * B) - (4 * A * C);
    if (D < 0) {
        return std::numeric_limits<double>::max();
    }

    double t1 = (-B + sqrt(D)) / 2 * A;
    double t2 = (-B - sqrt(D)) / 2 * A;

    // TODO: Check if either t1 or t2 can be negative
    double t = t1 > 0 ? (t2 > 0 ? fmin(t1, t2) : t1) : fmax(t2, 0);
    return t > 0 ? t : std::numeric_limits<double>::max();
}

void Sphere::getNormalAtPoint(const Eigen::Vector3d &point, int objectSubId, Eigen::Vector3d &normalVec) {
    normalVec = ((point - pos) / radius).normalized();
}
