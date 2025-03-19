import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_xolobot_control = get_package_share_directory('xolobot_control')

    return LaunchDescription([
        Node(
            package='controller_manager',
            executable='ros2_control_node',
            parameters=[os.path.join(pkg_xolobot_control, 'config', 'xolobot_control.yaml')],
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
