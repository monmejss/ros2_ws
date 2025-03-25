cmake_minimum_required(VERSION 3.8)
project(xolobot_arm_server)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(fmt REQUIRED)
find_package(ros_ign_interfaces REQUIRED)


include_directories(include)

add_executable(xolobot_arm_server
  src/startServerNode.cpp
  src/SimulationController.cpp
)

ament_target_dependencies(xolobot_arm_server
  rclcpp
  std_msgs
  fmt
  ros_ign_interfaces
)


target_include_directories(xolobot_arm_server PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)


install(TARGETS xolobot_arm_server
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
  DESTINATION include/
  FILES_MATCHING PATTERN "*.h"
)

ament_package()
