#include <stdio.h>
#include "config.h"
#include "spws_controller.h"
#include "hal_actuators.h"
#include "hal_sensor.h"
#include "hal_buttons.h"
#include <unistd.h>

SystemSettings_t settings = {30.0, 70.0, 300, 2, 15};
SystemState_t state = {MODE_AUTO, PUMP_OFF, LED_NORMAL, 0, 0};
SensorData_t sensorData = {0.0, 0.0};

void System_Init() {
    HAL_GPIO_Init(); 
    printf("He thong SPWS: Khoi tao hoan tat.\n");
}

int main() {
    System_Init();

    while (1) {
        state.sensorCheckCounter++;
        if (state.sensorCheckCounter >= settings.sensorReadInterval_s) {
            sensorData = HAL_ReadSensors(); // Hàm lấy trung bình làm mịn
            state.sensorCheckCounter = 0;
            printf("[INFO] Sensor: %.1f%% - %.1f C\n", 
                    sensorData.soilMoisturePercent, sensorData.airTemperatureCelsius);
        }
        
        HAL_IsButton1Pressed();

        if (state.currentMode == MODE_AUTO) {
            SPWS_RunAutoMode();
        } else {
            if (state.pumpState == PUMP_ON && 
                state.wateringTimeCounter >= settings.manualWateringDuration_s) {
                state.pumpState = PUMP_OFF;
                printf("[MANUAL] Tu dong ngat sau %ds\n", settings.manualWateringDuration_s);
            }
        }
        if (state.pumpState == PUMP_ON) {
            state.wateringTimeCounter++;
        }
        SPWS_UpdateSystemStatus();

        sleep(10000);
    }
    return 0;
}