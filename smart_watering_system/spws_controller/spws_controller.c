#include "config.h"
#include "hal_actuators.h"
#include <stdio.h>

extern SystemSettings_t settings;
extern SystemState_t state;
extern SensorData_t sensorData;

void SPWS_UpdateSystemStatus() {
    // Tự động cập nhật LedState dựa trên trạng thái bơm và cảm biến
    if (state.pumpState == PUMP_ON) {
        state.ledState = LED_WATERING;
    } else if (sensorData.soilMoisturePercent < settings.minMoistureThreshold) {
        state.ledState = LED_LOW_MOISTURE_ALERT;
    } else {
        state.ledState = LED_NORMAL;
    }
    
    // Gọi HAL để thực hiện lệnh vật lý
    HAL_ControlPump(state.pumpState);
    HAL_ControlLED(state.ledState);
}

void SPWS_RunAutoMode() {
    if (state.currentMode != MODE_AUTO) return;

    if (state.pumpState == PUMP_OFF) {
        if (sensorData.soilMoisturePercent < settings.minMoistureThreshold) {
            state.pumpState = PUMP_ON;
            state.wateringTimeCounter = 0; // Reset bộ đếm khi bắt đầu tưới
            printf("[AUTO] Do am thap: %.1f%%. Bat dau tuoi.\n", sensorData.soilMoisturePercent);
        }
    } else {
        // Tắt bơm khi đủ ẩm HOẶC quá thời gian tối đa
        if (sensorData.soilMoisturePercent > settings.maxMoistureThreshold || 
            state.wateringTimeCounter >= settings.maxWateringDuration_s) {
            state.pumpState = PUMP_OFF;
            printf("[AUTO] Dung tuoi. Do am: %.1f%%, Thoi gian: %ds\n", 
                    sensorData.soilMoisturePercent, state.wateringTimeCounter);
        }
    }
}