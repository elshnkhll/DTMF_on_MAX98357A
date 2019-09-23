#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2s.h"
#include "esp_system.h"
#define SAMPLE_RATE (8000)

void SPKR_Start();
void SPKR_Play_Sample(int data);
void SPKR_Stop();
