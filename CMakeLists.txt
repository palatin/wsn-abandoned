cmake_minimum_required(VERSION 3.9)
project(WSN)

set(CMAKE_CXX_STANDARD 17)


set(DEBUG TRUE)


enable_testing()




add_library(WSN SHARED src/network/model/node/node.cpp src/network/model/node/node.h src/network/model/point.cpp src/network/model/point.h src/network/controller/wsn_controller.cpp
        src/network/controller/wsn_controller.h src/network/model/node/node_link.cpp src/network/model/node/node_link.h
        src/network/model/nodes.h src/network/util/geometry.h src/network/util/array_helper.h
        src/network/model/data/data.h src/network/model/data/command.cpp src/network/model/data/command.h
        src/network/model/data/event_message.cpp src/network/model/data/event_message.h src/network/model/data/loop_command.cpp src/network/model/data/loop_command.h src/network/model/data/data.cpp
        src/network/protocol/network_protocol.h src/network/controller/physics/physics_controller.h src/network/util/euclid_geometry.cpp src/network/util/euclid_geometry.h
        src/network/controller/physics/first_order_model_physics_controller.h src/network/model/node/radio_node.cpp src/network/model/node/radio_node.h src/network/notification/notification_center.cpp src/network/notification/notification_center.h src/network/notification/observer.h src/network/notification/event.h src/network/core/wsn_component.h)

set_target_properties(WSN PROPERTIES PREFIX "")

if(DEBUG)
    add_subdirectory(test)
endif()
