cmake_minimum_required(VERSION 3.10)
project(${PROJECT_NAME} CrossyRoadGL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} 
    src/Main.cpp
    src/glad.c
    src/Game.cpp
    src/Shader.cpp
    src/Level.cpp
    src/Entity.cpp
    src/Element.cpp
    src/Levelelement.cpp
    src/Player.cpp
    src/Enemy.cpp
    src/Camera.cpp
    src/stb_image.cpp
    src/TextureManager.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/GLFW
    ${CMAKE_CURRENT_SOURCE_DIR}/include/glad
    ${CMAKE_CURRENT_SOURCE_DIR}/include/glm
    ${CMAKE_CURRENT_SOURCE_DIR}/include/stb_image
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/libglfw3dll.a
)

if (WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE opengl32)
elseif (APPLE)
    find_library(COCOA_LIBRARY Cocoa REQUIRED)
    find_library(OpenGL_LIBRARY OpenGL REQUIRED)
    find_library(IOKIT_LIBRARY IOKit REQUIRED)
    find_library(COREVIDEO_LIBRARY CoreVideo REQUIRED)
    target_link_libraries(OpenGLProject PRIVATE ${COCOA_LIBRARY} ${OpenGL_LIBRARY} ${IOKIT_LIBRARY} ${COREVIDEO_LIBRARY})
else ()
    find_package(OpenGL REQUIRED)
    target_link_libraries(OpenGLProject PRIVATE ${OPENGL_gl_LIBRARY})
    find_package(X11 REQUIRED)
    target_link_libraries(OpenGLProject PRIVATE ${X11_LIBRARIES})
endif()