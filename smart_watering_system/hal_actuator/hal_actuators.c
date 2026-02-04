#include "hal_actuators.h"
#include <stdio.h>

void HAL_TurnPumpOn(SystemState_t *s) {
    if (s == NULL) return;
    
    s->pumpState = PUMP_ON;
    s->ledState = LED_WATERING;
    printf("[HAL] Output: Pump ACTIVATED | LED: YELLOW\n");
}

void HAL_TurnPumpOff(SystemState_t *s) {
    if (s == NULL) return;

    s->pumpState = PUMP_OFF;
    s->ledState = LED_NORMAL;
    printf("[HAL] Output: Pump DEACTIVATED | LED: GREEN\n");
}