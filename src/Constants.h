#pragma once
#include <vector>

namespace Constant
{
    const std::vector<float> Player = {
        // Front face
        -0.5f, -0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-left corner
        0.5f, -0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-right corner
        0.0f,  0.0f,  0.5f, 1.0f, 0.0f, 0.0f,  // Middle

        0.5f, -0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-right corner
        0.5f,  0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Top-right corner
        0.0f,  0.0f,  0.5f, 1.0f, 0.0f, 0.0f,  // Middle

        0.5f,  0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Top-right corner
        -0.5f,  0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Top-left corner
        0.0f,  0.0f,  0.5f, 1.0f, 0.0f, 0.0f,  // Middle

        -0.5f,  0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Top-left corner
        -0.5f, -0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-left corner
        0.0f,  0.0f,  0.5f, 1.0f, 0.0f, 0.0f,  // Middle

        // Back face
        -0.5f, -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-left corner
        0.5f, -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-right corner
        0.0f,  0.0f, -0.5f, 1.0f, 0.0f, 0.0f,  // Middle

        0.5f, -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-right corner
        0.5f,  0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Top-right corner
        0.0f,  0.0f, -0.5f, 1.0f, 0.0f, 0.0f,  // Middle

        0.5f,  0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Top-right corner
        -0.5f,  0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Top-left corner
        0.0f,  0.0f, -0.5f, 1.0f, 0.0f, 0.0f,  // Middle

        -0.5f,  0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Top-left corner
        -0.5f, -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-left corner
        0.0f,  0.0f, -0.5f, 1.0f, 0.0f, 0.0f,  // Middle

        // Left face
        -0.5f, -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-left corner
        -0.5f, -0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-right corner
        -0.5f,  0.0f,  0.0f, 1.0f, 0.0f, 0.0f,  // Middle

        -0.5f, -0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-right corner
        -0.5f,  0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Top-right corner
        -0.5f,  0.0f,  0.0f, 1.0f, 0.0f, 0.0f,  // Middle

        -0.5f,  0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Top-right corner
        -0.5f,  0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Top-left corner
        -0.5f,  0.0f,  0.0f, 1.0f, 0.0f, 0.0f,  // Middle

        -0.5f,  0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Top-left corner
        -0.5f, -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-left corner
        -0.5f,  0.0f,  0.0f, 1.0f, 0.0f, 0.0f,  // Middle

        // Right face
        0.5f, -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-left corner
        0.5f, -0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-right corner
        0.5f,  0.0f,  0.0f, 1.0f, 0.0f, 0.0f,  // Middle

        0.5f, -0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-right corner
        0.5f,  0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Top-right corner
        0.5f,  0.0f,  0.0f, 1.0f, 0.0f, 0.0f,  // Middle

        0.5f,  0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Top-right corner
        0.5f,  0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Top-left corner
        0.5f,  0.0f,  0.0f, 1.0f, 0.0f, 0.0f,  // Middle

        0.5f,  0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Top-left corner
        0.5f, -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-left corner
        0.5f,  0.0f,  0.0f, 1.0f, 0.0f, 0.0f,  // Middle

        // Top face
        -0.5f,  0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-left corner
        0.5f,  0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-right corner
        0.0f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f,  // Middle

        0.5f,  0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-right corner
        0.5f,  0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Top-right corner
        0.0f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f,  // Middle

        0.5f,  0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Top-right corner
        -0.5f,  0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Top-left corner
        0.0f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f,  // Middle

        -0.5f,  0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Top-left corner
        -0.5f,  0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-left corner
        0.0f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f,  // Middle

        // Bottom face
        -0.5f, -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-left corner
        0.5f, -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-right corner
        0.0f, -0.5f,  0.0f, 1.0f, 0.0f, 0.0f,  // Middle

        0.5f, -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-right corner
        0.5f, -0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Top-right corner
        0.0f, -0.5f,  0.0f, 1.0f, 0.0f, 0.0f,  // Middle

        0.5f, -0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Top-right corner
        -0.5f, -0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Top-left corner
        0.0f, -0.5f,  0.0f, 1.0f, 0.0f, 0.0f,  // Middle

        -0.5f, -0.5f,  0.5f, 0.5f, 0.0f, 0.0f,  // Top-left corner
        -0.5f, -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  // Bottom-left corner
        0.0f, -0.5f,  0.0f, 1.0f, 0.0f, 0.0f   // Middle
    };

    const std::vector<float> Enemy = {
        // Front face
        -1.0f, -0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-left corner (Darker Blue)
        1.0f, -0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-right corner (Darker Blue)
        0.0f,  0.0f,  0.5f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        1.0f, -0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-right corner (Darker Blue)
        1.0f,  0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Top-right corner (Darker Blue)
        0.0f,  0.0f,  0.5f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        1.0f,  0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Top-right corner (Darker Blue)
        -1.0f,  0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Top-left corner (Darker Blue)
        0.0f,  0.0f,  0.5f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        -1.0f,  0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Top-left corner (Darker Blue)
        -1.0f, -0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-left corner (Darker Blue)
        0.0f,  0.0f,  0.5f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        // Back face
        -1.0f, -0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-left corner (Darker Blue)
        1.0f, -0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-right corner (Darker Blue)
        0.0f,  0.0f, -0.5f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        1.0f, -0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-right corner (Darker Blue)
        1.0f,  0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Top-right corner (Darker Blue)
        0.0f,  0.0f, -0.5f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        1.0f,  0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Top-right corner (Darker Blue)
        -1.0f,  0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Top-left corner (Darker Blue)
        0.0f,  0.0f, -0.5f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        -1.0f,  0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Top-left corner (Darker Blue)
        -1.0f, -0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-left corner (Darker Blue)
        0.0f,  0.0f, -0.5f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        // Left face
        -1.0f, -0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-left corner (Darker Blue)
        -1.0f, -0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-right corner (Darker Blue)
        -1.0f,  0.0f,  0.0f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        -1.0f, -0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-right corner (Darker Blue)
        -1.0f,  0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Top-right corner (Darker Blue)
        -1.0f,  0.0f,  0.0f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        -1.0f,  0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Top-right corner (Darker Blue)
        -1.0f,  0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Top-left corner (Darker Blue)
        -1.0f,  0.0f,  0.0f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        -1.0f,  0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Top-left corner (Darker Blue)
        -1.0f, -0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-left corner (Darker Blue)
        -1.0f,  0.0f,  0.0f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        // Right face
        1.0f, -0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-left corner (Darker Blue)
        1.0f, -0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-right corner (Darker Blue)
        1.0f,  0.0f,  0.0f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        1.0f, -0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-right corner (Darker Blue)
        1.0f,  0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Top-right corner (Darker Blue)
        1.0f,  0.0f,  0.0f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        1.0f,  0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Top-right corner (Darker Blue)
        1.0f,  0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Top-left corner (Darker Blue)
        1.0f,  0.0f,  0.0f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        1.0f,  0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Top-left corner (Darker Blue)
        1.0f, -0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-left corner (Darker Blue)
        1.0f,  0.0f,  0.0f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        // Top face
        -1.0f,  0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-left corner (Darker Blue)
        1.0f,  0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-right corner (Darker Blue)
        0.0f,  0.5f,  0.0f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        1.0f,  0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-right corner (Darker Blue)
        1.0f,  0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Top-right corner (Darker Blue)
        0.0f,  0.5f,  0.0f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        1.0f,  0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Top-right corner (Darker Blue)
        -1.0f,  0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Top-left corner (Darker Blue)
        0.0f,  0.5f,  0.0f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        -1.0f,  0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Top-left corner (Darker Blue)
        -1.0f,  0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-left corner (Darker Blue)
        0.0f,  0.5f,  0.0f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        // Bottom face
        -1.0f, -0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-left corner (Darker Blue)
        1.0f, -0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-right corner (Darker Blue)
        0.0f, -0.5f,  0.0f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        1.0f, -0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-right corner (Darker Blue)
        1.0f, -0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Top-right corner (Darker Blue)
        0.0f, -0.5f,  0.0f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        1.0f, -0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Top-right corner (Darker Blue)
        -1.0f, -0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Top-left corner (Darker Blue)
        0.0f, -0.5f,  0.0f, 0.5f, 0.5f, 1.0f,  // Middle (Light Blue)

        -1.0f, -0.5f,  0.5f, 0.0f, 0.0f, 0.5f,  // Top-left corner (Darker Blue)
        -1.0f, -0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  // Bottom-left corner (Darker Blue)
        0.0f, -0.5f,  0.0f, 0.5f, 0.5f, 1.0f   // Middle (Light Blue)
    };

    const std::vector<float> Grass = {
       -20.f, -5.f,  3.f, 0.0f, 0.3922f, 0.0f,  // Bottom left (dark green)
        20.f, -5.f,  3.f, 0.0f, 0.3922f, 0.0f,   // Bottom right (dark green)
        20.f,  5.f,  3.f, 0.0078f, 0.6392f, 0.1922f,   // Top right (light green)
        20.f,  5.f,  3.f, 0.0078f, 0.6392f, 0.1922f,   // Top right (light green)
        -20.f,  5.f,  3.f, 0.0078f, 0.6392f, 0.1922f,  // Top left (light green)
        -20.f, -5.f,  3.f, 0.0f, 0.3922f, 0.0f,  // Bottom left (dark green)

        // Left face
        -20.f,  5.f,  3.f, 0.0078f, 0.6392f, 0.1922f,   // Top front (light green)
        -20.f,  5.f, -3.f, 0.0078f, 0.6392f, 0.1922f,   // Top back (light green)
        -20.f, -5.f, -3.f, 0.0f, 0.3922f, 0.0f,  // Bottom back (dark green)
        -20.f, -5.f, -3.f, 0.0f, 0.3922f, 0.0f,  // Bottom back (dark green)
        -20.f, -5.f,  3.f, 0.0f, 0.3922f, 0.0f,  // Bottom front (dark green)
        -20.f,  5.f,  3.f, 0.0078f, 0.6392f, 0.1922f,   // Top front (light green)

        // Right face
        20.f,  5.f,  3.f, 0.0078f, 0.6392f, 0.1922f,   // Top front (light green)
        20.f,  5.f, -3.f, 0.0078f, 0.6392f, 0.1922f,   // Top back (light green)
        20.f, -5.f, -3.f, 0.0f, 0.3922f, 0.0f,  // Bottom back (dark green)
        20.f, -5.f, -3.f, 0.0f, 0.3922f, 0.0f,  // Bottom back (dark green)
        20.f, -5.f,  3.f, 0.0f, 0.3922f, 0.0f,  // Bottom front (dark green)
        20.f,  5.f,  3.f, 0.0078f, 0.6392f, 0.1922f,   // Top front (light green)

        // Back face
        -20.f, -5.f, -3.f, 0.0f, 0.3922f, 0.0f,  // Bottom left (dark green)
        20.f, -5.f, -3.f, 0.0f, 0.3922f, 0.0f,   // Bottom right (dark green)
        20.f,  5.f, -3.f, 0.0078f, 0.6392f, 0.1922f,   // Top right (light green)
        20.f,  5.f, -3.f, 0.0078f, 0.6392f, 0.1922f,   // Top right (light green)
        -20.f,  5.f, -3.f, 0.0078f, 0.6392f, 0.1922f,  // Top left (light green)
        -20.f, -5.f, -3.f, 0.0f, 0.3922f, 0.0f,  // Bottom left (dark green)

        // Top face
        -20.f,  5.f,  3.f, 0.0078f, 0.6392f, 0.1922f,  // Front left (light green)
        20.f,  5.f,  3.f, 0.0078f, 0.6392f, 0.1922f,   // Front right (light green)
        20.f,  5.f, -3.f, 0.0078f, 0.6392f, 0.1922f,   // Back right (light green)
        20.f,  5.f, -3.f, 0.0078f, 0.6392f, 0.1922f,   // Back right (light green)
        -20.f,  5.f, -3.f, 0.0078f, 0.6392f, 0.1922f,  // Back left (light green)
        -20.f,  5.f,  3.f, 0.0078f, 0.6392f, 0.1922f,  // Front left (light green)

        // Bottom face
        -20.f, -5.f,  3.f, 0.0f, 0.1922f, 0.0f,  // Front left (dark green)
        20.f, -5.f,  3.f, 0.0f, 0.1022f, 0.0f,   // Front right (dark green)
        20.f, -5.f, -3.f, 0.0f, 0.1022f, 0.0f,   // Back right (dark green)
        20.f, -5.f, -3.f, 0.0f, 0.1022f, 0.0f,   // Back right (dark green)
        -20.f, -5.f, -3.f, 0.0f, 0.1022f, 0.0f,  // Back left (dark green)
        -20.f, -5.f,  3.f, 0.0f, 0.1922f, 0.0f,  // Front left (dark green)
    };

    const std::vector<float> Road = {
        -20.f, -5.f,  3.f, 0.3f, 0.3f, 0.3f,  // Bottom left (dark gray)
        20.f, -5.f,  3.f, 0.3f, 0.3f, 0.3f,   // Bottom right (dark gray)
        20.f,  5.f,  3.f, 0.5f, 0.5f, 0.5f,   // Top right (light gray)
        20.f,  5.f,  3.f, 0.5f, 0.5f, 0.5f,   // Top right (light gray)
        -20.f,  5.f,  3.f, 0.5f, 0.5f, 0.5f,  // Top left (light gray)
        -20.f, -5.f,  3.f, 0.3f, 0.3f, 0.3f,  // Bottom left (dark gray)

        // Left face
        -20.f,  5.f,  3.f, 0.5f, 0.5f, 0.5f,   // Top front (light gray)
        -20.f,  5.f, -3.f, 0.5f, 0.5f, 0.5f,   // Top back (light gray)
        -20.f, -5.f, -3.f, 0.3f, 0.3f, 0.3f,  // Bottom back (dark gray)
        -20.f, -5.f, -3.f, 0.3f, 0.3f, 0.3f,  // Bottom back (dark gray)
        -20.f, -5.f,  3.f, 0.3f, 0.3f, 0.3f,  // Bottom front (dark gray)
        -20.f,  5.f,  3.f, 0.5f, 0.5f, 0.5f,   // Top front (light gray)

        // Right face
        20.f,  5.f,  3.f, 0.5f, 0.5f, 0.5f,   // Top front (light gray)
        20.f,  5.f, -3.f, 0.5f, 0.5f, 0.5f,   // Top back (light gray)
        20.f, -5.f, -3.f, 0.3f, 0.3f, 0.3f,  // Bottom back (dark gray)
        20.f, -5.f, -3.f, 0.3f, 0.3f, 0.3f,  // Bottom back (dark gray)
        20.f, -5.f,  3.f, 0.3f, 0.3f, 0.3f,  // Bottom front (dark gray)
        20.f,  5.f,  3.f, 0.5f, 0.5f, 0.5f,   // Top front (light gray)

        // Back face
        -20.f, -5.f, -3.f, 0.3f, 0.3f, 0.3f,  // Bottom left (dark gray)
        20.f, -5.f, -3.f, 0.3f, 0.3f, 0.3f,   // Bottom right (dark gray)
        20.f,  5.f, -3.f, 0.5f, 0.5f, 0.5f,   // Top right (light gray)
        20.f,  5.f, -3.f, 0.5f, 0.5f, 0.5f,   // Top right (light gray)
        -20.f,  5.f, -3.f, 0.5f, 0.5f, 0.5f,  // Top left (light gray)
        -20.f, -5.f, -3.f, 0.3f, 0.3f, 0.3f,  // Bottom left (dark gray)

        // Top face
        -20.f,  5.f,  3.f, 0.5f, 0.5f, 0.5f,  // Front left (light gray)
        20.f,  5.f,  3.f, 0.5f, 0.5f, 0.5f,   // Front right (light gray)
        20.f,  5.f, -3.f, 0.5f, 0.5f, 0.5f,   // Back right (light gray)
        20.f,  5.f, -3.f, 0.5f, 0.5f, 0.5f,   // Back right (light gray)
        -20.f,  5.f, -3.f, 0.5f, 0.5f, 0.5f,  // Back left (light gray)
        -20.f,  5.f,  3.f, 0.5f, 0.5f, 0.5f,  // Front left (light gray)

        // Bottom face
        -20.f, -5.f,  3.f, 0.3f, 0.3f, 0.3f,  // Front left (dark gray)
        20.f, -5.f,  3.f, 0.3f, 0.3f, 0.3f,   // Front right (dark gray)
        20.f, -5.f, -3.f, 0.3f, 0.3f, 0.3f,   // Back right (dark gray)
        20.f, -5.f, -3.f, 0.3f, 0.3f, 0.3f,   // Back right (dark gray)
        -20.f, -5.f, -3.f, 0.3f, 0.3f, 0.3f,  // Back left (dark gray)
        -20.f, -5.f,  3.f, 0.3f, 0.3f, 0.3f,  // Front left (dark gray)
    };

    const std::vector<float> Lines = {
        // Line 1
        // Front face
        -20.f,  3.5f,  3.f, 1.0f, 1.0f, 1.0f,
        -20.f,  2.5f,  3.f, 1.0f, 1.0f, 1.0f,
        -14.f,  2.5f,  3.f, 1.0f, 1.0f, 1.0f,
        -14.f,  2.5f,  3.f, 1.0f, 1.0f, 1.0f,
        -14.f,  3.5f,  3.f, 1.0f, 1.0f, 1.0f,
        -20.f,  3.5f,  3.f, 1.0f, 1.0f, 1.0f,

        // Back face
        -20.f,  3.5f, -3.f, 0.9f, 0.9f, 0.9f,
        -20.f,  2.5f, -3.f, 0.9f, 0.9f, 0.9f,
        -14.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        -14.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        -14.f,  3.5f, -3.f, 0.9f, 0.9f, 0.9f,
        -20.f,  3.5f, -3.f, 0.9f, 0.9f, 0.9f,

        // Right face
        -14.f,  3.5f,  3.f, 0.9f, 0.9f, 0.9f,
        -14.f,  2.5f,  3.f, 0.9f, 0.9f, 0.9f,
        -14.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        -14.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        -14.f,  3.5f, -3.f, 0.9f, 0.9f, 0.9f,
        -14.f,  3.5f,  3.f, 0.9f, 0.9f, 0.9f,

        // Left face
        -20.f,  3.5f,  3.f, 0.9f, 0.9f, 0.9f,
        -20.f,  2.5f,  3.f, 0.9f, 0.9f, 0.9f,
        -20.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        -20.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        -20.f,  3.5f, -3.f, 0.9f, 0.9f, 0.9f,
        -20.f,  3.5f,  3.f, 0.9f, 0.9f, 0.9f,

        // Top face
        -20.f,  3.5f,  3.f, 0.9f, 0.9f, 0.9f,
        -14.f,  3.5f,  3.f, 0.9f, 0.9f, 0.9f,
        -14.f,  3.5f, -3.f, 1.0f, 1.0f, 1.0f,
        -14.f,  3.5f, -3.f, 1.0f, 1.0f, 1.0f,
        -20.f,  3.5f, -3.f, 0.9f, 0.9f, 0.9f,
        -20.f,  3.5f,  3.f, 0.9f, 0.9f, 0.9f,

        // Bottom face
        -20.f,  2.5f,  3.f, 0.9f, 0.9f, 0.9f,
        -14.f,  2.5f,  3.f, 0.9f, 0.9f, 0.9f,
        -14.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        -14.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        -20.f,  2.5f, -3.f, 0.9f, 0.9f, 0.9f,
        -20.f,  2.5f,  3.f, 0.9f, 0.9f, 0.9f,

        // Line 2
        // Front face
        -8.f,  3.5f,  3.f, 1.0f, 1.0f, 1.0f,
        -8.f,  2.5f,  3.f, 1.0f, 1.0f, 1.0f,
        -2.f,  2.5f,  3.f, 1.0f, 1.0f, 1.0f,
        -2.f,  2.5f,  3.f, 1.0f, 1.0f, 1.0f,
        -2.f,  3.5f,  3.f, 1.0f, 1.0f, 1.0f,
        -8.f,  3.5f,  3.f, 1.0f, 1.0f, 1.0f,

        // Back face
        -8.f,  3.5f, -3.f, 0.9f, 0.9f, 0.9f,
        -8.f,  2.5f, -3.f, 0.9f, 0.9f, 0.9f,
        -2.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        -2.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        -2.f,  3.5f, -3.f, 0.9f, 0.9f, 0.9f,
        -8.f,  3.5f, -3.f, 0.9f, 0.9f, 0.9f,

        // Right face
        -2.f,  3.5f,  3.f, 0.9f, 0.9f, 0.9f,
        -2.f,  2.5f,  3.f, 0.9f, 0.9f, 0.9f,
        -2.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        -2.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        -2.f,  3.5f, -3.f, 0.9f, 0.9f, 0.9f,
        -2.f,  3.5f,  3.f, 0.9f, 0.9f, 0.9f,

        // Left face
        -8.f,  3.5f,  3.f, 0.9f, 0.9f, 0.9f,
        -8.f,  2.5f,  3.f, 0.9f, 0.9f, 0.9f,
        -8.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        -8.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        -8.f,  3.5f, -3.f, 0.9f, 0.9f, 0.9f,
        -8.f,  3.5f,  3.f, 0.9f, 0.9f, 0.9f,

        // Top face
        -8.f,  3.5f,  3.f, 0.9f, 0.9f, 0.9f,
        -2.f,  3.5f,  3.f, 0.9f, 0.9f, 0.9f,
        -2.f,  3.5f, -3.f, 1.0f, 1.0f, 1.0f,
        -2.f,  3.5f, -3.f, 1.0f, 1.0f, 1.0f,
        -8.f,  3.5f, -3.f, 0.9f, 0.9f, 0.9f,
        -8.f,  3.5f,  3.f, 0.9f, 0.9f, 0.9f,

        // Bottom face
        -8.f,  2.5f,  3.f, 0.9f, 0.9f, 0.9f,
        -2.f,  2.5f,  3.f, 0.9f, 0.9f, 0.9f,
        -2.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        -2.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        -8.f,  2.5f, -3.f, 0.9f, 0.9f, 0.9f,
        -8.f,  2.5f,  3.f, 0.9f, 0.9f, 0.9f,

        // Line 3
        // Front face
        4.f,  3.5f,  3.f, 1.0f, 1.0f, 1.0f,
        4.f,  2.5f,  3.f, 1.0f, 1.0f, 1.0f,
        10.f,  2.5f,  3.f, 1.0f, 1.0f, 1.0f,
        10.f,  2.5f,  3.f, 1.0f, 1.0f, 1.0f,
        10.f,  3.5f,  3.f, 1.0f, 1.0f, 1.0f,
        4.f,  3.5f,  3.f, 1.0f, 1.0f, 1.0f,

        // Back face
        4.f,  3.5f, -3.f, 0.9f, 0.9f, 0.9f,
        4.f,  2.5f, -3.f, 0.9f, 0.9f, 0.9f,
        10.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        10.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        10.f,  3.5f, -3.f, 0.9f, 0.9f, 0.9f,
        4.f,  3.5f, -3.f, 0.9f, 0.9f, 0.9f,

        // Right face
        10.f,  3.5f,  3.f, 0.9f, 0.9f, 0.9f,
        10.f,  2.5f,  3.f, 0.9f, 0.9f, 0.9f,
        10.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        10.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        10.f,  3.5f, -3.f, 0.9f, 0.9f, 0.9f,
        10.f,  3.5f,  3.f, 0.9f, 0.9f, 0.9f,

        // Left face
        4.f,  3.5f,  3.f, 0.9f, 0.9f, 0.9f,
        4.f,  2.5f,  3.f, 0.9f, 0.9f, 0.9f,
        4.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        4.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        4.f,  3.5f, -3.f, 0.9f, 0.9f, 0.9f,
        4.f,  3.5f,  3.f, 0.9f, 0.9f, 0.9f,

        // Top face
        4.f,  3.5f,  3.f, 0.9f, 0.9f, 0.9f,
        10.f,  3.5f,  3.f, 0.9f, 0.9f, 0.9f,
        10.f,  3.5f, -3.f, 1.0f, 1.0f, 1.0f,
        10.f,  3.5f, -3.f, 1.0f, 1.0f, 1.0f,
        4.f,  3.5f, -3.f, 0.9f, 0.9f, 0.9f,
        4.f,  3.5f,  3.f, 0.9f, 0.9f, 0.9f,

        // Bottom face
        4.f,  2.5f,  3.f, 0.9f, 0.9f, 0.9f,
        10.f,  2.5f,  3.f, 0.9f, 0.9f, 0.9f,
        10.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        10.f,  2.5f, -3.f, 1.0f, 1.0f, 1.0f,
        4.f,  2.5f, -3.f, 0.9f, 0.9f, 0.9f,
        4.f,  2.5f,  3.f, 0.9f, 0.9f, 0.9f,
    };

    const float PlayerSpeed = 7;
    const float EnemySpeed = 10;

    const glm::vec3 GrassBaseVec = glm::vec3(0.f, -3.65f, -12.f);
    const glm::vec3 RoadBaseVec = glm::vec3(0.f, -3.65f, -22.f);
    const glm::vec3 LineBaseVec =  glm::vec3(4.5f, -3.60f, -18.5f);

    const glm::vec3 EnemyEVec = glm::vec3(-18.f, 0.f, -44.f);
    const glm::vec3 EnemyWVec = glm::vec3(18.f, 0.f, -39.f);

    const float DepthOffset = -20.f;

}
