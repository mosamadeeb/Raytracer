#ifndef RAYTRACER_SCENEIMAGE_H
#define RAYTRACER_SCENEIMAGE_H


class SceneImage {
public:
    SceneImage(int, int);
    ~SceneImage();

    int width;
    int height;
    char** buffer;
};


#endif //RAYTRACER_SCENEIMAGE_H
