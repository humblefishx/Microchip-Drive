#ifndef _DRV_TMC7300_H_
#define _DRV_TMC7300_H_

#include "stdint.h"
#include "stdio.h"
#include "stdbool.h"

#pragma pack(1)

#define TMC7300Reg_GCONF				0x00
#define TMC7300Reg_GSTAT				0x01
#define TMC7300Reg_IFCNT				0x02
#define TMC7300Reg_SLAVECONF			0x03
#define TMC7300Reg_IOIN					0x06
#define TMC7300Reg_CURRENT_LIMIT		0x10
#define TMC7300Reg_PWMAB				0x22
#define TMC7300Reg_CHOPCONF			0x6c
#define TMC7300Reg_DRV_STATUS			0x6f
#define TMC7300Reg_PWMCONF			0x70

/* 具体作用请参考 datasheet */
typedef union 
{
	struct
	{
		uint8_t PWM_direct	:1;
		uint8_t extcap		:1;
		uint8_t par_mode	:1;
		uint8_t reserved0	:4;
		uint8_t test_mode	:1;
	}TEMP;
	uint8_t data;
}TMC_GCONF;

typedef union
{
	struct
	{
		uint8_t reset		:1;
		uint8_t drv_err		:1;
		uint8_t	u3v5		:1;
		uint8_t reserved	:5;
	}TEMP;
	uint8_t data;
}TMC_GSTAT;

typedef union
{
	struct
	{
		uint8_t	reserved0	:8;
		uint8_t senddelay	:4;
		uint8_t	reserved1	:4;
	}TEMP;
	uint16_t data;
}TMC_SLAVECONF;

typedef union
{
	struct
	{
		uint8_t EN			:1;
		uint8_t NSTDBY		:1;
		uint8_t AD0			:1;
		uint8_t AD1			:1;
		uint8_t DIAG		:1;
		uint8_t UART_1		:1;
		uint8_t URAT_IN		:1;
		uint8_t MODE		:1;
		uint8_t A2			:1;
		uint8_t A1			:1;
		uint8_t COMP_A1A2	:1;
		uint8_t COMP_B1B2	:1;
		uint8_t reserved0	:8;
		uint8_t reserved1	:4;
		uint8_t VERSION		:8;
	}TEMP;
}TMC_IOIN;

typedef union
{
	struct
	{
		uint8_t	motorrun	:1;
		uint8_t reserved0	:7;
		uint8_t IRUN		:5;
		uint8_t reserved1	:3;
	}TEMP;
	uint16_t data;
}TMC_CURRENTLIMIT;

typedef union
{
	struct
	{
		int16_t PWM_A		:9;
		int16_t reserved0	:7;
	 	int16_t PWM_B		:9;
		int16_t reserved1	:7;
	}TEMP;
	uint32_t data;
}TMC_PWMAB;

typedef union
{
	struct
	{
		uint16_t enabledrv	:1;
		uint16_t reserved0	:14;
		uint16_t TBL		:2;
		uint16_t reserved1	:7;
		uint16_t reserved2	:6;
		uint16_t diss2g		:1;
		uint16_t diss2vs	:1;
	}TEMP;
	uint32_t data;
}TMC_CHOPCONF;

typedef union
{
	struct
	{
		uint16_t otpw		:1;
		uint16_t ot			:1;
		uint16_t s2ga		:1;
		uint16_t s2gb		:1;
		uint16_t s2vsa		:1;
		uint16_t s2vsb		:1;
		uint16_t lia		:1;
		uint16_t lib		:1;
		uint16_t t150		:1;
		uint16_t t120		:1;
		uint16_t reserved0	:6;
		uint16_t reserved1	:16;
	}TEMP;
	uint32_t data;
}TMC_DRV_STATUS;

typedef union
{
	struct
	{
		uint16_t reserved0	:16;
		uint16_t PWM_freq	:2;
		uint16_t reserved1	:2;
		uint16_t freewhee	:2;
		uint16_t reserved2	:10;
	}TEMP;
	uint32_t data;
}TMC_PWMCONF;

extern void Drv_tmc7300_setCurrent(uint8_t addr,uint16_t current)；
extern void Drv_tmc7300_run(uint8_t addr,uint16_t speedA,uint16_t speedB)；
extern void Drv_tmc7300_Init(uint8_t addr);

#endif

