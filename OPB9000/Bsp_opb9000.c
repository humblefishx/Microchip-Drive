/*
 *��������: Bsp_opb9000_interrupSet()
 *��������: �����ж�
 *��    ��: Smark.Zhang
 *�������: 
 *�� �� ֵ: 
 *����˵��: 
 */
void Bsp_opb9000_interrupSet(uint8_t status)
{
	if(status)
	{
		// ʵ�ֹ�ȫ���ж�
	}
	else
	{
		// ʵ�ֿ�ȫ���ж�
	}
}

/*
 *��������: Bsp_opb9000_delay1us()
 *��������: ��ʱ1us
 *��    ��: Smark.Zhang
 *�������: 
 *�� �� ֵ: 
 *����˵��: 5us �� num��ֵ����5
 */
void Bsp_opb9000_delay1us()
{
	uint8_t num= 8;
	uint16_t i;
	for(i=0;i<num;i++)
	{
			;
	}
}

/*
 *��������: Bsp_opb9000_delay5us()
 *��������: ��ʱ5us
 *��    ��: Smark.Zhang
 *�������: 
 *�� �� ֵ: 
 *����˵��: ��Ҫʹ��ʾ����ȷ������ķ����ǲ���5us,�Ӷ�ȷ��num����ֵ
 */
void Bsp_opb9000_delay5us()
{
	uint8_t num= 30;
	uint16_t i;
	for(i=0;i<num;i++)
	{
			;
	}
}

/*
 *��������: Bsp_opb9000_CAL_HIGH()
 *��������: ����opb9000 CAL��Ϊ�ߵ�ƽ
 *��    ��: Smark.Zhang
 *�������: index opb9000���
 *�� �� ֵ: 
 *����˵��: 
 */
void Bsp_opb9000_CAL_HIGH(uint8_t index)
{
	// ʵ�� cal��������ߵ�ƽ
}

/*
 *��������: Bsp_opb9000_CAL_LOW()
 *��������: ����opb9000 CAL��Ϊ�͵�ƽ
 *��    ��: Smark.Zhang
 *�������: index opb9000���
 *�� �� ֵ: 
 *����˵��: 
 */
void Bsp_opb9000_CAL_LOW(uint8_t index)
{
	// ʵ�� cal��������͵�ƽ
}

/*
 *��������: Bsp_opb9000_CAL_DIR()
 *��������: ����opb9000 CAL�ŷ���
 *��    ��: Smark.Zhang
 *�������: index opb9000���		dir �˿ڷ���  0 ���  1 ����
 *�� �� ֵ: 
 *����˵��: 
 */
void Bsp_opb9000_CAL_DIR(uint8_t index,uint8_t dir)
{
	// ʵ�� cal���ŷ�������
}

/*
 *��������: Bsp_opb9000_CAL_READ()
 *��������: ��ȡopb9000 CAL�ŵ�ƽ
 *��    ��: Smark.Zhang
 *�������: index opb9000���
 *�� �� ֵ: 
 *����˵��: 
 */
uint8_t Bsp_opb9000_CAL_READ(uint8_t index)
{
	// ʵ��cal���Ŷ���ƽ����
}

/*
 *��������: Bsp_opb9000_OUT_DIR()
 *��������: ����opb9000 OUT�ŷ���
 *��    ��: Smark.Zhang
 *�������: index opb9000���		dir �˿ڷ���  0 ���  1 ����
 *�� �� ֵ: 
 *����˵��: 
 */
void Bsp_opb9000_OUT_DIR(uint8_t index,uint8_t dir)
{
	// ʵ�� out���ŷ�������
}

/*
 *��������: Bsp_opb9000_outRead()
 *��������: ��ȡ��������ŵ�ƽ
 *��    ��: Smark.Zhang
 *�������: index opb9000���
 *�� �� ֵ: 
 *����˵��: 
 */
uint8_t Bsp_opb9000_outRead(uint8_t index)
{
	// ʵ��out���Ŷ���ƽ����

}

/*
 *��������: Bsp_opb9000_configure()
 *��������: opb9000 ��ʼ��
 *��    ��: Smark.Zhang
 *�������: 
 *�� �� ֵ: 
 *����˵��: 
 */
void Bsp_opb9000_configure(void)
{	
	// ���ų�ʼ���� CAL�������ó�������� OUT��������Ϊ��������
}


