cmake_minimum_required(VERSION 3.9)
project(WSNEmulator)

set(CMAKE_CXX_STANDARD 17)


add_library(WSNEmulator SHARED src/library.cpp src/library.h src/network/model/node.cpp src/network/model/node.h src/network/model/point.cpp src/network/model/point.h src/network/model/node_types.h src/network/controller/wsn_controller.cpp src/network/controller/wsn_controller.h src/network/controller/plot_controller.cpp src/network/controller/plot_controller.h)

add_executable(test_ex src/library.cpp src/network/model/node.cpp src/network/model/node.h src/network/model/point.cpp src/network/model/point.h src/network/model/node_types.h src/network/controller/wsn_controller.cpp src/network/controller/wsn_controller.h src/network/controller/plot_controller.cpp src/network/controller/plot_controller.h)