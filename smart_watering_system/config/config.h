#ifndef CONFIG_H
#define CONFIG_H

// --- 1. Các Trạng Thái Hoạt Động (Enums) ---
typedef enum {
    MODE_AUTO,
    MODE_MANUAL
} SystemMode_t;

typedef enum {
    PUMP_OFF,
    PUMP_ON
} PumpState_t;

typedef enum {
    LED_NORMAL,            // Xanh: Bình thường, chờ
    LED_WATERING,          // Vàng: Đang tưới
    LED_LOW_MOISTURE_ALERT,// Đỏ nhấp nháy: Độ ẩm thấp cảnh báo
    LED_ERROR              // Đỏ sáng liên tục: Lỗi
} LedState_t;

// --- 2. Cấu Trúc Dữ Liệu Chính (Structs) ---
typedef struct {
    float soilMoisturePercent;
    float airTemperatureCelsius;
} SensorData_t;

typedef struct {
    float minMoistureThreshold;      // Ngưỡng tối thiểu để bắt đầu tưới
    float maxMoistureThreshold;      // Ngưỡng tối đa để dừng tưới
    unsigned int maxWateringDuration_s;  // Thời gian tưới tối đa
    unsigned int sensorReadInterval_s;   // Chu kỳ đọc cảm biến
    unsigned int manualWateringDuration_s; // Thời gian tưới thủ công
} SystemSettings_t;

typedef struct {
    SystemMode_t currentMode;
    PumpState_t pumpState;
    LedState_t ledState;
    unsigned int wateringTimeCounter; // Biến đếm thời gian đang tưới
    unsigned int sensorCheckCounter;  // Biến đếm cho chu kỳ đọc cảm biến
} SystemState_t;

#endif