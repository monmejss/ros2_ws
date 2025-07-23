/*
 * ArmDriver.cpp
 *
 *  Created on: Sept. 16, 2021
 *      Author: antonio
 * corregido ros2 iron
 */

#include "ArmDriver.h"

ArmDriver::ArmDriver()
: rclcpp::Node("arm_driver")  // Se requiere en ROS 2 heredar de rclcpp::Node
{
}

ArmDriver::~ArmDriver() {
}

void ArmDriver::setParameters(const char *iName) {
    // If needed override this method in the inherited class.
}
