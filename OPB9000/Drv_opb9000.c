/*
 *函数名称: Drv_opb9000_sendLow()
 *功能描述: opb9000 发送信号 0
 *作    者: Smark.Zhang
 *输入参数: opb9000编号
 *返 回 值: 
 *其他说明: 
 */
void Drv_opb9000_sendLow(uint8_t index)
{	//  1 -> 0
	Bsp_opb9000_CAL_HIGH(index);
	Bsp_opb9000_delay5us();
	Bsp_opb9000_CAL_LOW(index);
	Bsp_opb9000_delay5us();
}

/*
 *函数名称: Drv_opb9000_sendHigh()
 *功能描述: opb9000 发送信号 1
 *作    者: Smark.Zhang
 *输入参数: opb9000编号
 *返 回 值: 
 *其他说明: 
 */
void Drv_opb9000_sendHigh(uint8_t index)
{	//  0 -> 1
	Bsp_opb9000_CAL_LOW(index);
	Bsp_opb9000_delay5us();
	Bsp_opb9000_CAL_HIGH(index);
	Bsp_opb9000_delay5us();	
}

/*
 *函数名称: Drv_opb9000_calibrateRequest()
 *功能描述: opb9000 发送校准请求
 *作    者: Smark.Zhang
 *输入参数: opb9000编号
 *返 回 值: 
 *其他说明: 
 */
void Drv_opb9000_calibrateRequest(uint8_t index)
{
	uint8_t cmd = 0x33; // Command:1100-11
	uint8_t i;

	cmd = cmd << 2;
	for (i = 0; i < 6; i++)
	{
		if (cmd & 0x80)
		{
			Drv_opb9000_sendHigh(index);
		}
		else
		{
			Drv_opb9000_sendLow(index);
		}
		cmd = cmd << 1;
	}	
}

/*
 *函数名称: Drv_opb9000_calibrate()
 *功能描述: opb9000 校准操作
 *作    者: Smark.Zhang
 *输入参数: opb9000编号
 *返 回 值: 0-失败	非0-成功
 *其他说明: 
 */
uint8_t Drv_opb9000_calibrate(uint8_t index)
{
 	uint8_t tmp=0;
	uint16_t i=4000;

	Bsp_opb9000_interrupSet(0);
	Bsp_opb9000_CAL_HIGH(index);
	
	Drv_opb9000_calibrateRequest(index);
	
	Bsp_opb9000_CAL_DIR(index,1);
	Bsp_opb9000_CAL_READ(index);
	Bsp_opb9000_delay5us();

	while(i)   
	{
		tmp=Bsp_opb9000_CAL_READ(index);
		if (tmp == 0) // wait for CAL going to low
		{
			Bsp_opb9000_CAL_DIR(index,0);
			Bsp_opb9000_CAL_HIGH(index);
			Bsp_opb9000_interrupSet(1); // 成功
			return 1;
		}
		i--;
		Bsp_opb9000_delay5us();
	}
	
	Bsp_opb9000_CAL_DIR(index,0);
	Bsp_opb9000_CAL_HIGH(index);
	
	Bsp_opb9000_interrupSet(1);
	
	return 0;	
}

/*
 *函数名称: Drv_opb9000_writeRequest()
 *功能描述: opb9000 发送写请求
 *作    者: Smark.Zhang
 *输入参数: opb9000编号
 *返 回 值: 
 *其他说明: 
 */
void Drv_opb9000_writeRequest(uint8_t index)
{
	uint8_t cmd= 0x32;// 1100 10
	uint8_t i;
	cmd= cmd<<2;
	for(i=0;i<6;i++)
	{
		if(cmd & 0x80)
		{
			Drv_opb9000_sendHigh(index);
		}
		else
		{
			Drv_opb9000_sendLow(index);
		}
		cmd= cmd<<1;
	}
}

/*
 *函数名称: Drv_opb9000_writeBank2()
 *功能描述: opb9000 写bank2
 *作    者: Smark.Zhang
 *输入参数: index	opb9000 编号
 			outTye	输出类型
 			reference_level		LED等级
 *返 回 值: 
 *其他说明: 
 */
void Drv_opb9000_writeBank2(uint8_t index,uint8_t outType,uint8_t reference_level)
{
	uint8_t i,data=0;

	data |= (outType<<4);
	data |= reference_level;
	data <<= 2;//有效位从最高位开始

	Bsp_opb9000_interrupSet(0);
	Bsp_opb9000_CAL_HIGH(index);
	
	Drv_opb9000_writeRequest(index);
	
	for(i=0;i<6;i++)
	{
		if(data & 0x80)
		{
			Drv_opb9000_sendHigh(index);
		}
		else
		{
			Drv_opb9000_sendLow(index);
		}
		data<<= 1;
	}
	Bsp_opb9000_delay5us();
	
	Bsp_opb9000_interrupSet(1);
}

/*
 *函数名称: Drv_opb9000_readRequest()
 *功能描述: opb9000 读请求
 *作    者: Smark.Zhang
 *输入参数: index opb9000编号
 *返 回 值: 
 *其他说明: 
 */
void Drv_opb9000_readRequest(uint8_t index)
{
	uint8_t	cmd= 0x31;// 1100 01 
	uint8_t i;

	cmd <<= 2;
	for(i=0;i<6;i++)
	{
		if(cmd & 0x80)
		{
			Drv_opb9000_sendHigh(index);
		}
		else
		{
			Drv_opb9000_sendLow(index);
		}
		cmd<<= 1;
	}
}

/*
 *函数名称: Drv_opb9000_readEeprom()
 *功能描述: 读取opb9000 eeprom的值
 *作    者: Smark.Zhang
 *输入参数: index	opb9000编号
 			dataBuf	存取读到数据的buf头指针
 *返 回 值: 1 成功  0 失败
 *其他说明: 
 */
uint8_t Drv_opb9000_readEeprom(uint8_t index,OPB9000_EEPROM *dataBuf)
{
	uint16_t cnt= 0;
	uint8_t i,nDelay,Pinback;
	uint8_t buf[37];
	
	Bsp_opb9000_interrupSet(0);
	Bsp_opb9000_OUT_DIR(index,1);	
	Bsp_opb9000_CAL_HIGH(index);
	
	Drv_opb9000_readRequest(index);
	
	while (Bsp_opb9000_outRead(index)== 0)
	{
		cnt++;//等待
		if(cnt>= 0x7fff)
		{
			break;
		}
	}

	for (i=0; i<37; i++)
	{
		nDelay = 0;
		Pinback = Bsp_opb9000_outRead(index);
		while (Pinback == Bsp_opb9000_outRead(index))
		{
			Bsp_opb9000_delay1us(); 
			nDelay++;
			if (nDelay > 5) 
			{
				Bsp_opb9000_interrupSet(1);
				return 0; //fails
			}
		}
		Pinback = Bsp_opb9000_outRead(index);
		buf[i]= Pinback;		
		Bsp_opb9000_delay5us();
	}

	Bsp_opb9000_interrupSet(1);
	
	dataBuf->startFlag= buf[0];
	dataBuf->erroeFlag= buf[1];
	dataBuf->CABit= buf[11];
	dataBuf->AGCBit= buf[13]<<1 | buf[12];

	for(i=0;i<10;i++)
	{
		dataBuf->ledCount<<= 1;
		dataBuf->ledCount|= buf[23-i];
	}
	for(i=0;i<4;i++)
	{
		dataBuf->refLevel<<= 1;	
		dataBuf->refLevel|= buf[27-i];	
	}
	dataBuf->DSBit= buf[28];
	dataBuf->OPBit= buf[29];

	return 1; // receiving succeeds	
}

