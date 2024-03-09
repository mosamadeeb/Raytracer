#ifndef PROJECT_SCENE_H
#define PROJECT_SCENE_H

#include <vector>
#include "../Eigen/Dense"

#include "Camera.h"
#include "PointLight.h"
#include "Object.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Mesh.h"

class Scene {
public:
    Eigen::Vector3d ambientLight;
    Eigen::Vector3d backgroundColor;

    int maxRecursionDepth;
    double shadowRayEpsilon;

    Camera camera;
    std::vector<PointLight> pointLights;
    std::vector<Object*> objects;
};


#endif //PROJECT_SCENE_H
