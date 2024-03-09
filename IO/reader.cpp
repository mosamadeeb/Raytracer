#include <map>

#include "reader.h"

std::unordered_map<std::string, enum Tag> tagMap = {
        { "#BackgroundColor", TagBackgroundColor },
        { "#MaxRecursionDepth", TagMaxRecursionDepth },
        { "#ShadowRayEpsilon", TagShadowRayEpsilon },
        { "#Camera", TagCamera },
        { "#Material", TagMaterial },
        { "#AmbientLight", TagAmbientLight },
        { "#PointLight", TagPointLight },
        { "#VertexList", TagVertexList },
        { "#Sphere", TagSphere },
        { "#Triangle", TagTriangle },
        { "#Mesh", TagMesh },
};

void Reader::readFile(Scene &scene) {
    std::string cur;

    std::map<int, Material*> materials;
    std::vector<Eigen::Vector3d> vertices;

    int id;
    Material* mat;
    Eigen::Vector3d vertex;
    Eigen::Vector3i vertexIds;
    PointLight pointLight;
    Sphere* sphere;
    Triangle* triangle;
    Mesh* mesh;

    while (!stream->eof() && nextIsTag()) {
        (*stream) >> cur;

        switch (tagMap[cur]) {
            case TagBackgroundColor:
                readVector3(scene.backgroundColor);
                break;
            case TagMaxRecursionDepth:
                scene.maxRecursionDepth = readInt();
                break;
            case TagShadowRayEpsilon:
                scene.shadowRayEpsilon = readDouble();
                break;
            case TagCamera:
                readVector3(scene.camera.pos);
                readVector3(scene.camera.gaze);
                readVector3(scene.camera.up);

                scene.camera.nearPlane.left = readDouble();
                scene.camera.nearPlane.right = readDouble();
                scene.camera.nearPlane.bottom = readDouble();
                scene.camera.nearPlane.top = readDouble();

                scene.camera.nearDistance = readDouble();

                scene.camera.width = readInt();
                scene.camera.height = readInt();
                break;
            case TagMaterial:
                id = readInt();

                mat = new Material();
                readVector3(mat->ambientReflectance);
                readVector3(mat->diffuseReflectance);
                readVector3(mat->specularReflectance);
                mat->phongExponent = readDouble();
                readVector3(mat->mirrorReflectance);

                materials[id] = mat;
                break;
            case TagAmbientLight:
                readVector3(scene.ambientLight);
                break;
            case TagPointLight:
                readInt(); // Light ID

                readVector3(pointLight.pos);
                readVector3(pointLight.intensity);

                scene.pointLights.push_back(pointLight);
                break;
            case TagVertexList:
                while (!nextIsTag() && !stream->eof()) {
                    readVector3(vertex);
                    vertices.push_back(vertex);
                }
                break;
            case TagSphere:
                sphere = new Sphere();
                readInt(); // Sphere ID

                id = readInt(); // Material ID
                sphere->material = materials[id];

                id = readInt(); // Vertex ID
                sphere->pos = vertices[id - 1];

                sphere->radius = readDouble();

                scene.objects.push_back(sphere);
                break;
            case TagTriangle:
                triangle = new Triangle();
                readInt(); // Triangle ID

                id = readInt(); // Material ID
                triangle->material = materials[id];

                readVector3Int(vertexIds); // Vertex IDs

                // Counter-clockwise triangle indices
                triangle->pos_a = vertices[vertexIds.x() - 1];
                triangle->pos_b = vertices[vertexIds.y() - 1];
                triangle->pos_c = vertices[vertexIds.z() - 1];

                triangle->precalcNormal();

                scene.objects.push_back(triangle);
                break;
            case TagMesh:
                mesh = new Mesh();
                readInt(); // Mesh ID

                id = readInt(); // Material ID
                mesh->material = materials[id];

                while (!nextIsTag() && !stream->eof()) {
                    triangle = new Triangle();
                    readVector3Int(vertexIds); // Vertex IDs

                    // Counter-clockwise triangle indices
                    triangle->pos_a = vertices[vertexIds.x() - 1];
                    triangle->pos_b = vertices[vertexIds.y() - 1];
                    triangle->pos_c = vertices[vertexIds.z() - 1];

                    triangle->precalcNormal();

                    mesh->triangles.push_back(triangle);
                }

                scene.objects.push_back(mesh);
                break;
        }
    }
}

Reader::Reader(char *path) {
    stream = new std::ifstream(path);
}

Reader::~Reader() {
    stream->close();
}

void Reader::skipWhitespace() {
    while (stream->peek() == ' ' || stream->peek() == '\n') {
        stream->get();
    }
}

bool Reader::nextIsTag() {
    skipWhitespace();
    return stream->peek() == '#';
}

int Reader::readInt() {
    int x;
    (*stream) >> x;
    return x;
}

double Reader::readDouble() {
    double x;
    (*stream) >> x;
    return x;
}

void Reader::readVector3(Eigen::Vector3d &vec) {
    double x, y, z;
    (*stream) >> x >> y >> z;

    vec[0] = x;
    vec[1] = y;
    vec[2] = z;
}

void Reader::readVector3Int(Eigen::Vector3i &vec) {
    int x, y, z;
    (*stream) >> x >> y >> z;

    vec[0] = x;
    vec[1] = y;
    vec[2] = z;
}
