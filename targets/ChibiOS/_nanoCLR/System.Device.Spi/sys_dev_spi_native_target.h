//
// Copyright (c) .NET Foundation and Contributors
// See LICENSE file in the project root for full license information.
//

#ifndef SYS_DEV_SPI_NATIVE_TARGET_H
#define SYS_DEV_SPI_NATIVE_TARGET_H

#include <sys_dev_spi_native.h>
#include <hal.h>

// struct representing the SPI bus
struct NF_PAL_SPI
{
    int BusIndex;
    SPIDriver *Driver;
    SPIConfig Configuration;
    SpiBusConfiguration BusConfiguration;

    SPI_Callback Callback;

    bool SequentialTxRx;
    bool BufferIs16bits;

    uint8_t *WriteBuffer;
    uint16_t WriteSize;

    uint8_t *ReadBuffer;
    uint16_t ReadSize;
};

// the following macro defines a function that configures the GPIO pins for an STM32 SPI peripheral
// it gets called in the Windows_Devices_SPi_SPiDevice::NativeInit function
// this is required because the SPI peripherals can use multiple GPIO configuration combinations
#define SPI_CONFIG_PINS(                                                                                               \
    num,                                                                                                               \
    gpio_port_sck,                                                                                                     \
    sck_pin,                                                                                                           \
    gpio_port_miso,                                                                                                    \
    miso_pin,                                                                                                          \
    gpio_port_mosi,                                                                                                    \
    mosi_pin,                                                                                                          \
    alternate_function)                                                                                                \
    void ConfigPins_SPI##num(bool isHalfDuplex)                                                                        \
    {                                                                                                                  \
        palSetPadMode(                                                                                                 \
            gpio_port_sck,                                                                                             \
            sck_pin,                                                                                                   \
            (PAL_MODE_ALTERNATE(alternate_function) | PAL_STM32_OSPEED_HIGHEST | PAL_STM32_PUPDR_FLOATING |            \
             PAL_STM32_OTYPE_PUSHPULL));                                                                               \
        palSetPadMode(                                                                                                 \
            gpio_port_mosi,                                                                                            \
            mosi_pin,                                                                                                  \
            (PAL_MODE_ALTERNATE(alternate_function) | PAL_STM32_OSPEED_HIGHEST | PAL_STM32_PUPDR_FLOATING |            \
             PAL_STM32_OTYPE_PUSHPULL));                                                                               \
        if (!isHalfDuplex)                                                                                             \
        {                                                                                                              \
            palSetPadMode(                                                                                             \
                gpio_port_miso,                                                                                        \
                miso_pin,                                                                                              \
                (PAL_MODE_ALTERNATE(alternate_function) | PAL_STM32_OSPEED_HIGHEST | PAL_STM32_PUPDR_FLOATING |        \
                 PAL_STM32_OTYPE_PUSHPULL));                                                                           \
        }                                                                                                              \
    }

//////////////////////////////////////////////////////////////////////////////////////////////
// when an SPI is defined the declarations below will have the real function/configuration //
// in the target folder @ target_windows_devices_spi_config.cpp                             //
//////////////////////////////////////////////////////////////////////////////////////////////
void ConfigPins_SPI1(bool isHalfDuplex);
void ConfigPins_SPI2(bool isHalfDuplex);
void ConfigPins_SPI3(bool isHalfDuplex);
void ConfigPins_SPI4(bool isHalfDuplex);
void ConfigPins_SPI5(bool isHalfDuplex);
void ConfigPins_SPI6(bool isHalfDuplex);

#endif // SYS_DEV_SPI_NATIVE_TARGET_H
