#ifndef SENSOR_H
#define SENSOR_H

#include "math_functions.h"

class Sensor
{
  public:
    Sensors();
    ~Sensors();
  
    void init(); // Initializes - this is where all the weird junk goes I think
    void update(); // Get new measurements
    void print(); // Display measurements

    // Values
    float gyr[3];
    float acc[3];
    float mag[3];
    float quat[4];

    // Biases
    float gyrB[3];
    float accB[3];
    float magB[3];
    float quatB[4];
  
  private:
};

#endif
