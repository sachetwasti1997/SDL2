cmake_minimum_required(VERSION 3.28)
project(SDLIntro)

find_package(SDL2 REQUIRED)
include_directories (${SDL2_INCLUDE_DIRS})
include_directories(SYSTEM ./utils ./Graphics)

set(CMAKE_CXX_STANDARD 17)

add_executable(SDLIntro main.cpp
        Graphics/Color.h
        Graphics/Color.cpp
        Graphics/ScreenBuffer.cpp
        Graphics/ScreenBuffer.h
        Graphics/Screen.h
        Graphics/Screen.cpp
        utils/Vec2D.cpp
        utils/Vec2D.h
        utils/Utils.h
        utils/Utils.cpp)
target_link_libraries(SDLIntro ${SDL2_LIBRARIES})