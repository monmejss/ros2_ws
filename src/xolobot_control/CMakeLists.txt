cmake_minimum_required(VERSION 3.8)
project(xolobot_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


find_package(rclcpp REQUIRED)
find_package(controller_manager REQUIRED)
find_package(joint_state_controller REQUIRED)
find_package(robot_state_publisher REQUIRED)
find_package(fmt REQUIRED)


include_directories(
   include
)

ament_target_dependencies(xolobot_control
  rclcpp
  controller_manager
  joint_state_controller
  robot_state_publisher
  fmt
)

install(TARGETS xolobot_control
  DESTINATION lib/${PROJECT_NAME}
)
ament_package()
