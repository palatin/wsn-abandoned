cmake_minimum_required(VERSION 3.9)
project(WSN)

set(CMAKE_CXX_STANDARD 17)


add_library(WSN SHARED src/network/core/wsn.cpp src/network/model/node.cpp src/network/model/node.h src/network/model/point.cpp src/network/model/point.h src/network/controller/wsn_controller.cpp
        src/network/controller/wsn_controller.h src/network/model/node_link.cpp src/network/model/node_link.h src/network/controller/wsn_path_controller.cpp src/network/controller/wsn_path_controller.h
        lib/di/di.hpp)

add_executable(test_ex src/network/core/wsn.cpp src/network/model/node.cpp src/network/model/node.h src/network/model/point.cpp src/network/model/point.h src/network/controller/wsn_controller.cpp
        src/network/controller/wsn_controller.h src/network/model/node_link.cpp src/network/model/node_link.h src/network/controller/wsn_path_controller.cpp src/network/controller/wsn_path_controller.h
        lib/di/di.hpp)