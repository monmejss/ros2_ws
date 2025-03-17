import os 
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node 
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, ExecuteProcess, RegisterEventHandler
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.event_handlers import OnProcessExit

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
    gazebo_ros_launch = os.path.join(get_package_share_directory('ros_gz_sim'), 'launch', 'gz_sim.launch.py')
        
    # Argumentos que puedes pasar a este archivo de lanzamiento
    declared_arguments = [
        DeclareLaunchArgument('paused', default_value='false', description='Whether to start the simulation paused'),
        DeclareLaunchArgument('use_sim_time', default_value='true', description='Use simulation time'),
        DeclareLaunchArgument('gui', default_value='true', description='Whether to start Gazebo with GUI'),
        DeclareLaunchArgument('headless', default_value='false', description='Whether to start Gazebo in headless mode'),
        DeclareLaunchArgument('debug', default_value='false', description='Whether to enable debug mode'),
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

    urdf_file = os.path.join(pkg_xolobot_arm, 'models', 'xolobot.urdf')
    with open(urdf_file, 'r') as file:
        robot_description_content = file.read()

    # Cargar la descripción desde el URDF. Publicar para ros2 en robot_description
    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[{"robot_description": robot_description_content}]
    )
    
    # Nodo: spawn_sdf. Para el SDF
    sdf_spawner = Node(
        package='ros_gz_sim',
        # Se cambia de spawn_entity a create porque así se llama en esta versión de Gazebo
        executable='create',
        output='screen',
        arguments=[
            '-file', os.path.join(pkg_xolobot_arm, 'models', 'xolobot_arm.sdf'),
            '-name', 'xolobot_arm',
            '-x', '0.5', '-y', '0.5', '-z', '0.52277'
        ]
    )

    # Nodo: Para cargar los controladores desde el archivo YAML
    control_params = os.path.join(pkg_xolobot_control, 'config', 'xolobot_control.yaml')
    controller_manager = Node(
        package='controller_manager',
        executable='ros2_control_node',
        parameters=[
            {"use_sim_time": True},
            control_params, 
            {'hardware_interface': 'gazebo_ros2_control/GazeboSystemInterface'},
        ],
        output='screen'
    )

    # Cargar configuraciones de controladores de articulaciones desde el YAML
    load_trajectory_controller = ExecuteProcess(
        cmd=['ros2', 'control', 'load_controller', '--set-state', 'active', 'joint_trajectory_controller'],
        output='screen'
    )
    
    # Nodo para el "joint_state_broadcaster"
    load_joint_state_broadcaster = ExecuteProcess(
        cmd=['ros2', 'control', 'load_controller', '--set-state', 'active', 'joint_state_broadcaster'],
        output='screen'
    )
    
    event_handler_joint_state = RegisterEventHandler(
        event_handler=OnProcessExit(
            target_action=sdf_spawner,
            on_exit=[load_joint_state_broadcaster],
        )
    )

    event_handler_trajectory = RegisterEventHandler(
        event_handler=OnProcessExit(
            target_action=load_joint_state_broadcaster,
            on_exit=[load_trajectory_controller],
        )
    )

    # Retorna la LaunchDescription con los nodos
    return LaunchDescription(declared_arguments + [
        gazebo_launch,
        robot_state_publisher_node,
        sdf_spawner,
        controller_manager,
        event_handler_joint_state,
        event_handler_trajectory
    ])
