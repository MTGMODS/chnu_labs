cmake_minimum_required(VERSION 3.28)
project(laba3)

set(CMAKE_CXX_STANDARD 17)

add_executable(laba3 main.cpp
        Car.cpp
        Car.h
        Parking.h
        Parking.cpp)

# Set compiler flags for MinGW (if not set automatically)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++ -static -lpthread")
