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
        std::string dominio = argv[1];
        setenv("ROS_DOMAIN_ID", dominio.c_str(), 1);  // ROS 2 usa ROS_DOMAIN_ID en lugar de ROS_MASTER_URI
    }

    auto node = std::make_shared<SimulationController>();

    node->startTrajectory();
    RCLCPP_INFO(node->get_logger(), "La simulación ha terminado");

    rclcpp::spin(node);  // Mantener la simulación en ejecución
    rclcpp::shutdown();
    
    return 0;
}
