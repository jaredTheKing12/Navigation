// Implement Kalman Filter
// Goal: Accurately estimate state
// state = [position velocity]
// sensor_data = [quaternion accelerometer angular_rates magnometer(heading)]

// References:
// https://github.com/tkhamvilai/AERSP497.01-Fall2022/tree/main/NavFilter
// https://psu.instructure.com/courses/2207491/files/141600597?module_item_id=36964573

// File structure:
// Class sensor
    // Members: Acc, Gyro, Magn, Quat, Biases
    // Functions: Get new measurements, CalcBias
// Class state
    // Members: Position, Velocity, All of those matrices(P, F,...)
    // Functions: Update(sensor_data), print, initialize


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
