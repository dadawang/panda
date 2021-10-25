#ifndef PANDA_CONFIG_H
#define PANDA_CONFIG_H

//#define DEBUG
//#define DEBUG_UART
//#define DEBUG_USB
//#define DEBUG_SPI
//#define DEBUG_FAULTS

#define USB_VID 0xbbaaU

#ifdef BOOTSTUB
  #define USB_PID 0xddeeU
#else
  #define USB_PID 0xddccU
#endif

#define NULL ((void*)0)
#define COMPILE_TIME_ASSERT(pred) ((void)sizeof(char[1 - (2 * ((int)(!(pred))))]))

#define MIN(a,b) \
 ({ __typeof__ (a) _a = (a); \
     __typeof__ (b) _b = (b); \
   (_a < _b) ? _a : _b; })

#define MAX(a,b) \
 ({ __typeof__ (a) _a = (a); \
     __typeof__ (b) _b = (b); \
   (_a > _b) ? _a : _b; })

#define ABS(a) \
 ({ __typeof__ (a) _a = (a); \
   (_a > 0) ? _a : (-_a); })

#define MAX_RESP_LEN 0x40U
#define CANPACKET_HEAD_SIZE 5U

#define GET_BUS(msg) ((msg)->bus)
#define GET_LEN(msg) ((msg)->len)
#define GET_ADDR(msg) ((msg)->addr)
#define GET_BYTE(msg, b) ((msg)->data[(b)])
#define GET_BYTES_04(msg) ((msg)->data[0] | ((msg)->data[1] << 8) | ((msg)->data[2] << 16) | ((msg)->data[3] << 24))
#define GET_BYTES_48(msg) ((msg)->data[4] | ((msg)->data[5] << 8) | ((msg)->data[6] << 16) | ((msg)->data[7] << 24))
#define GET_FLAG(value, mask) (((__typeof__(mask))(value) & (mask)) == (mask))

// Flasher and pedal with raw mailbox access
#define GET_MAILBOX_BYTE(msg, b) (((int)(b) > 3) ? (((msg)->RDHR >> (8U * ((unsigned int)(b) % 4U))) & 0xFFU) : (((msg)->RDLR >> (8U * (unsigned int)(b))) & 0xFFU))
#define GET_MAILBOX_BYTES_04(msg) ((msg)->RDLR)
#define GET_MAILBOX_BYTES_48(msg) ((msg)->RDHR)

#define CAN_INIT_TIMEOUT_MS 500U

#include <stdbool.h>
#ifdef STM32H7
  #include "stm32h7/stm32h7_config.h"
#else
  #include "stm32fx/stm32fx_config.h"
#endif

#endif
