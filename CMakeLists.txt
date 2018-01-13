cmake_minimum_required(VERSION 3.9)
project(WSN)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)


add_library(WSN SHARED src/network/core/wsn.cpp src/network/model/node/node.cpp src/network/model/node/node.h src/network/model/point.cpp src/network/model/point.h src/network/controller/wsn_controller.cpp
        src/network/controller/wsn_controller.h src/network/model/node/node_link.cpp src/network/model/node/node_link.h src/network/controller/linker/wsn_linker_controller.h
        lib/di/di.hpp src/network/model/nodes.cpp src/network/model/nodes.h src/network/controller/linker/cluster_tree_linker/wsn_cluster_tree_linker_controller.cpp src/network/controller/linker/cluster_tree_linker/wsn_cluster_tree_linker_controller.h src/network/util/geometry.cpp src/network/util/geometry.h src/network/util/array_helper.h src/network/controller/linker/cluster_tree_linker/clustering_controller.h src/network/model/data/data.h src/network/model/data/command.cpp src/network/model/data/command.h src/network/model/data/event_message.cpp src/network/model/data/event_message.h src/network/model/data/loop_command.cpp src/network/model/data/loop_command.h)

add_executable(test_ex src/network/core/wsn.cpp src/network/model/node/node.cpp src/network/model/node/node.h src/network/model/point.cpp src/network/model/point.h src/network/controller/wsn_controller.cpp
        src/network/controller/wsn_controller.h src/network/model/node/node_link.cpp src/network/model/node/node_link.h src/network/controller/linker/wsn_linker_controller.h
        lib/di/di.hpp src/network/model/nodes.cpp src/network/model/nodes.h src/network/controller/linker/cluster_tree_linker/wsn_cluster_tree_linker_controller.cpp src/network/controller/linker/cluster_tree_linker/wsn_cluster_tree_linker_controller.h src/network/util/geometry.cpp src/network/util/geometry.h src/network/util/array_helper.h src/network/controller/linker/cluster_tree_linker/clustering_controller.h src/network/model/data/data.h src/network/model/data/command.cpp src/network/model/data/command.h src/network/model/data/event_message.cpp src/network/model/data/event_message.h src/network/model/data/loop_command.cpp src/network/model/data/loop_command.h)