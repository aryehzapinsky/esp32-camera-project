#ifndef CONFIGURATIONS_HPP
#define CONFIGURATIONS_HPP

// From http://web.mit.edu/6.111/www/f2016/tools/OV7670_2006.pdf
// https://www.openhacks.com/uploadsproductos/ov7670_cmos_camera_module_revc_ds.pdf
// https://www.haoyuelectronics.com/Attachment/OV7670%20+%20AL422B(FIFO)%20Camera%20Module(V2.0)/OV7670%20Implementation%20Guide%20(V1.0).pdf
// https://docs.rs-online.com/ad90/0900766b80cbe14a.pdf

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* @brief Resolution Register Settings
 *
 * Holds parameters for specified settings. Values from Table 2-2 in implementation guide (https://www.haoyuelectronics.com/Attachment/OV7670%20+%20AL422B(FIFO)%20Camera%20Module(V2.0)/OV7670%20Implementation%20Guide%20(V1.0).pdf
).
 */
struct ResolutionRegisterSettings {
    uint16_t CLKRC;
    uint16_t COM7;
    uint16_t COM3;
    uint16_t COM14;
    uint16_t SCALING_XSC;
    uint16_t SCALING_YSC;
    uint16_t SCALING_DCWCTR;
    uint16_t SCALING_PCLK_DIV;
    uint16_t SCALING_PCLK_DELAY;
};

struct ResolutionRegisterSettings vga_yuv_mode {
   0x01,
    0x00,
    0x00,
    0x00,
    0x3A,
    0x35,
    0x11,
     0xF0,
    0x02,
};

struct ResolutionRegisterSettings qvga_yuv_mode = {
    .CLKRC = 0x01,
    .COM7 = 0x00,
    .COM3 = 0x04,
    .COM14 = 0x19,
    .SCALING_XSC = 0x3A,
    .SCALING_YSC = 0x35,
    .SCALING_DCWCTR = 0x11,
    .SCALING_PCLK_DIV = 0xF1,
    .SCALING_PCLK_DELAY = 0x02,
};

static constexpr struct ResolutionRegisterSettings qqvga_yuv_mode = {
    .CLKRC = 0x01,
    .COM7 = 0x00,
    .COM3 = 0x04,
    .COM14 = 0x1A,
    .SCALING_XSC = 0x3A,
    .SCALING_YSC = 0x35,
    .SCALING_DCWCTR = 0x22,
    .SCALING_PCLK_DIV = 0xF2,
    .SCALING_PCLK_DELAY = 0x02,
};

ResolutionRegisterSettings cif_yuv_mode = {
    .CLKRC = 0x01,
    .COM7 = 0x00,
    .COM3 = 0x08,
    .COM14 = 0x11,
    .SCALING_XSC = 0x3A,
    .SCALING_YSC = 0x35,
    .SCALING_DCWCTR = 0x11,
    .SCALING_PCLK_DIV = 0xF1,
    .SCALING_PCLK_DELAY = 0x02,
};

ResolutionRegisterSettings vga_raw_bayer_rgb_mode = {
    .CLKRC = 0x01,
    .COM7 = 0x01,
    .COM3 = 0x00,
    .COM14 = 0x00,
    .SCALING_XSC = 0x3A,
    .SCALING_YSC = 0x35,
    .SCALING_DCWCTR = 0x11,
    .SCALING_PCLK_DIV = 0xF0,
    .SCALING_PCLK_DELAY = 0x02,
};

/* @brief Register map for OV7670.
 *
 * Table 8-2 on pages 45-62 in https://www.haoyuelectronics.com/Attachment/OV7670%20+%20AL422B(FIFO)%20Camera%20Module(V2.0)/OV7670%20Implementation%20Guide%20(V1.0).pdf
 *
 */
enum class RegisterAddress : unsigned char {
    GAIN,
    BLUE,
    RED,
    VREF,
    COM1,
    BAVE,
    GBAVE,
    AECHH,
    RAVE,
    COM2,
    PID,
    VER,
    COM3,
    COM4,
    COM5,
    COM6,
    AECH,
    CLKRC,
    COM7,
    COM8,
    COM9,
    COM10,
    RSVD1,
    HSTART,
    HSTOP,
    VSTART,
    VSTOP,
    PSHFT,
    MIDH,
    MIDL,
    MVFP,
    LAEC,
    ADCCTR0,
    ADCCTR1,
    ADCCTR2,
    ADCCTR3,
    AEW,
    AEB,
    VPT,
    BBIAS,
    GBBIAS,
    RSVD2,
    EXHCH,
    EXHCL,
    RBIAS,
    ADVFL,
    ADVFH,
    YAVE,
    HSYST,
    HSYEN,
    HREF,
    CHLF,
    ARBLM,
    RSVD3,
    RSVD4,
    ADC,
    ACOM_ADC_and_Analog_Common_Mode_Control,
    OFON_ADC_Offset_Control,
    TSLB_Line_Buffer_Test_Option,
    COM11,
    COM12,
    COM13,
    COM14,
    EDGE,
    COM15,
    COM16,
    COM17,
    AWBC1,
    AWBC2,
    AWBC3,
    AWBC4,
    AWBC5,
    AWBC6,
    RSVD5,
    RSVD6,
    REG4B,
    DNSTH,
    DM_POS,
    RSVD7,
    MATX1,
    MATX2,
    MATX3,
    MATX4,
    MATX5,
    MATX6,
    BRIGHT,
    CONTRAS,
    CONTRAS_CENTER,
    MTXS,
    AWBC7,
    AWBC8,
    AWBC9,
    AWBC10,
    AWBC11,
    AWBC12,
    B_LMT,
    R_LMT,
    G_LMT,
    LCC1,
    LCC2,
    LCC3,
    LCC4,
    LCC5,
    MANU,
    MANV,
    GFIX,
    GGAIN,
    DBLV,
    AWBCTR3,
    AWBCTR2,
    AWBCTR1,
    AWBCTR0,
    SCALING_XSC,
    SCALING_YSC,
    SCALING_DCWCTR,
    SCALING_PCLK_DIV,
    REG74,
    REG75,
    REG76,
    REG77,
    RSVD8,
    RSVD9,
    SLOP,
    GAM1,
    GAM2,
    GAM3,
    GAM4,
    GAM5,
    GAM6,
    GAM7,
    GAM8,
    GAM9,
    GAM10,
    GAM11,
    GAM12,
    GAM13,
    GAM14,
    GAM15,
    RSVD10,
    RSVD11,
    RSVD12,
    RSVD13,
    RSVD14,
    RSVD15,
    RSVD16,
    RSVD17,
    DM_LNL,
    DM_LNH,
    LCC6,
    LCC7,
    RSVD18,
    RSVD19,
    RSVD20,
    RSVD21,
    RSVD22,
    RSVD23,
    RSVD24,
    BD50ST,
    BD60ST,
    HRL,
    LRL,
    DSPC3,
    SCALING_PCLK_DELAY,
    RSVD25,
    NT_CTRL,
    AECGMAX,
    LPH,
    UPL,
    TPL,
    TPH,
    NALG,
    RSVD26,
    STR_OPT,
    STR_R,
    STR_G,
    STR_B,
    RSVD27,
    ABLC1,
    RSVD28,
    THL_ST,
    RSVD29,
    THL_DLT,
    RSVD30,
    RSVD31,
    RSVD32,
    RSVD33,
    RSVD34,
    RSVD35,
    RSVD36,
    RSVD37,
    AD_CHB,
    AD_CHR,
    AD_CHGB,
    AD_CHGR,
    RSVD38,
    RSVD39,
    RSVD40,
    RSVD41,
    RSVD42,
    RSVD43,
    RSVD44,
    SATCTR,
    TOTAL_NUMBER_OF_ADDRESSES = SATCTR,
};

static_assert(static_cast<int>(RegisterAddress::TOTAL_NUMBER_OF_ADDRESSES) == 201, 
 "Expecting 201 (0xC9) register addresses.");

enum class SyncSignalPins {
    VSYNC = 1,
    HREF = 2,
    HSYNC = HREF,
};

enum class Com10BitMask : unsigned char {
    HSYNC_Negative = 0b0000'0001,
    VSYNC_Negative = 0b0000'0010,
    VSYNC_changes_on_rising_edge_of_pclk = 0b0000'0100,
    HREF_Polarity_reverse = 0b0000'1000,
    PCLK_Polarity_reverse = 0b0001'0000,
    PCLK_Gated_By_HREF = 0b0010'0000,
    HREF_changes_to_HSYNC = 0b0100'0000,
    Reserved = 0b1000'0000,
};

bool dataUpdatedAtRisingEdge (unsigned char register_value) {
    return ((register_value & 
            static_cast<unsigned char>(Com10BitMask::PCLK_Polarity_reverse)) 
            == 0b0000'1000);
}

bool pclkGatedByHref (unsigned char register_value) {
    return ((register_value & 
            static_cast<unsigned char>(Com10BitMask::PCLK_Gated_By_HREF))
            == 0b0001'0000);
}

/* Represents clock frequency. f_SIO_C. Units - KHz*/
constexpr int kClockFrequency = 400;

/* Clock low period in nanoseconds. t_LOW. */
constexpr int kClockLowPeriod = 1300;

/* Clock low period in nanoseconds. t_LOW. */
constexpr int kClockHighPeriod = 600;

/* SIO_C low to Data out valid minimum time in nanoseconds. */
constexpr int kClockLowToValidDataOutMin = 100;

/* SIO_C low to Data out valid maximum time in nanoseconds. */
constexpr int kClockLowToValidDataOutMax = 900;

/* Bus free time before new start condition minimum time in nanoseonds. t_BUF */
constexpr int kBusFreeTimeBeforeNewStart = 1300;

/* Start condition to hold minimum time in nanoseconds. t_HD:STA*/
constexpr int kStartConditionHoldTime = 600;

/* Start condition to setup hold minimum time in nanoseconds. t_SU:STA*/
constexpr int kStartConditionSetupTime = 600;

/* Data in hold time. Time in nanoseconds. t_HD:DAT */
constexpr int kDataInHoldTime = 0;

/* Data in hold time. Time in nanoseconds. t_SU:DAT */
constexpr int kDataInSetupTime = 100;

/* Stop condition setup hold minimum time in nanoseconds. t_SU:STO */
constexpr int kStopConditionSetupTime = 600;

/* Data out hold time in nanoseconds. t_DH */
constexpr int kDataOutHoldTime = 50;

/* Max amount of time in nanoseconds between PCLK down to valid data out. t_PDV*/
constexpr int kPixelClockDownToValidDataOut = 5;

/* Minimum amount of time to setup valid data in nanoseconds. t_SU */
constexpr int kDataOutSetupTime = 15;

/* Minimum amount of time to hold valid data in nanoseconds. t_HD */
constexpr int kDataOutMinimumHoldTime = 8;

/* Average clock period in nanoseconds. t_CLK */
constexpr int kInputClockPeriod = 42;

/* Average clock frequency in MHz. f_CLK */
constexpr int kInputClockFrequency = 24;

/* Setting time after software/hardware reset in milliseconds. t_S:RESET */
constexpr int kSettingTimeAfterReset = 1;

/* Setting time for register change in milliseconds. 10 frames required. t_S:REG */
constexpr int kSettingTimeRegisterChange = 300;


/* Device's address as secondary is 0x42 for write and 0x43 for read. Data sheet page 11. */
constexpr uint8_t OV7670AddressWrite = 0x42;
constexpr uint8_t OV7670AddressRead = 0x43;

struct OV7670ChipPinConfiguration {
    uint8_t SIOC;
    uint8_t SIOD;
    uint8_t VSYNC;
    uint8_t HREF;
    uint8_t PCLK;
    uint8_t XCLK;
    uint8_t D7;
    uint8_t D6;
    uint8_t D5;
    uint8_t D4;
    uint8_t D3;
    uint8_t D2;
    uint8_t D1;
    uint8_t D0;
    uint8_t RESET;
    uint8_t PWDN;
};

OV7670ChipPinConfiguration defaultPinConfiguration = {
    .SIOC = 23,
    .SIOD = 22,
    .VSYNC = 34,
    .HREF = 35,
    .PCLK = 32,
    .XCLK = 33,
    .D7 = 4,
    .D6 = 0,
    .D5 = 2,
    .D4 = 15,
    .D3 = 13,
    .D2 = 12,
    .D1 = 14,
    .D0 = 27,
    .RESET = 36,
    .PWDN = 39,
};

enum class ResetPinValues : uint8_t {
    ResetMode = 0x00,
    NormalMode = 0x01
};

enum class PowerDownSignalValues : uint8_t {
    NormalMode = 0x00,
    PowerDownMode = 0x01
};

enum class TestPatternType : unsigned char {
    noTestOutput = 0b0000'0000,
    shiftingOne = 0b000'0001,
    eightBarColorBar = 0b0000'0010,
    fadeToGrayColorBar = 0b0000'0011,
};

enum class TestPatternScalingXscBitMask : const unsigned char {
    noTestOutput = 0b0000'0000,
    shiftingOne = 0b0000'0000,
    eightBarColorBar = 0b1000'0000,
    fadeToGrayColorBar = 0b1000'0000,
};

enum class TestPatternScalingYscBitMask : const unsigned char {
    noTestOutput = 0b0000'0000,
    shiftingOne = 0b1000'0000,
    eightBarColorBar = 0b0000'0000,
    fadeToGrayColorBar = 0b1000'0000,
};

#ifdef __cplusplus
}
#endif

/* First command must be a register reset because registers rely on default value setting.*/
#endif  // CONFIGUTATIONS_HPP
