#include "SceneImage.h"

SceneImage::SceneImage(int width, int height) {
    this->width = width;
    this->height = height;

    buffer = new char*[height];

    for (int i = 0; i < height; i++) {
        buffer[i] = new char[width * 3];
    }
}

SceneImage::~SceneImage() {
    for (int i = 0; i < height; i++) {
        delete[] buffer[i];
    }

    delete[] buffer;
}
