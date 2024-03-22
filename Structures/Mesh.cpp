#include "Mesh.h"

double Mesh::calcIntersectionParameter(const Ray &distanceVec, int &objectSubId) {
    double t_min = std::numeric_limits<double>::max();
    int tempSubId;

    for (int i = 0; i < triangles.size(); i++) {
        // Check intersection for all triangles in the mesh, and accept the closest one
        double t = triangles[i]->calcIntersectionParameter(distanceVec, tempSubId);
        if (t < t_min) {
            t_min = t;
            objectSubId = i;
        }
    }

    return t_min;
}

void Mesh::getNormalAtPoint(const Eigen::Vector3d &point, int objectSubId, Eigen::Vector3d &normalVec) {
    if (objectSubId < triangles.size()) {
        // Get precomputed normal of the intersected triangle
        normalVec = triangles[objectSubId]->normal;
    }
}
