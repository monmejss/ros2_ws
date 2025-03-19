cmake_minimum_required(VERSION 3.8)
project(xolobot_arm_server)

# Encontrar paquetes de ROS 2 necesarios
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(action_msgs REQUIRED)
find_package(gazebo_msgs REQUIRED)  
find_package(ros2_control REQUIRED)
find_package(ros2_controllers REQUIRED)
find_package(controller_manager REQUIRED)

# Agregar directorio de include
include_directories(include)

# Crear una biblioteca para SimulationController
add_library(simulation_controller_lib src/SimulationController.cpp)
ament_target_dependencies(simulation_controller_lib rclcpp std_msgs sensor_msgs geometry_msgs gazebo_msgs)

# Agregar el ejecutable start_server_node y vincularlo con la biblioteca SimulationController
add_executable(start_server_node src/startServerNode.cpp)
target_link_libraries(start_server_node simulation_controller_lib)
ament_target_dependencies(start_server_node rclcpp std_msgs sensor_msgs geometry_msgs gazebo_msgs)

# Instalar los ejecutables
install(TARGETS
  start_server_node
  DESTINATION lib/${PROJECT_NAME}
)

# Instalar los directorios necesarios (Si existen)
install(DIRECTORY launch config
  DESTINATION share/${PROJECT_NAME}
  OPTIONAL
)

# Exportar dependencias correctamente
ament_export_dependencies(rclcpp std_msgs sensor_msgs geometry_msgs gazebo_msgs ros2_control ros2_controllers controller_manager)

ament_package()
