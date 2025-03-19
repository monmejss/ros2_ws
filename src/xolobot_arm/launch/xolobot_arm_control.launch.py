import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_xolobot_arm = get_package_share_directory('xolobot_arm')

    return LaunchDescription([
        Node(
            package='ros_gz_sim',
            executable='gz_sim',
            arguments=['-r', os.path.join(pkg_xolobot_arm, 'worlds', 'xolobot.world')],
            output='screen'),

        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            parameters=[{'robot_description': os.path.join(pkg_xolobot_arm, 'models', 'xolobot.urdf')}],
            output='screen'),

        Node(
            package='controller_manager',
            executable='ros2_control_node',
            parameters=[os.path.join(pkg_xolobot_arm, 'config', 'xolobot_control.yaml')],
            output='screen'),

        Node(
            package='controller_manager',
            executable='spawner',
            arguments=['arm_controller'],
            output='screen'),

        Node(
            package='controller_manager',
            executable='spawner',
            arguments=['joint_state_broadcaster'],
            output='screen'),
    ])
