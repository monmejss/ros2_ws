#include "SimulationController.h"
#include "std_msgs/msg/float64.hpp"
#include <random>
#include "gazebo_msgs/msg/contacts_state.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory_point.hpp"

bool colisionDetectada = false;
void SimulationController::deteccionColision(gazebo_msgs::msg::ContactsState::SharedPtr msg) {
    RCLCPP_WARN(this->get_logger(), "Se ha detectado una colisión");
}

// Inicializa el nodo simulation_controller
SimulationController::SimulationController() : rclcpp::Node("simulation_controller"){
    // Inicializar los límites de las articulaciones (en radianes)
    jointLimits = {{-0.5, 0.5},  // Pecho
                   {-1.0, 1.0},  // Hombro
                   {-0.5, 0.5},  // Bíceps
                   {-0.5, 0.5},  // Codo
                   {-1.0, 1.0},  // Muñeca
                   {-1.0, 1.0}}; // Pulgar

    // Inicializar valores por defecto
    jointValues.assign(TOTAL_JOINTS, 0.0);

    // Crear publicadores para cada articulación
    for (int i = 0; i < TOTAL_JOINTS; i++){
        std::string topicCmd = "/xolobot_arm/joint" + std::to_string(i + 1) + "_position_controller/command";
        jointPub[i] = this->create_publisher<std_msgs::msg::Float64>(topicCmd, 5);
    }

    // Suscriptor para el bumper
    //suscriptorBicep = this->create_subscription<std_msgs::msg::Float64>(
    //    "/bicep_position_topic", 10, std::bind(&SimulationController::deteccionColision, this, std::placeholders::_1));

    // Publicador para trayectoria completa
    jointTrajectoryPub = this->create_publisher<trajectory_msgs::msg::JointTrajectory>("/joint_trajectory_controller/joint_trajectory", 10);
}
SimulationController::~SimulationController() {}

void SimulationController::startTrajectory(){
    RCLCPP_INFO(this->get_logger(), "Iniciando simulacion");
    rclcpp::Rate loop_rate(0.5);
    while (rclcpp::ok())
    {
        generaAleatorios();
        loop_rate.sleep();
    }
}

void SimulationController::generaAleatorios(){
    std::random_device rd;
    std::mt19937 gen(rd());
    rclcpp::Rate rate(8.0);
    
    trajectory_msgs::msg::JointTrajectory jointTrajectoryMsg;
    // Define nombres de articulaciones
    jointTrajectoryMsg.joint_names = {"jnt_pecho_hombro", "jnt_hombro_hombro", "jnt_hombro_biceps", 
                                      "jnt_biceps_codo", "jnt_codo_antebrazo", "jnt_palma_pulgar_1"};

    // Crear el punto de la trayectoria para las posiciones
    trajectory_msgs::msg::JointTrajectoryPoint point;


    for (size_t i = 0; i < TOTAL_JOINTS; ++i){
        std_msgs::msg::Float64 msg;
        // Codo
        if(i==3){
            msg.data = 1.5708;
            RCLCPP_INFO(this->get_logger(), "Articulacion %lu .Valor Fijo:%f", i+1, msg.data);
        }
        //Muñeca 
        else if (i == 4) {
            msg.data = -1.5708;
            /*
            1.5708
            4.7124
            6.2832
            */
            RCLCPP_INFO(this->get_logger(), "Articulacion %lu. Valor Fijo: %f",i+1, msg.data);
        }
        //Biceps
        else if(i==2){
            bicepMov += -0.087;
            rclcpp::Rate bicepRate(64.0);
            msg.data = bicepMov;
            jointPub[i]->publish(msg);
            RCLCPP_INFO(this->get_logger(), "Articulacion %lu  Moviendose:%f",i+1, msg.data);
        }

        // Publica el valor y se añada al punto
        jointPub[i]->publish(msg);
        point.positions.push_back(msg.data);
        rate.sleep();
    }

    point.time_from_start.sec = 1;
    // Juntar valores
    jointTrajectoryMsg.points.push_back(point);
    // Publicar trayectoria completa
    jointTrajectoryPub->publish(jointTrajectoryMsg);
}

