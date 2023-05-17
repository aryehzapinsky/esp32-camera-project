#include "ov7670chip.hpp"
#include "driver/gpio.h"
#include "freertos/FreeRTOSConfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void OV7670Chip::Reset() {
    gpio_set_level(static_cast<gpio_num_t>(pin_configuration_.RESET), 
                   static_cast<uint32_t>(ResetPinValues::ResetMode));

    // I don't really like using this constant over here. But I guess I need to use it as opposed to xPortGetTickRateHz() until I can find where and how to include that function.
    // I'm not sure I need to hold this for 1 ms
    vTaskDelay(1 / portTICK_PERIOD_MS);

    gpio_set_level(static_cast<gpio_num_t>(pin_configuration_.RESET), 
                   static_cast<uint32_t>(ResetPinValues::NormalMode));                   

    // Need to delay 1 millisecond before reading registers. 
    vTaskDelay(1 / portTICK_PERIOD_MS);
}

void OV7670Chip::Init() {
    /*
    GPIO configuration example: https://github.com/espressif/esp-idf/blob/17451f1fb3d6485af5113d96b6836a7ce60efee8/examples/peripherals/gpio/generic_gpio/main/gpio_example_main.c
    */
    gpio_config_t io_conf = {};
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    uint64_t pin_selection = 1ULL << pin_configuration_.RESET;
    io_conf.pin_bit_mask = pin_selection;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    gpio_config(&io_conf);
}

void GenerateTestData() {
    // i2c write to register scaling xsc
    TestPatternScalingXscBitMask::noTestOutput;
    // example to configure and send i2c commands: https://gist.github.com/mws-rmain/2ba434cd2a3f32d6d343c1c60fbd65c8
}