from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="xolobot_arm_server",  # Nombre del paquete
            executable="xolobot_arm_server",  # Nombre del ejecutable
            name="arm_server",  # Nombre del nodo
            output="screen"  # Para ver mensajes en la terminal
        )
    ])
