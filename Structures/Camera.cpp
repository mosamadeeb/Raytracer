#include "Camera.h"

Ray* Camera::constructRayThroughPixel(int i, int j) const {
    // Coordinate system formulas: https://computergraphics.stackexchange.com/questions/8115/understanding-of-camera-up-vector
    Eigen::Vector3d e = pos;
    Eigen::Vector3d w = (-gaze).normalized();
    Eigen::Vector3d u = up.cross(w).normalized();
    Eigen::Vector3d v = w.cross(u);

    Eigen::Vector3d q = e + (-w * nearDistance) + nearPlane.left * u + nearPlane.top * v;

    double su = (nearPlane.right - nearPlane.left) * (i + 0.5) / width;
    double sv = (nearPlane.top - nearPlane.bottom) * (j + 0.5) / height;

    Eigen::Vector3d s = q + su * u - sv * v;

    return new Ray(e, (s - e).normalized());
}
