#ifndef SIMULATION_CONTROLLER_HPP
#define SIMULATION_CONTROLLER_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64.hpp>
#include <ros_ign_interfaces/msg/contacts.hpp>  // <--- NUEVO

#include <string>
#include <vector>
#include <utility>
#include <random>

#define TOTAL_JOINTS 6
using Range = std::pair<double, double>;

enum Joint { PECHO = 0, SHOULDER, BICEPS, ELBOW, WRIST, THUMB };

class SimulationController : public rclcpp::Node {
public:
    SimulationController();
    virtual ~SimulationController();

    void startTrajectory();     
    void generaAleatorios(); 

private:
    std::vector<double> jointValues;
    std::vector<double> curJointVals;
    std::vector<Range> jointLimits;

    std::vector<rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr> jointPub;

    rclcpp::Subscription<ros_ign_interfaces::msg::Contacts>::SharedPtr collision_subscriber_;
};

#endif
