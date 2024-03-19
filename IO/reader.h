#ifndef PROJECT_READER_H
#define PROJECT_READER_H

#include <iostream>
#include <fstream>
#include <unordered_map>
#include "../Eigen/Dense"
#include "../Structures/Scene.h"

enum Tag {
    TagBackgroundColor,
    TagMaxRecursionDepth,
    TagShadowRayEpsilon,
    TagCamera,
    TagMaterial,
    TagAmbientLight,
    TagPointLight,
    TagVertexList,
    TagSphere,
    TagTriangle,
    TagMesh,
};

extern std::unordered_map<std::string, enum Tag> tagMap;

class Reader {
public:
    Reader(char*);
    ~Reader();

    void readFile(Scene&);
    void skipWhitespace();
    bool nextIsTag();
    int readInt();
    double readDouble();
    void readVector3(Eigen::Vector3d&);
    void readArray3(Eigen::Array3d&);
    void readVector3Int(Eigen::Vector3i&);

private:
    std::ifstream* stream;
};


#endif //PROJECT_READER_H
