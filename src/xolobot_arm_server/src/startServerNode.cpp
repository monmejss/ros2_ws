#include "SimulationController.h"
#include <ros/ros.h>
#include <vector>
#include <string>
#include <utility>
#include <fmt/core.h>
#include <fmt/ranges.h>

using namespace std;

int main(int argc, char** argv)
{
   if (argc > 1)
   {
      printf("ENTRO AL IF DE CAMBIO DE ENTORNO\n");
      std::string puerto = std::string("http://localhost:1135") + argv[1];
      setenv("ROS_MASTER_URI", puerto.c_str(), 1);
   }
   ros::init(argc, argv, "xolobot_arm_server");
   SimulationController sim;

   sim.startTrajectory();

   ROS_INFO("La simulacion ha terminado\n");

   return 0;
}
