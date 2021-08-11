/*
 *��������: Drv_opb9000_sendLow()
 *��������: opb9000 �����ź� 0
 *��    ��: Smark.Zhang
 *�������: opb9000���
 *�� �� ֵ: 
 *����˵��: 
 */
void Drv_opb9000_sendLow(uint8_t index)
{	//  1 -> 0
	Bsp_opb9000_CAL_HIGH(index);
	Bsp_opb9000_delay5us();
	Bsp_opb9000_CAL_LOW(index);
	Bsp_opb9000_delay5us();
}

/*
 *��������: Drv_opb9000_sendHigh()
 *��������: opb9000 �����ź� 1
 *��    ��: Smark.Zhang
 *�������: opb9000���
 *�� �� ֵ: 
 *����˵��: 
 */
void Drv_opb9000_sendHigh(uint8_t index)
{	//  0 -> 1
	Bsp_opb9000_CAL_LOW(index);
	Bsp_opb9000_delay5us();
	Bsp_opb9000_CAL_HIGH(index);
	Bsp_opb9000_delay5us();	
}

/*
 *��������: Drv_opb9000_calibrateRequest()
 *��������: opb9000 ����У׼����
 *��    ��: Smark.Zhang
 *�������: opb9000���
 *�� �� ֵ: 
 *����˵��: 
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
 *��������: Drv_opb9000_calibrate()
 *��������: opb9000 У׼����
 *��    ��: Smark.Zhang
 *�������: opb9000���
 *�� �� ֵ: 0-ʧ��	��0-�ɹ�
 *����˵��: 
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
			Bsp_opb9000_interrupSet(1); // �ɹ�
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
 *��������: Drv_opb9000_writeRequest()
 *��������: opb9000 ����д����
 *��    ��: Smark.Zhang
 *�������: opb9000���
 *�� �� ֵ: 
 *����˵��: 
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
 *��������: Drv_opb9000_writeBank2()
 *��������: opb9000 дbank2
 *��    ��: Smark.Zhang
 *�������: index	opb9000 ���
 			outTye	�������
 			reference_level		LED�ȼ�
 *�� �� ֵ: 
 *����˵��: 
 */
void Drv_opb9000_writeBank2(uint8_t index,uint8_t outType,uint8_t reference_level)
{
	uint8_t i,data=0;

	data |= (outType<<4);
	data |= reference_level;
	data <<= 2;//��Чλ�����λ��ʼ

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
 *��������: Drv_opb9000_readRequest()
 *��������: opb9000 ������
 *��    ��: Smark.Zhang
 *�������: index opb9000���
 *�� �� ֵ: 
 *����˵��: 
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
 *��������: Drv_opb9000_readEeprom()
 *��������: ��ȡopb9000 eeprom��ֵ
 *��    ��: Smark.Zhang
 *�������: index	opb9000���
 			dataBuf	��ȡ�������ݵ�bufͷָ��
 *�� �� ֵ: 1 �ɹ�  0 ʧ��
 *����˵��: 
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
		cnt++;//�ȴ�
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

