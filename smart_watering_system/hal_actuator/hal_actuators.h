#ifndef HAL_ACTUATORS_H
#define HAL_ACTUATORS_H

#include "config.h"

/**
 * @brief Initializes the GPIO pins for the pump and LED indicators.
 * This should be called during System_Init().
 */
void HAL_GPIO_Init(void);

/**
 * @brief Controls the physical state of the water pump.
 * @param state PUMP_ON or PUMP_OFF.
 */
void HAL_ControlPump(PumpState_t state);

/**
 * @brief Updates the physical LED color/pattern based on the system state.
 * @param state The current LedState_t (NORMAL, WATERING, ALERT, ERROR).
 */
void HAL_ControlLED(LedState_t state);

#endif