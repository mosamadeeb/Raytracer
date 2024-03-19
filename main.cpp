#include <iostream>
#include "IO/reader.h"
#include "IO/writer.h"
#include "tracing.h"

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
