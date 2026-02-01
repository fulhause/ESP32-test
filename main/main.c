#include <inttypes.h>
#include <stdio.h>

#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_log.h"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "m5stamps3a";

void app_main(void)
{
    esp_chip_info_t chip_info;
    uint32_t flash_size = 0;

    esp_chip_info(&chip_info);
    esp_flash_get_size(NULL, &flash_size);

    ESP_LOGI(TAG, "Hello from M5StampS3A!");
    ESP_LOGI(TAG, "ESP-IDF version: %s", esp_get_idf_version());
    ESP_LOGI(TAG, "Chip revision: %d", chip_info.revision);
    ESP_LOGI(TAG, "Flash size: %" PRIu32 " bytes", flash_size);

    while (true) {
        ESP_LOGI(TAG, "Running... free heap: %" PRIu32 " bytes", esp_get_free_heap_size());
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
