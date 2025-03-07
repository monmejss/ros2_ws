cmake_minimum_required(VERSION 3.8)
project(xolobot_arm_server)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(fmt REQUIRED)

include_directories(
   include
)

add_executable(xolobot_arm_server
	src/startServerNode.cpp
	src/SimulationController.cpp
)
	
target_link_libraries(xolobot_arm_server
  rclcpp::rclcpp
  fmt::fmt
)
install(TARGETS xolobot_arm_server
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION include/${PROJECT_NAME}
  FILES_MATCHING PATTERN "*.hpp"
) 

ament_target_dependencies(xolobot_arm_server
  rclcpp
  std_msgs
  fmt
)


ament_package()