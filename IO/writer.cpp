#include <iostream>
#include <fstream>
#include "writer.h"

void writePPM(SceneImage &sceneImage, const char *path) {
    std::ofstream output(path);

    output << "P6\n";       // magic
    output << sceneImage.width << ' ' << sceneImage.height << '\n';
    output << 255 << '\n';  // max color value

    // height rows, each consisting of width pixels, each pixel is rgb
    for (int i = 0; i < sceneImage.width; i++) {
        for (int j = 0; j < sceneImage.height; j++) {
            // swap height and width indices
            output << sceneImage.buffer[j][i * 3]
                << sceneImage.buffer[j][i * 3 + 1]
                << sceneImage.buffer[j][i * 3 + 2];
        }
    }

    output.close();
}
