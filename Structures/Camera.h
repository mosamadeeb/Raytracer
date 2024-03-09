#ifndef PROJECT_CAMERA_H
#define PROJECT_CAMERA_H

#include "../Eigen/Dense"
#include "Ray.h"

struct NearPlane {
    double left;
    double right;
    double bottom;
    double top;
};

class Camera {
public:
    Eigen::Vector3d pos;
    Eigen::Vector3d gaze;
    Eigen::Vector3d up;

    struct NearPlane nearPlane;
    double nearDistance;

    int width;
    int height;

    Ray* constructRayThroughPixel(int i, int j) const;
};


#endif //PROJECT_CAMERA_H
