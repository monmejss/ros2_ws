import os 
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node 
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

# os - manejo de rutas de archivos
# LaunchDescription - define estructura del launch
# Node - para lanzar nodos en ROS 2
# DeclareLaunchArgument - define argumentos que pueden modificarse
# IncludeLaunchDescription - permite incluir otros launch
# PythonLaunchDescriptionSource - incluir launch escritos en Python
# get_package_share_directory - buscar paquetes dentro del ws


def generate_launch_description():
    pkg_xolobot_arm = get_package_share_directory('xolobot_arm')
    pkg_xolobot_control = get_package_share_directory('xolobot_control')
    
    # Cambia a ros_gz_sim para usar Ignition. Antes: gazebo_ros
    gazebo_ros_launch = os.path.join(get_package_share_directory('ros_gz_sim'), 'launch', 'gazebo.launch.py')
    
    # These are the arguments you can pass this launch file
    declared_arguments = [
        DeclareLaunchArgument('paused', default_value='false'),
        DeclareLaunchArgument('use_sim_time', default_value='true'),
        DeclareLaunchArgument('gui', default_value='true'),
        DeclareLaunchArgument('headless', default_value='false'),
        DeclareLaunchArgument('debug', default_value='false'),
    ]

    # Cargar el mundo coca_levitando.world
    gazebo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(gazebo_ros_launch),
        launch_arguments={
            'world': os.path.join(pkg_xolobot_arm, 'worlds', 'coca_levitando.world'),
            'paused': 'false',
            'use_sim_time': 'true',
            'gui': 'true',
            'headless': 'false',
            'debug': 'false'
        }.items(),
    )

    # Cargar la descripcion desde el URDF. Publicar para ros2 en robot_description
    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[{
            'robot_description': open(os.path.join(pkg_xolobot_arm, 'models', 'xolobot.urdf')).read()
        }]
    )
    
    # Nodo: spawn_sdf. Para el SDF
    sdf_spawner = Node(
        package='ros_gz_sim',
        executable='spawn_entity',
        output='screen',
        arguments=[
            '-file', os.path.join(pkg_xolobot_arm, 'models', 'xolobot_arm.sdf'),
            '-name', 'xolobot_arm',
            '-x', '0.5', '-y', '0.5', '-z', '0.52277'
        ]
    )

    # Load joint controller configurations from YAML file
    controller_spawner = Node(
        package='controller_manager',
        executable='spawner',
        output='screen',
        arguments=['--load', os.path.join(pkg_xolobot_control, 'config', 'xolobot_control.yaml')]
    )
    
    joint_state_broadcaster_node = Node(
        package='controller_manager',
        executable='spawner',
        output='screen',
        arguments=['joint_state_broadcaster']
    )

    return LaunchDescription(declared_arguments + [
        gazebo_launch,
        robot_state_publisher_node,
        joint_state_broadcaster_node,
        sdf_spawner,
        controller_spawner
    ])
