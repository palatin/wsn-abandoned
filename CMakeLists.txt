cmake_minimum_required(VERSION 3.9)
project(WSN)

set(CMAKE_CXX_STANDARD 17)


set(DEBUG TRUE)





include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(WSN SHARED src/model/node/node.cpp include/model/node/node.h src/model/point.cpp include/model/point.h src/controller/wsn_controller.cpp
        include/controller/wsn_controller.h src/model/node/node_link.cpp include/model/node/node_link.h
        include/model/nodes.h include/util/geometry.h include/util/array_helper.h
        include/model/data/data.h src/model/data/command.cpp include/model/data/command.h
        src/model/data/event_message.cpp include/model/data/event_message.h src/model/data/loop_command.cpp include/model/data/loop_command.h src/model/data/data.cpp
        include/protocol/network_protocol.h include/controller/physics/physics_controller.h src/util/euclid_geometry.cpp include/util/euclid_geometry.h
        include/controller/physics/first_order_model_physics_controller.h src/model/node/radio_node.cpp include/model/node/radio_node.h src/notification/notification_center.cpp
        include/notification/notification_center.h include/notification/observer.h include/notification/event/event.h include/core/wsn_component.h
        include/notification/event/node_death_event.h src/notification/event/node_death_event.cpp include/factory/nodes_factory.h src/factory/random_location_nodes_factory.cpp
        include/factory/random_location_nodes_factory.h)

set_target_properties(WSN PROPERTIES PREFIX "")

if(DEBUG)
    enable_testing()
    add_subdirectory(test)
endif()
