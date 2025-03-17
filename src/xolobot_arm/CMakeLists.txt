cmake_minimum_required(VERSION 3.8)
project(xolobot_arm)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(gazebo_ros REQUIRED)
find_package(ros2_control REQUIRED)
find_package(hardware_interface REQUIRED)
find_package(controller_manager REQUIRED)
find_package(robot_state_publisher REQUIRED)

find_package(controller_interface REQUIRED)

find_package(gz_ros2_control REQUIRED)


install(
  DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/
)

install(
  DIRECTORY models/
  DESTINATION share/${PROJECT_NAME}/models
)

install(
  DIRECTORY worlds/
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
