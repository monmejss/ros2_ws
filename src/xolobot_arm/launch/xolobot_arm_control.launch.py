import os
from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

from launch.actions import LogInfo, ExecuteProcess

def generate_launch_description():
    # Paquetes necesarios
    package_name1 = "xolobot_arm"
    package_name2 = "xolobot_control"
    
    # coca_levitando.world
    world_path = os.path.join(
        FindPackageShare(package_name1).find(package_name1), 
        "worlds", "coca_levitando.world"
    )
    
    # xolobot_control.yaml
    config_path = os.path.join(
        FindPackageShare(package_name2).find(package_name2), 
        "config", "xolobot_control.yaml"
    )
    
    # xolobot_arm.sdf
    #sdf_path = os.path.join(
    #    FindPackageShare(package_name1).find(package_name1), 
    #    "models", "xolobot_arm.sdf"
    #)
    
    # xolobot.urdf
    urdf_path = os.path.join(
        FindPackageShare(package_name1).find(package_name1), 
        "models", "xolobot.urdf"
    )
    
    # Iniciar Gazebo Ignition con el modelo SDF
    gazebo_launch = ExecuteProcess(
        cmd=['ign', 'gazebo', world_path, '-v', '4', '--gui'],
        output='screen'
    )
    
    #spawn_robot = ExecuteProcess(
    #    cmd=[
    #        'ros2', 'run', 'ros_gz_sim', 'create',
    #        '-file', sdf_path,
    #        '-name', 'xolobot_arm',
    #        '-x', '0.5', '-y', '0.5', '-z', '0.52277'
    #    ],
    #    output='screen'
    #)
        
    with open(urdf_path, 'r') as file:
        descripcion_xolobot = file.read()

    return LaunchDescription([
        gazebo_launch,
        #spawn_robot,
        
        # Este nodo utiliza la descripcion del URDF
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            parameters=[{'robot_description': descripcion_xolobot}],
            output='screen'
        ),
        
        Node(
            package='controller_manager',
            executable='ros2_control_node',
            parameters=[{config_path}],
            output='screen'
        ),
        
        ExecuteProcess(
            cmd=['ros2', 'control', 'load_controller', '--set-state', 'active', 'joint_trajectory_controller'],
            output='screen'
        ),
        
        ExecuteProcess(
            cmd=['ros2', 'control', 'load_controller', '--set-state', 'active', 'joint_state_broadcaster'],
            output='screen'
        ),
    ])