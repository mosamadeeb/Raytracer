#ifndef PROJECT_OBJECT_H
#define PROJECT_OBJECT_H

#include "Material.h"
#include "Ray.h"

class Object {
public:
    const Material* material = nullptr;

    /// Calculates the intersection of a ray with this object
    /// \param distanceVec ray from camera to image plane at a specific pixel
    /// \param objectSubId out parameter to avoid some recalculations (e.g. index of tri in a mesh)
    /// \return ray parameter for intersection: the t in r(t)
    virtual double calcIntersectionParameter(const Ray &distanceVec, int& objectSubId) = 0;

    /// Retrieves the normal vector at the given point
    /// \param point assumed to be on the object
    /// \param objectSubId same id received from calcIntersectionParameter()
    /// \param normalVec out result normal vector
    virtual void getNormalAtPoint(const Eigen::Vector3d &point, int objectSubId, Eigen::Vector3d &normalVec) = 0;
};


#endif //PROJECT_OBJECT_H
