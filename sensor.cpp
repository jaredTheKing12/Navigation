#include "sensors.h"

#include <Pozyx.h>
#include <Pozyx_definitions.h>
#include <Wire.h>

// Constructor - gets called after setup
Sensor::Sensor()
{
  this->quat[0] = 1;
  this->quatB[0] = 0;
  for(uint8_t i = 0; i < 3; i++)
  {
    this->gyr[i] = 0;
    this->acc[i] = 0;
    this->mag[i] = 0;
    this->quat[i+1] = 0;
    this->gyrB[i] = 0;
    this->accB[i] = 0;
    this->magB[i] = 0;
    this->quatB[i+1] = 0;
  }
}

Sensor::~Sensor(){}

// Initialize and set biases - gets called in setup
Sensor::init()
{
  if(Pozyx.begin(false, MODE_INTERRUPT, POZYX_INT_MASK_IMU) == POZYX_FAILURE){
    Serial.println("ERROR: Unable to connect to POZYX shield");
    Serial.println("Reset required");
    delay(100);
    abort();
  }

  // Calculate biases
  for (uint8_t samples = 0; samples < 10; samples++) {
    sensor_raw_t sData; // sensor data
    Pozyx.getRawSensorData(&sData, remote_id);
  
    // Acc
    accB[0] = (samples * accB[0] + float(sData.acceleration[0])) / (samples + 1);
    accB[1] = (samples * accB[1] + float(sData.acceleration[1])) / (samples + 1);
    accB[2] = (samples * accB[2] + float(sData.acceleration[2])) / (samples + 1);

    // Gyr
    gyrB[0] = (samples * gyrB[0] + float(sData.angular_vel[0]) * 3.14 /180) / (samples + 1);
    gyrB[1] = (samples * gyrB[1] + float(sData.angular_vel[1]) * 3.14 /180) / (samples + 1);
    gyrB[2] = (samples * gyrB[2] + float(sData.angular_vel[2]) * 3.14 /180) / (samples + 1);

    // Quat
    quatB[0] = (samples * quatB[0] + float(sData.quaternion[0])*POZYX_QUAT_SCALE) / (samples + 1);
    quatB[1] = (samples * quatB[1] + float(sData.quaternion[0])*POZYX_QUAT_SCALE) / (samples + 1);
    quatB[2] = (samples * quatB[2] + float(sData.quaternion[0])*POZYX_QUAT_SCALE) / (samples + 1);
    quatB[3] = (samples * quatB[3] + float(sData.quaternion[0])*POZYX_QUAT_SCALE) / (samples + 1);
  }
}

// Gets new measured data
Sensor::update()
{
  sensor_raw_t sData; // sensor data
  Pozyx.getRawSensorData(&sData, remote_id);

  // Put the measurements in the arrays
  for (uint8_t i = 0; i < 3; i++) {
    acc[i] = sData.accelerometer
  }
}
