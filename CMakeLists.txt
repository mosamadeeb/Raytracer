cmake_minimum_required(VERSION 3.22)
project(Raytracer)

set(CMAKE_CXX_STANDARD 11)

add_executable(Raytracer main.cpp
        Structures/Scene.h
        Structures/Object.h
        Structures/Sphere.cpp
        Structures/Sphere.h
        Structures/Triangle.cpp
        Structures/Triangle.h
        Structures/Mesh.cpp
        Structures/Mesh.h
        Structures/PointLight.cpp
        Structures/PointLight.h
        Structures/Material.cpp
        Structures/Material.h
        Structures/Camera.cpp
        Structures/Camera.h
        IO/reader.cpp
        IO/reader.h
        IO/writer.cpp
        IO/writer.h
        Structures/SceneImage.cpp
        Structures/SceneImage.h
        Structures/Ray.h
        tracing.cpp
        tracing.h
)
