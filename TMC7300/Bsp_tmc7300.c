/*
 *��������: Bsp_tmc7300_interruptSet()
 *��������: �����ж�
 *��	��: 	Smark.Zhang
 *�������: 
 *�� �� ֵ: 
 *����˵��: 
 */
void Bsp_tmc7300_interruptSet(uint8_t status)
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
 *��������: Bsp_tmc7300_sendByte()
 *��������: tmc7300�����ֽ�
 *��	��: 	Smark.Zhang
 *�������: 
 *�� �� ֵ: 
 *����˵��: 
 */
void Bsp_tmc7300_sendByte(uint8_t byte)
 {
 	// ʵ�ִ��ڷ���һ���ֽ�
 }

/*
 *��������: Bsp_tmc7300_readByte()
 *��������: tmc7300�����ֽ�
 *��	��: 	Smark.Zhang
 *�������: 
 *�� �� ֵ: 
 *����˵��: 
 */
uint8_t Bsp_tmc7300_readByte(void)
 {
 	// ʵ�ִ��ڽ���һ���ֽ�
 }

/*
 *��������: Bsp_tmc7300_enable()
 *��������: ������˳�standbyģʽ
 *��	��: 	Smark.Zhang
 *�������: status 0-����standby		��0-�˳�standby
 *�� �� ֵ: 
 *����˵��: 
 */
void Bsp_tmc7300_enable(uint8_t status)
{
	if(status)
	{
		//EN ������
	}
	else
	{
		//EN ���õ�
	}
}

/*
 *��������: Bsp_tmc7300_delay()
 *��������: ��ʱ
 *��	��: 	Smark.Zhang
 *�������: ms ��ʱ������
 *�� �� ֵ: 
 *����˵��: 
 */
void Bsp_tmc7300_delay(uint16_t ms)
{
	// ʵ����ʱ��ms����
}


