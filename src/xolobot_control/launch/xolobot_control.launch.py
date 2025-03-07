import os
import launch
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, LogInfo, IncludeLaunchDescription, PushRosNamespace
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration, ThisLaunchFileDir

def generate_launch_description():
    return LaunchDescription([
        # Cargar los parámetros desde un archivo YAML
        Node(
            package='rosparam',
            executable='rosparam',
            name='load_joint_params',
            output='screen',
            arguments=['load', os.path.join(
                ThisLaunchFileDir(), '..', 'config', 'xolobot_control.yaml')],
        ),
        
        # Cargar los controladores con el controlador del gestor de controladores
        Node(
            package='controller_manager',
            executable='spawner',
            name='controller_spawner',
            respawn=False,
            output='screen',
            arguments=[
                'joint_state_controller', 
                'joint1_position_controller',
                'joint2_position_controller', 
                'joint3_position_controller', 
                'joint4_position_controller', 
                'joint5_position_controller', 
                'joint6_position_controller'
            ],
            namespace='xolobot_arm'
        ),
        
        # Publicar las transformaciones TF de las articulaciones en RViz, etc.
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            respawn=False,
            output='screen',
            remappings=[('/joint_states', '/xolobot_arm/joint_states')]
        ),
    ])
