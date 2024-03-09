#include <iostream>
#include "IO/reader.h"
#include "IO/writer.h"
#include "Structures/SceneImage.h"

void traceRay(Scene& scene, Ray& ray, int bounceCount, Eigen::Vector3d& outColor) {

    // Check scene.maxRecursionDepth before recursion
}

// TODO: test if camera width/height should be swapped when reading
void renderImage(Scene& scene, SceneImage& sceneImage) {
    Ray* ray;
    Eigen::Vector3d color;

    for (int i = 0; i < scene.camera.height; i++)
    {
        for (int j = 0; j < scene.camera.width; j++) {
            ray = scene.camera.constructRayThroughPixel(i, j);

            // Primary rays start with zero bounce count
            traceRay(scene, *ray, 0, color);

            // TODO: convert intensity values
            sceneImage.buffer[i][j * 3] = color[0];
            sceneImage.buffer[i][j * 3 + 1] = color[1];
            sceneImage.buffer[i][j * 3 + 2] = color[2];
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "usage: ./Raytracer input.txt" << std::endl;
        return 0;
    }

    Scene scene;

    Reader reader(argv[1]);
    reader.readFile(scene);

    SceneImage sceneImage(scene.camera.width, scene.camera.height);
    renderImage(scene, sceneImage);

    writePPM(sceneImage, "output.ppm");

    return 0;
}
