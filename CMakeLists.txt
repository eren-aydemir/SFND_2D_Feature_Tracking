cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(camera_fusion)

find_package(OpenCV 4.1 REQUIRED)
find_package(Boost 1.72.0 REQUIRED COMPONENTS program_options system thread)

message("Boost dirs: ${Boost_LIBRARY_DIRS} ${Boost_INCLUDE_DIRS}")
message("Boost libraries ${Boost_LIBRARIES}")

include_directories(${OpenCV_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
#link_directories(${OpenCV_LIBRARY_DIRS})
#add_definitions(${OpenCV_DEFINITIONS})

# Executable for create matrix exercise
add_executable (2D_feature_tracking src/matching2D_Student.cpp src/MidTermProject_Camera_Student.cpp)
target_link_libraries (2D_feature_tracking ${OpenCV_LIBRARIES} ${Boost_LIBRARIES})