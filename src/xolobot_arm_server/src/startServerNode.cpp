#include "SimulationController.hpp"
#include <rclcpp/rclcpp.hpp>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);

    if (argc > 1)
    {
        printf("ENTRO AL IF DE CAMBIO DE ENTORNO\n");
        std::string puerto = std::string("http://localhost:1135") + argv[1];
        setenv("ROS_MASTER_URI", puerto.c_str(), 1);
    }

    auto node = rclcpp::Node::make_shared("xolobot_arm_server");
    SimulationController sim;
    sim.startTrajectory();
    RCLCPP_INFO(node->get_logger(), "La simulacion ha terminado");
    rclcpp::spin_some(node);
    rclcpp::shutdown();
    
    return 0;
}
