cmake_minimum_required(VERSION 3.8)
project(xolobot_control)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(ros2_control REQUIRED)
find_package(ros2_controllers REQUIRED)
find_package(controller_manager REQUIRED)
find_package(gazebo_ros REQUIRED)
find_package(gazebo_ros2_control REQUIRED)

install(DIRECTORY config launch
  DESTINATION share/${PROJECT_NAME}
)

ament_export_dependencies(rclcpp std_msgs sensor_msgs geometry_msgs ros2_control ros2_controllers controller_manager gazebo_ros gazebo_ros2_control)
ament_package()
