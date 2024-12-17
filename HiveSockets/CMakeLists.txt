set(CMAKE_CXX_STANDARD 20)

if (DEFINED ENV{VCPKG_ROOT})
    message(STATUS "VCPKG_ROOT: $ENV{VCPKG_ROOT}")
    if (DEFINED ENV{VCPKG_TARGET_TRIPLET})
        message(VERBOSE "VCPKG_TARGET_TRIPLET: $ENV{VCPKG_TARGET_TRIPLET}")
        set(VCPKG_TARGET_TRIPLET "$ENV{VCPKG_TARGET_TRIPLET}")
    endif()
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
endif()

# Dependencies
add_subdirectory(dep/sockets)
add_subdirectory(dep/HiveCore)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.h)

add_library(HiveSockets ${SOURCES})
target_link_libraries(HiveSockets GameNetworkingSockets HiveCore)
target_include_directories(HiveSockets PRIVATE src)

target_include_directories(HiveSockets PRIVATE dep/sockets/src)
target_include_directories(HiveSockets PRIVATE dep/HiveCore/HiveCore/src)

# Precompiled header file
target_precompile_headers(HiveSockets PRIVATE src/hvpch.h)