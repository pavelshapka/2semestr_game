cmake_minimum_required(VERSION 3.20)
project(2semestr)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")


set(SOURCE_FILES main.cpp tApplication.cpp tApplication.h tMap.cpp tMap.h)
add_executable(2semestr ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(2semestr sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
