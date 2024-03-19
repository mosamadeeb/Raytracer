#ifndef RAYTRACER_TRACING_H
#define RAYTRACER_TRACING_H

#include "Structures/Scene.h"
#include "Structures/SceneImage.h"

void traceRay(Scene& scene, Ray& ray, int bounceCount, Eigen::Array3d& outColor);

void renderImage(Scene& scene, SceneImage& sceneImage);

#endif //RAYTRACER_TRACING_H
