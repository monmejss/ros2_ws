#ifndef SRC_SIMULATIONCONTROLLER_H_
#define SRC_SIMULATIONCONTROLLER_H_

#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <string>
#include <vector>
#include <utility>
#include <random>  

#define TOTAL_JOINTS 6 // Total de articulaciones del brazo

// Alias para definir rangos de movimiento de las articulaciones
using Range = std::pair<double, double>;

enum Joint { PECHO = 0, SHOULDER, BICEPS, ELBOW, WRIST, THUMB };

class SimulationController{
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
    std::vector<double> curJointVals;  // Valores acumulados para cada articulación
    std::vector<Range> jointLimits;    // Rango permitido para cada articulación

    ros::NodeHandle nh;
    //Publicadores para articulaciones
    ros::Publisher jointPub[TOTAL_JOINTS];
};

#endif /* SRC_SIMULATIONCONTROLLER_H_ */
