#ifndef _BSP_OPB9000_H_
#define _BSP_OPB9000_H_

#include "stdint.h"
#include "stdio.h"
#include "stdbool.h"

extern void Bsp_opb9000_interrupSet(uint8_t status);
extern void Bsp_opb9000_delay1us();
extern void Bsp_opb9000_delay5us();
extern void Bsp_opb9000_CAL_HIGH(uint8_t index);
extern void Bsp_opb9000_CAL_LOW(uint8_t index);
extern void Bsp_opb9000_CAL_DIR(uint8_t index,uint8_t dir);
extern uint8_t Bsp_opb9000_CAL_READ(uint8_t index);
extern void Bsp_opb9000_OUT_DIR(uint8_t index,uint8_t dir);
extern uint8_t Bsp_opb9000_outRead(uint8_t index);
extern void Bsp_opb9000_configure(void);

#endif


