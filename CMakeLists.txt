cmake_minimum_required(VERSION 3.15)
project(dcmtk_sample)

set(CMAKE_CXX_STANDARD 14)

if (APPLE)
    set(CMAKE_CXX_COMPILER "/usr/bin/clang++" CACHE STRING "clang++ compiler" FORCE)
endif()

add_definitions(-DHAVE_CONFIG_H)

find_package(DCMTK REQUIRED)

include_directories(${DCMTK_INCLUDE_DIRS})

add_executable(dcmtk_sample main.cpp)

target_link_libraries(dcmtk_sample ${DCMTK_LIBRARIES})
