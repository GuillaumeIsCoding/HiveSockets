add_executable(Sandbox-Client main.cpp)
target_include_directories(Sandbox-Client PRIVATE ${CMAKE_SOURCE_DIR}/HiveSockets/src)
target_link_libraries(Sandbox-Client HiveSockets)