#ifndef HAL_BUTTONS_H
#define HAL_BUTTONS_H

#include <stdbool.h>

/**
 * @brief Checks if the Mode Switch button (Button 1) is pressed.
 * @return true if pressed, false otherwise.
 */
bool HAL_IsButton1Pressed(void);

/**
 * @brief Checks if the Manual Watering button (Button 2) is pressed.
 * @return true if pressed, false otherwise.
 */
bool HAL_IsButton2Pressed(void);

#endif