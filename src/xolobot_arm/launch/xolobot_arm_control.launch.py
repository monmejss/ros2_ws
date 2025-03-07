import os
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_xolobot_arm = get_package_share_directory('xolobot_arm')
    pkg_xolobot_control = get_package_share_directory('xolobot_control')
    gazebo_ros_launch = os.path.join(get_package_share_directory('gazebo_ros'), 'launch', 'gazebo.launch.py')
    
    # Argumentos de la simulación
    declared_arguments = [
        DeclareLaunchArgument('paused', default_value='false'),
        DeclareLaunchArgument('use_sim_time', default_value='true'),
        DeclareLaunchArgument('gui', default_value='true'),
        DeclareLaunchArgument('headless', default_value='false'),
        DeclareLaunchArgument('debug', default_value='false'),
    ]

    # Incluye el launch de Gazebo Ignition
    gazebo = IncludeLaunchDescription(
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

    # Publicador del estado del robot
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[{
            'robot_description': open(os.path.join(pkg_xolobot_arm, 'models', 'xolobot.urdf')).read()
        }]
    )

    # Spawner URDF
    urdf_spawner = Node(
        package='gazebo_ros',
        executable='spawn_model',
        output='screen',
        arguments=[
            '-urdf',
            '-param', 'robot_description',
            '-model', 'xolobot_arm_j',
            '-x', '0.5', '-y', '0.5', '-z', '0.52277'
        ]
    )

    # Spawner SDF usando Gazebo Ignition
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

    # Cargar configuraciones de controladores desde YAML
    controller_spawner = Node(
        package='controller_manager',
        executable='spawner',
        output='screen',
        parameters=[os.path.join(pkg_xolobot_control, 'config', 'xolobot_control.yaml')]
    )

    return LaunchDescription(declared_arguments + [
        gazebo,
        robot_state_publisher,
        urdf_spawner,
        sdf_spawner,
        controller_spawner
    ])
