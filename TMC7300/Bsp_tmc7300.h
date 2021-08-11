#ifndef _BSP_TMC7300_H_
#define _BSP_TMC7300_H_

#include "stdint.h"
#include "stdio.h"
#include "stdbool.h"

extern void Bsp_tmc7300_interruptSet(uint8_t status);
extern void Bsp_tmc7300_sendByte(uint8_t byte);
extern uint8_t Bsp_tmc7300_readByte(void);
extern void Bsp_tmc7300_enable(uint8_t status);
extern void Bsp_tmc7300_delay(uint16_t ms);


#endif

