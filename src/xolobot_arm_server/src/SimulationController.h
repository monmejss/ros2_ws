#ifndef SRC_SIMULATIONCONTROLLER_H_
#define SRC_SIMULATIONCONTROLLER_H_

#include <rclcpp/rclcpp.hpp>
#include "std_msgs/msg/float64.hpp"
#include "gazebo_msgs/msg/contacts_state.hpp"
#include <string>
#include <vector>
#include <utility>
#include <random>  
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory_point.hpp"

#define TOTAL_JOINTS 7

// Alias para definir rangos de movimiento de las articulaciones
using Range = std::pair<double, double>;

enum Joint { PECHO = 0, SHOULDER, BICEPS, ELBOW, WRIST, WRIST2, THUMB };

class SimulationController : public rclcpp::Node{
public:
    // Constructor
    SimulationController();
    // Destructor
    virtual ~SimulationController();

    // Métodos principales
    void startTrajectory();     
    void generaAleatorios(); 

private:
    // Atributos
    std::vector<double> jointValues;    // Valores generados para cada articulación
    std::vector<Range> jointLimits;    // Rango permitido para cada articulación

    double bicepMov = 0.0;
    bool colisionDetectada;

    // Publicador para la trayectoria completa
    rclcpp::Publisher<trajectory_msgs::msg::JointTrajectory>::SharedPtr jointTrajectoryPub;
    rclcpp::Subscription<gazebo_msgs::msg::ContactsState>::SharedPtr suscriptorPalma;
   
    void deteccionColision(const gazebo_msgs::msg::ContactsState::SharedPtr msg);
};

#endif /* SRC_SIMULATIONCONTROLLER_H_ */