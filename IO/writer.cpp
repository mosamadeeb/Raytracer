#include <iostream>
#include <fstream>
#include "writer.h"

void writePPM(SceneImage &sceneImage, const char *path) {
    std::ofstream output(path);

    output << "P6\n";       // magic
    output << sceneImage.width << ' ' << sceneImage.height << '\n';
    output << 255 << '\n';  // max color value

    // height rows, each consisting of width pixels, each pixel is rgb
    for (int i = 0; i < sceneImage.height; i++) {
        for (int j = 0; j < sceneImage.width * 3; j += 3) {
            output << sceneImage.buffer[i][j]
                << sceneImage.buffer[i][j + 1]
                << sceneImage.buffer[i][j + 2];
        }
    }

    output.close();
}
