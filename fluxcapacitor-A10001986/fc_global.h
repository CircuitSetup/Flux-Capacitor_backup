/*
 * -------------------------------------------------------------------
 * CircuitSetup.us Flux Capacitor
 * (C) 2023 Thomas Winischhofer (A10001986)
 * https://github.com/realA10001986/Flux-Capacitor
 * http://fc.backtothefutu.re
 *
 * Global definitions
 */

#ifndef _FC_GLOBAL_H
#define _FC_GLOBAL_H

// Version strings.
#define FC_VERSION       "V1.010"
#define FC_VERSION_EXTRA "SEP192023"

//#define FC_DBG              // debug output on Serial

/*************************************************************************
 ***                     mDNS (Bonjour) support                        ***
 *************************************************************************/

// Supply mDNS service 
// Allows accessing the Config Portal via http://hostname.local
// <hostname> is configurable in the Config Portal
// This needs to be commented if WiFiManager provides mDNS
#define FC_MDNS

// Uncomment this if WiFiManager has mDNS enabled
//#define FC_WM_HAS_MDNS          

/*************************************************************************
 ***             Configuration for peripherals/features                ***
 *************************************************************************/

// Uncomment for HomeAssistant MQTT protocol support
#define FC_HAVEMQTT

// --- end of config options

/*************************************************************************
 ***                           Miscellaneous                           ***
 *************************************************************************/

// Uncomment this if using a FC control board v1.2
// Comment for all later versions
//#define BOARD_1_2

// Use SPIFFS (if defined) or LittleFS (if undefined; esp32-arduino >= 2.x)
//#define USE_SPIFFS

// External time travel lead time, as defined by TCD firmware
// If FC is connected by wire, the option "Signal Time Travel without 5s 
// lead" on the TCD must NOT be set.
#define ETTO_LEAD 5000

/*************************************************************************
 ***                  esp32-arduino version detection                  ***
 *************************************************************************/

#if defined __has_include && __has_include(<esp_arduino_version.h>)
#include <esp_arduino_version.h>
#ifdef ESP_ARDUINO_VERSION_MAJOR
    #if ESP_ARDUINO_VERSION >= ESP_ARDUINO_VERSION_VAL(2,0,8)
    #define HAVE_GETNEXTFILENAME
    #endif
#endif
#endif

/*************************************************************************
 ***                             GPIO pins                             ***
 *************************************************************************/

// FC LEDs
#define SHIFT_CLK_PIN     21
#define REG_CLK_PIN       18
#define MRESET_PIN        19
#define SERDATA_PIN       22

// Box LEDs
#define BLED_PWM_PIN      2

// Center LED
#define LED_PWM_PIN       17

// GPIO14 (for alternative box lights)
#define GPIO_14           14

// IR Remote input
#define IRREMOTE_PIN      27

// IR feedback LED
#ifndef BOARD_1_2
#define IR_FB_PIN         12
#else
#define IR_FB_PIN         14
#endif

// Time Travel button (or TCD tt trigger input)
#define TT_IN_PIN         13

// I2S audio pins
#define I2S_BCLK_PIN      26
#define I2S_LRCLK_PIN     25
#define I2S_DIN_PIN       33

// SD Card pins
#define SD_CS_PIN          5
#define SPI_MOSI_PIN      23
#define SPI_MISO_PIN      16
#define SPI_SCK_PIN       15

// analog input pin, used for Speed
#define SPEED_PIN         32   

// analog input, for volume   
#define VOLUME_PIN        35    // Board Rev 1.3

#endif
