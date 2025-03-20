import os
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_xolobot_arm = get_package_share_directory('xolobot_arm')
    pkg_xolobot_control = get_package_share_directory('xolobot_control')

    sdf_file = os.path.join(pkg_xolobot_arm, 'models', 'xolobot_arm.sdf')
    world_file = os.path.join(pkg_xolobot_arm, 'worlds', 'coca_levitando.world')
    urdf_file = os.path.join(pkg_xolobot_arm, 'models', 'xolobot.urdf')
    
    with open(urdf_file, 'r') as file:
        robot_description_content = file.read()

    gazebo_ros_launch = os.path.join(get_package_share_directory('ros_gz_sim'), 'launch', 'gz_sim.launch.py')

    return LaunchDescription([
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(gazebo_ros_launch),
            launch_arguments={'world': world_file}.items()
        ),
        
        Node(
            package='ros_gz_sim',
            executable='create',
            arguments=['-file', sdf_file, '-name', 'xolobot_arm', '-topic', '/robot_description'],
            output='screen'
        ),
        
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            parameters=[{'robot_description': robot_description_content}],
            output='screen'
        ),

        Node(
            package='controller_manager',
            executable='ros2_control_node',
            parameters=[{os.path.join(pkg_xolobot_control, 'config', 'xolobot_control.yaml')}, 
                        {'hardware_interface': 'gz_ros2_control/GazeboSystemInterface'}],
            output='screen'
        ),
        
        Node(
            package='controller_manager',
            executable='spawner',
            arguments=['arm_controller'],
            output='screen'
        ),
        
        Node(
            package='controller_manager',
            executable='spawner',
            arguments=['joint_state_broadcaster'],
            output='screen'
        ),
    ])
