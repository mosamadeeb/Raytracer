#ifndef PROJECT_MESH_H
#define PROJECT_MESH_H

#include <vector>
#include "../Eigen/Dense"
#include "Object.h"
#include "Triangle.h"

class Mesh : public Object {
public:
    std::vector<Triangle*> triangles;

    double calcIntersectionParameter(const Ray &distanceVec, int &objectSubId) override;
    void getNormalAtPoint(const Eigen::Vector3d &point, int objectSubId, Eigen::Vector3d &normalVec) override;
};


#endif //PROJECT_MESH_H
