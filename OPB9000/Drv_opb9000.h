#ifndef _DRV_OPB9000_H_
#define _DRV_OPB9000_H_

#include "stdint.h"
#include "stdio.h"
#include "stdbool.h"

#pragma pack(1)

typedef struct
{
	uint16_t startFlag	:1;
	uint16_t erroeFlag	:1;
	uint16_t reserved1	:9;
	uint16_t CABit		:1;
	uint16_t AGCBit		:2;
	uint16_t ledCount	:10;
	uint16_t refLevel	:4;
	uint16_t DSBit		:1;
	uint16_t OPBit		:1;
	uint16_t reserved2	:7;
	uint16_t reserved3 	:3;
}OPB9000_EEPROM;

extern uint8_t Drv_opb9000_calibrate(uint8_t index)£»
extern void Drv_opb9000_writeBank2(uint8_t index,uint8_t outType,uint8_t reference_level)£»
extern uint8_t Drv_opb9000_readEeprom(uint8_t index,OPB9000_EEPROM *dataBuf)£»

#endif

