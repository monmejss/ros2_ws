cmake_minimum_required(VERSION 3.8)
project(xolobot_arm)

find_package(ament_cmake REQUIRED)
find_package(robot_state_publisher REQUIRED)
find_package(gazebo_ros REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(ros2_control REQUIRED)
find_package(control_msgs REQUIRED)
find_package(controller_manager REQUIRED)


find_package(ros2_controllers REQUIRED)
find_package(gazebo_ros2_control REQUIRED)

install(
  DIRECTORY
    launch
    worlds
    models
  DESTINATION share/${PROJECT_NAME}
)


ament_package()
