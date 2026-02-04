#ifndef HAL_SENSORS_H
#define HAL_SENSORS_H

#include "config.h"

float HAL_ReadSoilMoisture(void);
float HAL_ReadTemperature(void);

SensorData_t HAL_ReadSensors(void); 

#endif