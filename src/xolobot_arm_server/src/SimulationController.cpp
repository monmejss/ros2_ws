#include "SimulationController.hpp"
#include "gazebo_msgs/msg/contacts_state.hpp"
#include <random>

bool colisionDetectada = false;

void SimulationController::deteccionColision(const gazebo_msgs::msg::ContactsState::SharedPtr msg) {
    if (!msg->states.empty()) {
        colisionDetectada = true;
        RCLCPP_WARN(this->get_logger(), "Se ha detectado una colisión");
    }
}

SimulationController::SimulationController() : Node("simulation_controller") {
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
    for (size_t i = 0; i < TOTAL_JOINTS; i++) {
        std::string topicCmd = "/xolobot_arm/joint" + std::to_string(i + 1) + "_position_controller/command";
        jointPub.push_back(this->create_publisher<std_msgs::msg::Float64>(topicCmd, rclcpp::QoS(10)));
    }

    // Suscriptor para detección de colisión
    collision_subscriber_ = this->create_subscription<gazebo_msgs::msg::ContactsState>(
        "/collision_topic", rclcpp::QoS(10), 
        std::bind(&SimulationController::deteccionColision, this, std::placeholders::_1));

    RCLCPP_INFO(this->get_logger(), "Nodo SimulationController iniciado.");
}

SimulationController::~SimulationController() {}

void SimulationController::startTrajectory() {
    RCLCPP_INFO(this->get_logger(), "Iniciando simulación");
    rclcpp::Rate loop_rate(0.5);
    
    while (rclcpp::ok()) {
        // Generar valores aleatorios para las articulaciones
        generaAleatorios();
        loop_rate.sleep();
    }
}

void SimulationController::generaAleatorios() {
    std::random_device rd;
    std::mt19937 gen(rd());
    rclcpp::Rate rate(8.0);

    for (size_t i = 0; i < TOTAL_JOINTS; ++i) {
        auto msg = std_msgs::msg::Float64();

        // Codo
        if (i == 3) {
            msg.data = 1.5708;
            RCLCPP_INFO(this->get_logger(), "Articulación %lu. Valor Fijo: %f", i + 1, msg.data);
        }
        // Muñeca
        else if (i == 4) {
            msg.data = -1.5708;
            RCLCPP_INFO(this->get_logger(), "Articulación %lu. Valor Fijo: %f", i + 1, msg.data);
        }
        // Bíceps (parece que aquí faltaba código en ROS1)
        else if (i == 2) {
            msg.data = (jointLimits[i].first + jointLimits[i].second) / 2.0;
            RCLCPP_INFO(this->get_logger(), "Articulación %lu Moviéndose: %f", i + 1, msg.data);
        }

        jointPub[i]->publish(msg);
        rate.sleep();
    }
}
