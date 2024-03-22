#include "SceneImage.h"

SceneImage::SceneImage(int width, int height) {
    this->width = width;
    this->height = height;

    buffer = new char*[width];

    for (int i = 0; i < width; i++) {
        buffer[i] = new char[height * 3];
    }
}

SceneImage::~SceneImage() {
    for (int i = 0; i < width; i++) {
        delete[] buffer[i];
    }

    delete[] buffer;
}
