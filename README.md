# Brazo robótico antropomórfico 🦾
## Comandos
### Para lanzar el mundo - ejecutar 
1. colcon build
2. source install/setup.bash
3. ros2 launch xolobot_arm xolobot_arm_control.launch.py
4. ros2 run xolobot_arm_server xolobot_arm_server

### Para escuchar tópicos
1. ros2 topic echo /bumper_states

### Para ver los controladores disponibles
1. ros2 control list_controllers

### Para matar procesos
1. pkill -9 gzserver
2. pkill -9 gzclient
3. pkill -9 gazebo

