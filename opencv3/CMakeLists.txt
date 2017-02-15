cmake_minimum_required(VERSION 3.5)
project(opencv3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_INCLUDE_CURRENT_DIR on)
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_AUTOMOC on)
set(CMAKE_AUTORCC on)

find_package(Qt5Widgets)
find_package(OpenCV)


set(SOURCE_FILES main.cpp)
add_executable(opencv3 ${SOURCE_FILES})
target_link_libraries(opencv3 Qt5::Widgets)
target_link_libraries(opencv3 ${OpenCV_LIBS})