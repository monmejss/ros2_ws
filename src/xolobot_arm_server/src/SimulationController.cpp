#include "SimulationController.hpp"
#include <random>

SimulationController::SimulationController() : Node("simulation_controller") {
    jointLimits = {{-0.5, 0.5}, {-1.0, 1.0}, {-0.5, 0.5},
                   {-0.5, 0.5}, {-1.0, 1.0}, {-1.0, 1.0}};

    jointValues.assign(TOTAL_JOINTS, 0.0);

    for (size_t i = 0; i < TOTAL_JOINTS; i++) {
        std::string topicCmd = "/xolobot_arm/joint" + std::to_string(i + 1) + "_position_controller/command";
        jointPub.push_back(this->create_publisher<std_msgs::msg::Float64>(topicCmd, rclcpp::QoS(10)));
    }

    collision_subscriber_ = this->create_subscription<ros_ign_interfaces::msg::Contacts>(
        "/world/coca_levitando/physics/contacts", rclcpp::QoS(10),
        [this](ros_ign_interfaces::msg::Contacts::SharedPtr msg) {
            if (!msg->contacts.empty()) {
                RCLCPP_WARN(this->get_logger(), "🚨 ¡Colisión detectada en el mundo Ignition!");
            }
        });

    RCLCPP_INFO(this->get_logger(), "Nodo SimulationController iniciado.");
}

SimulationController::~SimulationController() {}

void SimulationController::startTrajectory() {
    RCLCPP_INFO(this->get_logger(), "Iniciando simulación");
    rclcpp::Rate loop_rate(0.5);
    
    while (rclcpp::ok()) {
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

        if (i == 3) {
            msg.data = 1.5708;
        } else if (i == 4) {
            msg.data = -1.5708;
        } else if (i == 2) {
            msg.data = (jointLimits[i].first + jointLimits[i].second) / 2.0;
        }

        RCLCPP_INFO(this->get_logger(), "Articulación %lu valor: %f", i + 1, msg.data);
        jointPub[i]->publish(msg);
        rate.sleep();
    }
}
