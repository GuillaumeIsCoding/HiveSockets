add_executable(Sandbox-Server main.cpp)
target_include_directories(Sandbox-Server PRIVATE ${CMAKE_SOURCE_DIR}/HiveSockets/src)
target_link_libraries(Sandbox-Server HiveSockets)