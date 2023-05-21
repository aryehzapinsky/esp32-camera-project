#include "ov7670chip.hpp"
#include "configurations.hpp"
#include "driver/gpio.h"
#include "driver/i2c.h"
#include "freertos/FreeRTOSConfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "type_traits"
#include "utility"

namespace
{
  constexpr int kI2cTimeoutMs = 1000 / portTICK_PERIOD_MS;
  constexpr int kI2cPrimaryPort = 0;
  constexpr int kI2cWriteAddress = 0x42;
  constexpr int kI2cReadAddress = 0x43;
} // namespace

void OV7670Chip::Reset()
{
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

void OV7670Chip::Init()
{
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

void OV7670Chip::InitializeI2C()
{
  i2c_config_t configuration;
  configuration.mode = I2C_MODE_MASTER;
  configuration.sda_io_num = static_cast<int>(pin_configuration_.SIOD);
  configuration.sda_pullup_en = GPIO_PULLUP_ENABLE;
  configuration.scl_io_num = static_cast<int>(pin_configuration_.SIOC);
  configuration.scl_pullup_en = GPIO_PULLUP_ENABLE;
  configuration.master.clk_speed = kClockFrequency();
  i2c_param_config(kI2cPrimaryPort, &configuration);

  i2c_driver_install(kI2cPrimaryPort, configuration.mode, /*slv_rx_buf_len=*/0, /*slv_tx_buf_len=*/0, /*intr_alloc_flags=*/0);
}

// https://stackoverflow.com/questions/14589417/can-an-enum-class-be-converted-to-the-underlying-type
template<typename E>
constexpr auto to_underlying(E e) -> typename std::underlying_type<E>::type 
{
   return static_cast<typename std::underlying_type<E>::type>(e);
}

void OV7670Chip::GenerateTestData()
{
  // i2c write to register scaling xsc
  // TestPatternScalingXscBitMask::noTestOutput;
  constexpr int size_of_write_buffer = 4;
  constexpr unsigned char write_buffer[size_of_write_buffer] = {
    to_underlying(RegisterAddress::SCALING_XSC),
    to_underlying(TestPatternScalingXscBitMask::eightBarColorBar),
    to_underlying(RegisterAddress::SCALING_YSC), 
    to_underlying(TestPatternScalingYscBitMask::eightBarColorBar)};
  i2c_master_write_to_device(kI2cPrimaryPort, kI2cWriteAddress, write_buffer, size_of_write_buffer, kI2cTimeoutMs);
  // example to configure and send i2c commands: https://gist.github.com/mws-rmain/2ba434cd2a3f32d6d343c1c60fbd65c8
}