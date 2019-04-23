cmake_minimum_required (VERSION 3.1)
project (Linal)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Release)

FIND_PACKAGE(Boost COMPONENTS python)

include_directories(
    include
    )

file(GLOB SOURCES
    src/*.cpp
    # src/boostpy/*.cpp
    )

add_library(${PROJECT_NAME} SHARED ${SOURCES})

install(TARGETS ${PROJECT_NAME} DESTINATION /usr/local/lib)
