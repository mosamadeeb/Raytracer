#include "tracing.h"
#include <limits>

char clampToByte(double value) {
    return (char)fmax(0, fmin(value, 255));
}

void traceRay(Scene& scene, Ray& ray, int bounceCount, Eigen::Array3d& outColor) {
    double t_min = std::numeric_limits<double>::max();

    Object* obj = nullptr;
    int objSubId, tempSubId;

    for (Object* o : scene.objects) {
        // Check intersection with all objects in scene
        double t = o->calcIntersectionParameter(ray, tempSubId);
        if (t < t_min) {
            // Store closest object
            t_min = t;
            obj = o;
            objSubId = tempSubId;
        }
    }

    if (obj == nullptr) {
        outColor = scene.backgroundColor;
    } else {
        // Intersection point
        Eigen::Vector3d x = ray.pointAt(t_min);

        // Normal
        Eigen::Vector3d normal;
        obj->getNormalAtPoint(x, objSubId, normal);

        // Ambient shading
        outColor = obj->material->calcAmbient(scene.ambientLight);

        for (PointLight& l : scene.pointLights) {
            // Shadow ray
            Ray s = Ray::Through(x + (l.pos - x).normalized() * scene.shadowRayEpsilon, l.pos);
            double distanceToL = (l.pos - x).norm();

            bool hasShadow = false;
            for (Object* p : scene.objects) {
                // Check intersection with all objects in scene
                double t = p->calcIntersectionParameter(s, tempSubId);

                if (t < std::numeric_limits<double>::max()
                        && (s.pointAt(t) - x).norm() < distanceToL) {
                    // Ray intersects an object before the light
                    hasShadow = true;
                    break;
                }
            }

            if (!hasShadow) {
                // Diffuse and Specular shading
                outColor += obj->material->calcDiffuse(x, normal, l)
                        + obj->material->calcSpecular(x, normal, l, -(ray.direction()));
            }
        }

        // Reflections
        if (bounceCount < scene.maxRecursionDepth) {
            // Direction: d + 2(-d.n)n
            Eigen::Vector3d d = (ray.direction() + ((-ray.direction()).dot(normal)) * normal).normalized();
            Ray r(x + d * scene.shadowRayEpsilon, d);

            Eigen::Array3d reflectedColor;
            traceRay(scene, r, bounceCount + 1, reflectedColor);

            // Mirror shading
            outColor += obj->material->calcMirror(reflectedColor);
        }
    }
}

// TODO: test if camera width/height should be swapped when reading
void renderImage(Scene& scene, SceneImage& sceneImage) {
    Ray* ray;
    Eigen::Array3d color;

    for (int i = 0; i < scene.camera.width; i++) {
        for (int j = 0; j < scene.camera.height; j++) {
            ray = scene.camera.constructRayThroughPixel(i, j);

            // Primary rays start with zero bounce count
            traceRay(scene, *ray, 0, color);

            // TODO: convert intensity values
            sceneImage.buffer[i][j * 3] = clampToByte(color[0]);
            sceneImage.buffer[i][j * 3 + 1] = clampToByte(color[1]);
            sceneImage.buffer[i][j * 3 + 2] = clampToByte(color[2]);
        }
    }
}
