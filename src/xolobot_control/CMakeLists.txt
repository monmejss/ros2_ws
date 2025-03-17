cmake_minimum_required(VERSION 3.8)
project(xolobot_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(controller_manager REQUIRED)
find_package(joint_state_broadcaster REQUIRED)
find_package(robot_state_publisher REQUIRED)
find_package(trajectory_msgs REQUIRED)
find_package(fmt REQUIRED)

find_package(ros2_controllers REQUIRED)
find_package(ros2_control REQUIRED)
find_package(gazebo_ros2_control REQUIRED)

find_package(gazebo_ros REQUIRED)
find_package(hardware_interface REQUIRED)

find_package(controller_interface REQUIRED)


install(
  DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
