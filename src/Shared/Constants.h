#pragma once
#include <vector>
#include <glm/glm.hpp>

namespace Constant
{
    const std::vector<float> Player = {
        // positions          // normals           // texture coords
        -0.5f, -0.5f, -0.5f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  1.0f,  1.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f, -0.5f,  1.0f,  1.0f,  1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
    };

    const std::vector<float> Enemy = {
        // positions         //normals              // texture coords
        -1.0f, -0.5f, -0.5f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f,
        1.0f, -0.5f, -0.5f,  1.0f,  1.0f,  1.0f,  1.0f,  0.0f,
        1.0f,  0.5f, -0.5f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,
        1.0f,  0.5f, -0.5f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,
        -1.0f,  0.5f, -0.5f,  1.0f,  1.0f,  1.0f,  0.0f,  1.0f,
        -1.0f, -0.5f, -0.5f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f,

        -1.0f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
        1.0f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
        1.0f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        1.0f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        -1.0f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
        -1.0f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

        -1.0f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        -1.0f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        -1.0f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -1.0f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -1.0f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        -1.0f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

        1.0f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        1.0f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        1.0f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        1.0f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        1.0f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        1.0f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

        -1.0f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
        1.0f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
        1.0f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        1.0f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        -1.0f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
        -1.0f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

        -1.0f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
        1.0f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
        1.0f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        1.0f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        -1.0f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
        -1.0f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
    };

    const std::vector<float> Grass = {
        // Front face
        -20.f, -5.f,  3.f,  1.0f,  1.0f,  1.0f, 0.0f, 0.0f,  // Bottom left
        20.f, -5.f,  3.f,  1.0f,  1.0f,  1.0f, 1.0f, 0.0f,  // Bottom right
        20.f,  5.f,  3.f,  1.0f,  1.0f,  1.0f, 1.0f, 1.0f,  // Top right
        20.f,  5.f,  3.f,  1.0f,  1.0f,  1.0f, 1.0f, 1.0f,  // Top right
        -20.f,  5.f,  3.f,  1.0f,  1.0f,  1.0f, 0.0f, 1.0f,  // Top left
        -20.f, -5.f,  3.f,  1.0f,  1.0f,  1.0f, 0.0f, 0.0f,  // Bottom left

        // Left face
        -20.f,  5.f,  3.f,  0.0f,  0.0f,  1.0f, 0.0f, 1.0f,  // Top front
        -20.f,  5.f, -3.f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f,  // Top back
        -20.f, -5.f, -3.f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f,  // Bottom back
        -20.f, -5.f, -3.f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f,  // Bottom back
        -20.f, -5.f,  3.f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f,  // Bottom front
        -20.f,  5.f,  3.f,  0.0f,  0.0f,  1.0f, 0.0f, 1.0f,  // Top front

        // Right face
        20.f,  5.f,  3.f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f,  // Top front
        20.f,  5.f, -3.f, -1.0f,  0.0f,  0.0f, 1.0f, 1.0f,  // Top back
        20.f, -5.f, -3.f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f,  // Bottom back
        20.f, -5.f, -3.f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f,  // Bottom back
        20.f, -5.f,  3.f, -1.0f,  0.0f,  0.0f, 0.0f, 0.0f,  // Bottom front
        20.f,  5.f,  3.f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f,  // Top front

        // Back face
        -20.f, -5.f, -3.f,  1.0f,  0.0f,  0.0f, 0.0f, 0.0f,  // Bottom left
        20.f, -5.f, -3.f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f,  // Bottom right
        20.f,  5.f, -3.f,  1.0f,  0.0f,  0.0f, 1.0f, 1.0f,  // Top right
        20.f,  5.f, -3.f,  1.0f,  0.0f,  0.0f, 1.0f, 1.0f,  // Top right
        -20.f,  5.f, -3.f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f,  // Top left
        -20.f, -5.f, -3.f,  1.0f,  0.0f,  0.0f, 0.0f, 0.0f,  // Bottom left

        // Top face
        -20.f,  5.f,  3.f,  0.0f, 1.0f,  0.0f, 0.0f, 1.0f,  // Front left
        20.f,  5.f,  3.f,  0.0f, 1.0f,  0.0f, 1.0f, 1.0f,  // Front right
        20.f,  5.f, -3.f,  0.0f, 1.0f,  0.0f, 1.0f, 0.0f,  // Back right
        20.f,  5.f, -3.f,  0.0f, 1.0f,  0.0f, 1.0f, 0.0f,  // Back right
        -20.f,  5.f, -3.f,  0.0f, 1.0f,  0.0f, 0.0f, 0.0f,  // Back left
        -20.f,  5.f,  3.f,  0.0f, 1.0f,  0.0f, 0.0f, 1.0f,  // Front left

        // Bottom face
        -20.f, -5.f,  3.f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f,  // Front left
        20.f, -5.f,  3.f,  0.0f,  1.0f,  0.0f, 1.0f, 1.0f,  // Front right
        20.f, -5.f, -3.f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f,  // Back right
        20.f, -5.f, -3.f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f,  // Back right
        -20.f, -5.f, -3.f,  0.0f,  1.0f,  0.0f, 0.0f, 0.0f,  // Back left
        -20.f, -5.f,  3.f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f   // Front left
    };

    const std::vector<float> Road = {
        // Front face
        -20.f, -5.f,  3.f,  1.0f,  1.0f,  1.0f, 0.0f, 0.0f,  // Bottom left
        20.f, -5.f,  3.f,  1.0f,  1.0f,  1.0f, 1.0f, 0.0f,  // Bottom right
        20.f,  5.f,  3.f,  1.0f,  1.0f,  1.0f, 1.0f, 1.0f,  // Top right
        20.f,  5.f,  3.f,  1.0f,  1.0f,  1.0f, 1.0f, 1.0f,  // Top right
        -20.f,  5.f,  3.f,  1.0f,  1.0f,  1.0f, 0.0f, 1.0f,  // Top left
        -20.f, -5.f,  3.f,  1.0f,  1.0f,  1.0f, 0.0f, 0.0f,  // Bottom left

        // Left face
        -20.f,  5.f,  3.f,  0.0f,  0.0f,  1.0f, 0.0f, 1.0f,  // Top front
        -20.f,  5.f, -3.f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f,  // Top back
        -20.f, -5.f, -3.f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f,  // Bottom back
        -20.f, -5.f, -3.f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f,  // Bottom back
        -20.f, -5.f,  3.f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f,  // Bottom front
        -20.f,  5.f,  3.f,  0.0f,  0.0f,  1.0f, 0.0f, 1.0f,  // Top front

        // Right face
        20.f,  5.f,  3.f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f,  // Top front
        20.f,  5.f, -3.f, -1.0f,  0.0f,  0.0f, 1.0f, 1.0f,  // Top back
        20.f, -5.f, -3.f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f,  // Bottom back
        20.f, -5.f, -3.f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f,  // Bottom back
        20.f, -5.f,  3.f, -1.0f,  0.0f,  0.0f, 0.0f, 0.0f,  // Bottom front
        20.f,  5.f,  3.f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f,  // Top front

        // Back face
        -20.f, -5.f, -3.f,  1.0f,  0.0f,  0.0f, 0.0f, 0.0f,  // Bottom left
        20.f, -5.f, -3.f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f,  // Bottom right
        20.f,  5.f, -3.f,  1.0f,  0.0f,  0.0f, 1.0f, 1.0f,  // Top right
        20.f,  5.f, -3.f,  1.0f,  0.0f,  0.0f, 1.0f, 1.0f,  // Top right
        -20.f,  5.f, -3.f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f,  // Top left
        -20.f, -5.f, -3.f,  1.0f,  0.0f,  0.0f, 0.0f, 0.0f,  // Bottom left

        // Top face
        -20.f,  5.f,  3.f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f,  // Front left
        20.f,  5.f,  3.f,  0.0f, -1.0f,  0.0f, 1.0f, 1.0f,  // Front right
        20.f,  5.f, -3.f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f,  // Back right
        20.f,  5.f, -3.f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f,  // Back right
        -20.f,  5.f, -3.f,  0.0f, -1.0f,  0.0f, 0.0f, 0.0f,  // Back left
        -20.f,  5.f,  3.f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f,  // Front left

        // Bottom face
        -20.f, -5.f,  3.f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f,  // Front left
        20.f, -5.f,  3.f,  0.0f,  1.0f,  0.0f, 1.0f, 1.0f,  // Front right
        20.f, -5.f, -3.f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f,  // Back right
        20.f, -5.f, -3.f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f,  // Back right
        -20.f, -5.f, -3.f,  0.0f,  1.0f,  0.0f, 0.0f, 0.0f,  // Back left
        -20.f, -5.f,  3.f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f   // Front left
    };

    const std::vector<float> Lines = {
        // Line 1
        // Front face
        -20.f,  3.5f,  3.f,  1.0f,  1.0f,  1.0f, 0.f, 1.f, // Vertex 1
        -20.f,  2.5f,  3.f,  1.0f,  1.0f,  1.0f, 0.f, 0.f, // Vertex 2
        -14.f,  2.5f,  3.f,  1.0f,  1.0f,  1.0f, 1.f, 0.f, // Vertex 3
        -14.f,  2.5f,  3.f,  1.0f,  1.0f,  1.0f, 1.f, 0.f, // Vertex 4
        -14.f,  3.5f,  3.f,  1.0f,  1.0f,  1.0f, 1.f, 1.f, // Vertex 5
        -20.f,  3.5f,  3.f,  1.0f,  1.0f,  1.0f, 0.f, 1.f, // Vertex 6

        // Back face
        -20.f,  3.5f, -3.f,  0.0f,  0.0f,  1.0f, 0.f, 1.f, // Vertex 1
        -20.f,  2.5f, -3.f,  0.0f,  0.0f,  1.0f, 0.f, 0.f, // Vertex 2
        -14.f,  2.5f, -3.f,  0.0f,  0.0f,  1.0f, 1.f, 0.f, // Vertex 3
        -14.f,  2.5f, -3.f,  0.0f,  0.0f,  1.0f, 1.f, 0.f, // Vertex 4
        -14.f,  3.5f, -3.f,  0.0f,  0.0f,  1.0f, 1.f, 1.f, // Vertex 5
        -20.f,  3.5f, -3.f,  0.0f,  0.0f,  1.0f, 0.f, 1.f, // Vertex 6

        // Right face
        -14.f,  3.5f,  3.f, -1.0f,  0.0f,  0.0f, 0.f, 1.f, // Vertex 1
        -14.f,  2.5f,  3.f, -1.0f,  0.0f,  0.0f, 0.f, 0.f, // Vertex 2
        -14.f,  2.5f, -3.f, -1.0f,  0.0f,  0.0f, 1.f, 0.f, // Vertex 3
        -14.f,  2.5f, -3.f, -1.0f,  0.0f,  0.0f, 1.f, 0.f, // Vertex 4
        -14.f,  3.5f, -3.f, -1.0f,  0.0f,  0.0f, 1.f, 1.f, // Vertex 5
        -14.f,  3.5f,  3.f, -1.0f,  0.0f,  0.0f, 0.f, 1.f, // Vertex 6

        // Left face
        -20.f,  3.5f,  3.f,  1.0f,  0.0f,  0.0f, 0.f, 1.f, // Vertex 1
        -20.f,  2.5f,  3.f,  1.0f,  0.0f,  0.0f, 0.f, 0.f, // Vertex 2
        -20.f,  2.5f, -3.f,  1.0f,  0.0f,  0.0f, 1.f, 0.f, // Vertex 3
        -20.f,  2.5f, -3.f,  1.0f,  0.0f,  0.0f, 1.f, 0.f, // Vertex 4
        -20.f,  3.5f, -3.f,  1.0f,  0.0f,  0.0f, 1.f, 1.f, // Vertex 5
        -20.f,  3.5f,  3.f,  1.0f,  0.0f,  0.0f, 0.f, 1.f, // Vertex 6

        // Top face
        -20.f,  3.5f,  3.f,  0.0f, -1.0f,  0.0f, 0.f, 1.f, // Vertex 1
        -14.f,  3.5f,  3.f,  0.0f, -1.0f,  0.0f, 0.f, 0.f, // Vertex 2
        -14.f,  3.5f, -3.f,  0.0f, -1.0f,  0.0f, 1.f, 0.f, // Vertex 3
        -14.f,  3.5f, -3.f,  0.0f, -1.0f,  0.0f, 1.f, 0.f, // Vertex 4
        -20.f,  3.5f, -3.f,  0.0f, -1.0f,  0.0f, 1.f, 1.f, // Vertex 5
        -20.f,  3.5f,  3.f,  0.0f, -1.0f,  0.0f, 0.f, 1.f, // Vertex 6

        // Bottom face
        -20.f,  2.5f,  3.f,  0.0f,  1.0f,  0.0f, 0.f, 1.f, // Vertex 1
        -14.f,  2.5f,  3.f,  0.0f,  1.0f,  0.0f, 0.f, 0.f, // Vertex 2
        -14.f,  2.5f, -3.f,  0.0f,  1.0f,  0.0f, 1.f, 0.f, // Vertex 3
        -14.f,  2.5f, -3.f,  0.0f,  1.0f,  0.0f, 1.f, 0.f, // Vertex 4
        -20.f,  2.5f, -3.f,  0.0f,  1.0f,  0.0f, 1.f, 1.f, // Vertex 5
        -20.f,  2.5f,  3.f,  0.0f,  1.0f,  0.0f, 0.f, 1.f, // Vertex 6

        // Line 2
        // Front face
        -8.f,  3.5f,  3.f,  1.0f,  1.0f,  1.0f, 0.f, 1.f, // Vertex 1
        -8.f,  2.5f,  3.f,  1.0f,  1.0f,  1.0f, 0.f, 0.f, // Vertex 2
        -2.f,  2.5f,  3.f,  1.0f,  1.0f,  1.0f, 1.f, 0.f, // Vertex 3
        -2.f,  2.5f,  3.f,  1.0f,  1.0f,  1.0f, 1.f, 0.f, // Vertex 4
        -2.f,  3.5f,  3.f,  1.0f,  1.0f,  1.0f, 1.f, 1.f, // Vertex 5
        -8.f,  3.5f,  3.f,  1.0f,  1.0f,  1.0f, 0.f, 1.f, // Vertex 6

        // Back face
        -8.f,  3.5f, -3.f,  0.0f,  0.0f,  1.0f, 0.f, 1.f, // Vertex 1
        -8.f,  2.5f, -3.f,  0.0f,  0.0f,  1.0f, 0.f, 0.f, // Vertex 2
        -2.f,  2.5f, -3.f,  0.0f,  0.0f,  1.0f, 1.f, 0.f, // Vertex 3
        -2.f,  2.5f, -3.f,  0.0f,  0.0f,  1.0f, 1.f, 0.f, // Vertex 4
        -2.f,  3.5f, -3.f,  0.0f,  0.0f,  1.0f, 1.f, 1.f, // Vertex 5
        -8.f,  3.5f, -3.f,  0.0f,  0.0f,  1.0f, 0.f, 1.f, // Vertex 6

        // Right face
        -2.f,  3.5f,  3.f, -1.0f,  0.0f,  0.0f, 0.f, 1.f, // Vertex 1
        -2.f,  2.5f,  3.f, -1.0f,  0.0f,  0.0f, 0.f, 0.f, // Vertex 2
        -2.f,  2.5f, -3.f, -1.0f,  0.0f,  0.0f, 1.f, 0.f, // Vertex 3
        -2.f,  2.5f, -3.f, -1.0f,  0.0f,  0.0f, 1.f, 0.f, // Vertex 4
        -2.f,  3.5f, -3.f, -1.0f,  0.0f,  0.0f, 1.f, 1.f, // Vertex 5
        -2.f,  3.5f,  3.f, -1.0f,  0.0f,  0.0f, 0.f, 1.f, // Vertex 6

        // Left face
        -8.f,  3.5f,  3.f,  1.0f,  0.0f,  0.0f, 0.f, 1.f, // Vertex 1
        -8.f,  2.5f,  3.f,  1.0f,  0.0f,  0.0f, 0.f, 0.f, // Vertex 2
        -8.f,  2.5f, -3.f,  1.0f,  0.0f,  0.0f, 1.f, 0.f, // Vertex 3
        -8.f,  2.5f, -3.f,  1.0f,  0.0f,  0.0f, 1.f, 0.f, // Vertex 4
        -8.f,  3.5f, -3.f,  1.0f,  0.0f,  0.0f, 1.f, 1.f, // Vertex 5
        -8.f,  3.5f,  3.f,  1.0f,  0.0f,  0.0f, 0.f, 1.f, // Vertex 6

        // Top face
        -8.f,  3.5f,  3.f,  0.0f, -1.0f,  0.0f, 0.f, 1.f, // Vertex 1
        -2.f,  3.5f,  3.f,  0.0f, -1.0f,  0.0f, 0.f, 0.f, // Vertex 2
        -2.f,  3.5f, -3.f,  0.0f, -1.0f,  0.0f, 1.f, 0.f, // Vertex 3
        -2.f,  3.5f, -3.f,  0.0f, -1.0f,  0.0f, 1.f, 0.f, // Vertex 4
        -8.f,  3.5f, -3.f,  0.0f, -1.0f,  0.0f, 1.f, 1.f, // Vertex 5
        -8.f,  3.5f,  3.f,  0.0f, -1.0f,  0.0f, 0.f, 1.f, // Vertex 6

        // Bottom face
        -8.f,  2.5f,  3.f,  0.0f,  1.0f,  0.0f, 0.f, 1.f, // Vertex 1
        -2.f,  2.5f,  3.f,  0.0f,  1.0f,  0.0f, 0.f, 0.f, // Vertex 2
        -2.f,  2.5f, -3.f,  0.0f,  1.0f,  0.0f, 1.f, 0.f, // Vertex 3
        -2.f,  2.5f, -3.f,  0.0f,  1.0f,  0.0f, 1.f, 0.f, // Vertex 4
        -8.f,  2.5f, -3.f,  0.0f,  1.0f,  0.0f, 1.f, 1.f, // Vertex 5
        -8.f,  2.5f,  3.f,  0.0f,  1.0f,  0.0f, 0.f, 1.f, // Vertex 6

        // Line 3
        // Front face
        4.f,  3.5f,  3.f,  1.0f,  1.0f,  1.0f, 0.f, 1.f, // Vertex 1
        4.f,  2.5f,  3.f,  1.0f,  1.0f,  1.0f, 0.f, 0.f, // Vertex 2
        10.f,  2.5f,  3.f,  1.0f,  1.0f,  1.0f, 1.f, 0.f, // Vertex 3
        10.f,  2.5f,  3.f,  1.0f,  1.0f,  1.0f, 1.f, 0.f, // Vertex 4
        10.f,  3.5f,  3.f,  1.0f,  1.0f,  1.0f, 1.f, 1.f, // Vertex 5
        4.f,  3.5f,  3.f,  1.0f,  1.0f,  1.0f, 0.f, 1.f, // Vertex 6

        // Back face
        4.f,  3.5f, -3.f,  0.0f,  0.0f,  1.0f, 0.f, 1.f, // Vertex 1
        4.f,  2.5f, -3.f,  0.0f,  0.0f,  1.0f, 0.f, 0.f, // Vertex 2
        10.f,  2.5f, -3.f,  0.0f,  0.0f,  1.0f, 1.f, 0.f, // Vertex 3
        10.f,  2.5f, -3.f,  0.0f,  0.0f,  1.0f, 1.f, 0.f, // Vertex 4
        10.f,  3.5f, -3.f,  0.0f,  0.0f,  1.0f, 1.f, 1.f, // Vertex 5
        4.f,  3.5f, -3.f,  0.0f,  0.0f,  1.0f, 0.f, 1.f, // Vertex 6

        // Right face
        10.f,  3.5f,  3.f, -1.0f,  0.0f,  0.0f, 0.f, 1.f, // Vertex 1
        10.f,  2.5f,  3.f, -1.0f,  0.0f,  0.0f, 0.f, 0.f, // Vertex 2
        10.f,  2.5f, -3.f, -1.0f,  0.0f,  0.0f, 1.f, 0.f, // Vertex 3
        10.f,  2.5f, -3.f, -1.0f,  0.0f,  0.0f, 1.f, 0.f, // Vertex 4
        10.f,  3.5f, -3.f, -1.0f,  0.0f,  0.0f, 1.f, 1.f, // Vertex 5
        10.f,  3.5f,  3.f, -1.0f,  0.0f,  0.0f, 0.f, 1.f, // Vertex 6

        // Left face
        4.f,  3.5f,  3.f,  1.0f,  0.0f,  0.0f, 0.f, 1.f, // Vertex 1
        4.f,  2.5f,  3.f,  1.0f,  0.0f,  0.0f, 0.f, 0.f, // Vertex 2
        4.f,  2.5f, -3.f,  1.0f,  0.0f,  0.0f, 1.f, 0.f, // Vertex 3
        4.f,  2.5f, -3.f,  1.0f,  0.0f,  0.0f, 1.f, 0.f, // Vertex 4
        4.f,  3.5f, -3.f,  1.0f,  0.0f,  0.0f, 1.f, 1.f, // Vertex 5
        4.f,  3.5f,  3.f,  1.0f,  0.0f,  0.0f, 0.f, 1.f, // Vertex 6

        // Top face
        4.f,  3.5f,  3.f,  0.0f, -1.0f,  0.0f, 0.f, 1.f, // Vertex 1
        10.f,  3.5f,  3.f,  0.0f, -1.0f,  0.0f, 0.f, 0.f, // Vertex 2
        10.f,  3.5f, -3.f,  0.0f, -1.0f,  0.0f, 1.f, 0.f, // Vertex 3
        10.f,  3.5f, -3.f,  0.0f, -1.0f,  0.0f, 1.f, 0.f, // Vertex 4
        4.f,  3.5f, -3.f,  0.0f, -1.0f,  0.0f, 1.f, 1.f, // Vertex 5
        4.f,  3.5f,  3.f,  0.0f, -1.0f,  0.0f, 0.f, 1.f, // Vertex 6

        // Bottom face
        4.f,  2.5f,  3.f,  0.0f,  1.0f,  0.0f, 0.f, 1.f, // Vertex 1
        10.f,  2.5f,  3.f,  0.0f,  1.0f,  0.0f, 0.f, 0.f, // Vertex 2
        10.f,  2.5f, -3.f,  0.0f,  1.0f,  0.0f, 1.f, 0.f, // Vertex 3
        10.f,  2.5f, -3.f,  0.0f,  1.0f,  0.0f, 1.f, 0.f, // Vertex 4
        4.f,  2.5f, -3.f,  0.0f,  1.0f,  0.0f, 1.f, 1.f, // Vertex 5
        4.f,  2.5f,  3.f,  0.0f,  1.0f,  0.0f, 0.f, 1.f, // Vertex 6
    };

    const std::vector<float> Lamp = {
        // Base
        // Front face        //Colors
        // Base Cube
        // Front face
        -0.25f, -1.5f,  0.25f, 0.5f, 0.5f, 0.5f,
        0.25f, -1.5f,  0.25f, 0.5f, 0.5f, 0.5f,
        0.25f,  1.5f,  0.25f, 0.5f, 0.5f, 0.5f,
        -0.25f, -1.5f,  0.25f, 0.5f, 0.5f, 0.5f,
        0.25f,  1.5f,  0.25f, 0.5f, 0.5f, 0.5f,
        -0.25f,  1.5f,  0.25f, 0.5f, 0.5f, 0.5f,

        // Back face
        -0.25f, -1.5f, -0.25f, 0.5f, 0.5f, 0.5f,
        0.25f, -1.5f, -0.25f, 0.5f, 0.5f, 0.5f,
        0.25f,  1.5f, -0.25f, 0.5f, 0.5f, 0.5f,
        -0.25f, -1.5f, -0.25f, 0.5f, 0.5f, 0.5f,
        0.25f,  1.5f, -0.25f, 0.5f, 0.5f, 0.5f,
        -0.25f,  1.5f, -0.25f, 0.5f, 0.5f, 0.5f,

        // Top face
        -0.25f,  1.5f,  0.25f, 0.5f, 0.5f, 0.5f,
        0.25f,  1.5f,  0.25f, 0.5f, 0.5f, 0.5f,
        0.25f,  1.5f, -0.25f, 0.5f, 0.5f, 0.5f,
        -0.25f,  1.5f,  0.25f, 0.5f, 0.5f, 0.5f,
        0.25f,  1.5f, -0.25f, 0.5f, 0.5f, 0.5f,
        -0.25f,  1.5f, -0.25f, 0.5f, 0.5f, 0.5f,

        // Bottom face
        -0.25f, -1.5f,  0.25f, 0.5f, 0.5f, 0.5f,
        0.25f, -1.5f,  0.25f, 0.5f, 0.5f, 0.5f,
        0.25f, -1.5f, -0.25f, 0.5f, 0.5f, 0.5f,
        -0.25f, -1.5f,  0.25f, 0.5f, 0.5f, 0.5f,
        0.25f, -1.5f, -0.25f, 0.5f, 0.5f, 0.5f,
        -0.25f, -1.5f, -0.25f, 0.5f, 0.5f, 0.5f,

        // Right face
        0.25f, -1.5f,  0.25f, 0.5f, 0.5f, 0.5f,
        0.25f, -1.5f, -0.25f, 0.5f, 0.5f, 0.5f,
        0.25f,  1.5f, -0.25f, 0.5f, 0.5f, 0.5f,
        0.25f, -1.5f,  0.25f, 0.5f, 0.5f, 0.5f,
        0.25f,  1.5f, -0.25f, 0.5f, 0.5f, 0.5f,
        0.25f,  1.5f,  0.25f, 0.5f, 0.5f, 0.5f,

        // Left face
        -0.25f, -1.5f,  0.25f, 0.5f, 0.5f, 0.5f,
        -0.25f, -1.5f, -0.25f, 0.5f, 0.5f, 0.5f,
        -0.25f,  1.5f, -0.25f, 0.5f, 0.5f, 0.5f,
        -0.25f, -1.5f,  0.25f, 0.5f, 0.5f, 0.5f,
        -0.25f,  1.5f, -0.25f, 0.5f, 0.5f, 0.5f,
        -0.25f,  1.5f,  0.25f, 0.5f, 0.5f, 0.5f,

        // Lamp Cube
        // Front face
        -0.5f,  1.5f,  0.5f, 1.0f, 1.0f, 1.0f,
        0.5f,  1.5f,  0.5f, 1.0f, 1.0f, 1.0f,
        0.5f,  2.0f,  0.5f, 1.0f, 1.0f, 1.0f,
        -0.5f,  1.5f,  0.5f, 1.0f, 1.0f, 1.0f,
        0.5f,  2.0f,  0.5f, 1.0f, 1.0f, 1.0f,
        -0.5f,  2.0f,  0.5f, 1.0f, 1.0f, 1.0f,

        // Back face
        -0.5f,  1.5f, -0.5f, 1.0f, 1.0f, 1.0f,
        0.5f,  1.5f, -0.5f, 1.0f, 1.0f, 1.0f,
        0.5f,  2.0f, -0.5f, 1.0f, 1.0f, 1.0f,
        -0.5f,  1.5f, -0.5f, 1.0f, 1.0f, 1.0f,
        0.5f,  2.0f, -0.5f, 1.0f, 1.0f, 1.0f,
        -0.5f,  2.0f, -0.5f, 1.0f, 1.0f, 1.0f,

        // Top face
        -0.5f,  2.0f,  0.5f, 1.0f, 1.0f, 1.0f,
        0.5f,  2.0f,  0.5f, 1.0f, 1.0f, 1.0f,
        0.5f,  2.0f, -0.5f, 1.0f, 1.0f, 1.0f,
        -0.5f,  2.0f,  0.5f, 1.0f, 1.0f, 1.0f,
        0.5f,  2.0f, -0.5f, 1.0f, 1.0f, 1.0f,
        -0.5f,  2.0f, -0.5f, 1.0f, 1.0f, 1.0f,

        // Bottom face
        -0.5f,  1.5f,  0.5f, 1.0f, 1.0f, 1.0f,
        0.5f,  1.5f,  0.5f, 1.0f, 1.0f, 1.0f,
        0.5f,  1.5f, -0.5f, 1.0f, 1.0f, 1.0f,
        -0.5f,  1.5f,  0.5f, 1.0f, 1.0f, 1.0f,
        0.5f,  1.5f, -0.5f, 1.0f, 1.0f, 1.0f,
        -0.5f,  1.5f, -0.5f, 1.0f, 1.0f, 1.0f,

        // Right face
        0.5f,  1.5f,  0.5f, 1.0f, 1.0f, 1.0f,
        0.5f,  1.5f, -0.5f, 1.0f, 1.0f, 1.0f,
        0.5f,  2.0f, -0.5f, 1.0f, 1.0f, 1.0f,
        0.5f,  1.5f,  0.5f, 1.0f, 1.0f, 1.0f,
        0.5f,  2.0f, -0.5f, 1.0f, 1.0f, 1.0f,
        0.5f,  2.0f,  0.5f, 1.0f, 1.0f, 1.0f,

        // Left face
        -0.5f,  1.5f,  0.5f, 1.0f, 1.0f, 1.0f,
        -0.5f,  1.5f, -0.5f, 1.0f, 1.0f, 1.0f,
        -0.5f,  2.0f, -0.5f, 1.0f, 1.0f, 1.0f,
        -0.5f,  1.5f,  0.5f, 1.0f, 1.0f, 1.0f,
        -0.5f,  2.0f, -0.5f, 1.0f, 1.0f, 1.0f,
        -0.5f,  2.0f,  0.5f, 1.0f, 1.0f, 1.0f,
    };

    const float PlayerSpeed = 7;
    const float EnemySpeed = 10;

    const glm::vec3 GrassBaseVec = glm::vec3(0.f, -3.65f, -12.f);
    const glm::vec3 RoadBaseVec = glm::vec3(0.f, -3.65f, -22.f);
    const glm::vec3 LampBaseVec = glm::vec3(-15.f, 0.0f, -15.f);
    const glm::vec3 LineBaseVec =  glm::vec3(4.5f, -3.60f, -18.5f);

    const glm::vec3 EnemyEVec = glm::vec3(-18.f, 0.f, -44.f);
    const glm::vec3 EnemyWVec = glm::vec3(18.f, 0.f, -39.f);

    const float DepthOffset = -20.f;

    const std::string PlayerTexture = "player.png";
    const std::string PlayerSpecularTexture = "player_specular.png";
    const std::string PlayerNormalTexture = "player_normal.png";
    const std::string EnemyTexture = "enemy.png";
    const std::string EnemyNormalTexture = "enemy_normal.png";
    const std::string EnemySpecularTexture = "enemy_specular.png";
    const std::string GrassTexture = "grass.png";
    const std::string GrassNormalTexture = "grass_normal.png";
    const std::string GrassSpecularTexture = "grass_specular.png";
    const std::string RoadTexture = "road.png";
    const std::string RoadNormalTexture = "road_normal.png";
    const std::string RoadSpecularTexture = "road_specular.png";
    const std::string LinesTexture = "lines.png";
    const std::string LinesNormalTexture = "lines_normal.png";
    const std::string LinesSpecularTexture = "lines_specular.png";
}