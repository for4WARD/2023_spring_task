cmake_minimum_required(VERSION 3.25)
project(project_spring_2023)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
add_executable(project_spring_2023 main.cpp Headers/Game.h Headers/Headquarters.h Headers/Warriors.h Sources/Game.cpp Sources/Headquarters.cpp Sources/Warrior.cpp Headers/Weapons.h Headers/City.h Headers/Map.h Sources/City.cpp Sources/Map.cpp)
