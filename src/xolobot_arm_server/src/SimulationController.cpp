#include "SimulationController.h"
#include "std_msgs/msg/float64.hpp"
#include <random>
#include "gazebo_msgs/msg/contacts_state.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory_point.hpp"

SimulationController::SimulationController() : rclcpp::Node("simulation_controller"){
    // Inicializar los límites de las articulaciones (en radianes)

    jointLimits = {{-0.5, 0.5},  // jnt_pecho_hombro
                   {-1.0, 1.0},  // jnt_hombro_hombro
                   {-0.5, 0.5},  // jnt_hombro_biceps
                   {-0.5, 0.5},  // jnt_biceps_codo
                   {-1.0, 1.0},  // jnt_codo_antebrazo
                   {-1.0, 1.0},  // jnt_antebrazo_palma
                   {-1.0, 1.0},  // jnt_palma_pulgar_1 (6)
                   {-1.0, 1.0},  // jnt_pulgar_1_2
                   {-1.0, 1.0},  // jnt_pulgar_2_3
                   {-1.0, 1.0},  // jnt_palma_indice_1
                   {-1.0, 1.0},  // jnt_indice_1_2
                   {-1.0, 1.0},  // jnt_indice_2_3
                   {-1.0, 1.0},  // jnt_palma_cordial_1
                   {-1.0, 1.0},  // jnt_cordial_1_2
                   {-1.0, 1.0},  // jnt_cordial_2_3
                   {-1.0, 1.0},  // jnt_palma_anular_1
                   {-1.0, 1.0},  // jnt_anular_1_2
                   {-1.0, 1.0},  // jnt_anular_2_3
                   {-1.0, 1.0}   // jnt_palma_menique_1
                   {-1.0, 1.0},  // jnt_menique_1_2
                   {-1.0, 1.0}}; // jnt_menique_2_3
                   
    // Inicializar valores por defecto
    jointValues.assign(TOTAL_JOINTS, 0.0);

    // Publicador para trayectoria completa
    jointTrajectoryPub = this->create_publisher<trajectory_msgs::msg::JointTrajectory>("/joint_trajectory_controller/joint_trajectory", 10);

    // Suscriptor para bumper
    suscriptorPalma = this ->create_subscription<gazebo_msgs::msg::ContactsState>
        ("/bumper_states_palma", rclcpp::SensorDataQoS(), std::bind(&SimulationController::deteccionColision, this, std::placeholders::_1));

    // Suscriptor para bumper
    suscriptorAntebrazo= this ->create_subscription<gazebo_msgs::msg::ContactsState>
        ("/bumper_states_antebrazo", rclcpp::SensorDataQoS(), std::bind(&SimulationController::deteccionColision, this, std::placeholders::_1));
    
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(700),
        std::bind(&SimulationController::startTrajectory, this));

    rclcpp::Rate wait_rate(1.0);
    wait_rate.sleep();
    
}
SimulationController::~SimulationController() {}

void SimulationController::deteccionColision(const gazebo_msgs::msg::ContactsState::SharedPtr msg){
    if(!msg->states.empty() && !colisionDetectada){
        colisionDetectada = true;
        RCLCPP_WARN(this->get_logger(),"¡Colision detectada!");
    }
}

void SimulationController::startTrajectory(){
    RCLCPP_INFO(this->get_logger(), "Iniciando simulacion");
    generaAleatorios(); 
}

void SimulationController::generaAleatorios(){
    std::random_device rd;
    std::mt19937 gen(rd());
    rclcpp::Rate rate(2.0);
    
    trajectory_msgs::msg::JointTrajectory jointTrajectoryMsg;
    jointTrajectoryMsg.joint_names = {"jnt_pecho_hombro", "jnt_hombro_hombro", "jnt_hombro_biceps", 
        "jnt_biceps_codo", "jnt_codo_antebrazo", "jnt_antebrazo_palma", 
        "jnt_palma_pulgar_1", "jnt_pulgar_1_2", "jnt_pulgar_2_3", 
        "jnt_palma_indice_1", "jnt_indice_1_2", "jnt_indice_2_3", 
        "jnt_palma_cordial_1", "jnt_cordial_1_2", "jnt_cordial_2_3", 
        "jnt_palma_anular_1", "jnt_anular_1_2", "jnt_anular_2_3", 
        "jnt_palma_menique_1", "jnt_menique_1_2", "jnt_menique_2_3"};

    trajectory_msgs::msg::JointTrajectoryPoint point;

    for (size_t i = 0; i < TOTAL_JOINTS; ++i){
        std_msgs::msg::Float64 msg;
        //jnt_codo_antebrazo
        if(i==4){
            msg.data = -1.5708;
        }
        //jnt_biceps_codo 
        else if (i==3) {
            /*
            1.5708
            4.7124
            6.2832*/
            msg.data = 1.5708;
        }
        //jnt_hombro_biceps
        else if(i==2 && !colisionDetectada){
            bicepMov += -0.087;
            msg.data = bicepMov;
        }
        else if(i==2 && colisionDetectada){
            msg.data = bicepMov;
            RCLCPP_INFO(this->get_logger(), "Joint %lu. Detenido en: %f",i, msg.data);
        }
        else if(i==6 && colisionDetectada){
            msg.data = 1.5708;
        }
        else if((i==7 || i==8) && colisionDetectada){
            msg.data = -1.0;
        }
        else if(i==9 && colisionDetectada){
            msg.data = 0.80;
        }
        else{
            msg.data = 0.0;
        }
        point.positions.push_back(msg.data);
    }

    point.time_from_start.sec = 1;
    jointTrajectoryMsg.points.push_back(point);
    jointTrajectoryPub->publish(jointTrajectoryMsg);
}