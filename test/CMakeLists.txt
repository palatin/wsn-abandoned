# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/test/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/test/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/test/googletest-build
        EXCLUDE_FROM_ALL)


include_directories("${gtest_SOURCE_DIR}/include")


#test linking area

set(node_test_source model/node/node_test.cpp)
set(physics_controller_test_source controller/physics_controller_test.cpp)
set(euclid_geometry_test_source util/euclid_geometry_test.cpp)
set(nodes_test_source model/nodes_test.cpp)
set(notification_test_source notification/notification_test.cpp)
set(wsn_controller_test_source controller/wsn_controller_test.cpp)
set(random_location_nodes_factory factory/random_nodes_factory_test.cpp)
set(array_helper_source util/array_helper_test.cpp)
add_executable(tests ${node_test_source}
                     ${physics_controller_test_source}
                     ${euclid_geometry_test_source}
                     ${nodes_test_source}
                     ${notification_test_source}
                     ${wsn_controller_test_source}
                     ${random_location_nodes_factory}
                     ${array_helper_source})
target_link_libraries(tests gtest gmock WSN)
