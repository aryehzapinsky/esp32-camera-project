#ifndef OV7670CHIP_HPP
#define OV7670CHIP_HPP

#include <stdint.h>
#include "configurations.hpp"

#ifdef __cplusplus
extern "C" {
#endif

class OV7670Chip {
 public:
  explicit OV7670Chip(OV7670ChipPinConfiguration* pin_configuration) : pin_configuration_(*pin_configuration) {}
  void Init();

  /* @brief */
  void InitializeI2C();

  /* @brief Resets the chip's registers. 
   *
   * Sets the reset pin to reset mode, waits 1 millisecond, 
   * sets the reset pin to normal mode and then waits 1 millisecond.
   */
  void Reset();

  /**/
  void GenerateTestData();

 private:
  void ConfigureInputClock();

  void ConfigureHorizontalReference();

  /* @brief Configure the interrupt to trigger on positive edge of clock. */
  void ConfigurePixelClock();

  void ConfigureVerticalSync();

  void ConfigureResetSignal();
  /* @brief Configure the power down signal.
   *
   * 0 or low is normal mode. So configure the pull down resistor.
   */
  void ConfigurePowerDownSignal();

  /* @brief Non-owning reference to pin configuration. */
  const OV7670ChipPinConfiguration& pin_configuration_;
};


#ifdef __cplusplus
}
#endif

#endif  // OV7670CHIP_HPP