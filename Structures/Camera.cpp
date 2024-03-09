#include "Camera.h"

Ray* Camera::constructRayThroughPixel(int i, int j) const {

    Eigen::Vector3d dir;

    dir.normalize();

    return new Ray(pos, dir);
}
