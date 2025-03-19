#ifndef SIMULATION_CONTROLLER_HPP
#define SIMULATION_CONTROLLER_HPP

#include <rclcpp/rclcpp.hpp>
#include "std_msgs/msg/float64.hpp"
#include "gazebo_msgs/msg/contacts_state.hpp"
#include <string>
#include <vector>
#include <utility>
#include <random>

#define TOTAL_JOINTS 6 // Total de articulaciones del brazo

// Alias para definir rangos de movimiento de las articulaciones
using Range = std::pair<double, double>;

enum Joint { PECHO = 0, SHOULDER, BICEPS, ELBOW, WRIST, THUMB };

class SimulationController : public rclcpp::Node {
public:
    // Constructor
    SimulationController();
    // Destructor
    virtual ~SimulationController();

    // Métodos principales
    void startTrajectory();     
    void generaAleatorios(); 
    void deteccionColision(const gazebo_msgs::msg::ContactsState::SharedPtr msg);

private:
    // Atributos
    std::vector<double> jointValues;    // Valores generados para cada articulación
    std::vector<double> curJointVals;   // Valores acumulados para cada articulación
    std::vector<Range> jointLimits;     // Rango permitido para cada articulación

    std::vector<rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr> jointPub;
    rclcpp::Subscription<gazebo_msgs::msg::ContactsState>::SharedPtr collision_subscriber_;
};

#endif // SIMULATION_CONTROLLER_HPP
