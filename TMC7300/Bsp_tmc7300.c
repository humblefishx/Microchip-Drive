/*
 *函数名称: Bsp_tmc7300_interruptSet()
 *功能描述: 开关中断
 *作	者: 	Smark.Zhang
 *输入参数: 
 *返 回 值: 
 *其他说明: 
 */
void Bsp_tmc7300_interruptSet(uint8_t status)
{
	if(status)
	{
		// 实现关全局中断
	}
	else
	{
		// 实现开全局中断
	}
}

/*
 *函数名称: Bsp_tmc7300_sendByte()
 *功能描述: tmc7300发送字节
 *作	者: 	Smark.Zhang
 *输入参数: 
 *返 回 值: 
 *其他说明: 
 */
void Bsp_tmc7300_sendByte(uint8_t byte)
 {
 	// 实现串口发送一个字节
 }

/*
 *函数名称: Bsp_tmc7300_readByte()
 *功能描述: tmc7300接受字节
 *作	者: 	Smark.Zhang
 *输入参数: 
 *返 回 值: 
 *其他说明: 
 */
uint8_t Bsp_tmc7300_readByte(void)
 {
 	// 实现串口接受一个字节
 }

/*
 *函数名称: Bsp_tmc7300_enable()
 *功能描述: 进入和退出standby模式
 *作	者: 	Smark.Zhang
 *输入参数: status 0-进入standby		非0-退出standby
 *返 回 值: 
 *其他说明: 
 */
void Bsp_tmc7300_enable(uint8_t status)
{
	if(status)
	{
		//EN 脚拉高
	}
	else
	{
		//EN 脚置低
	}
}

/*
 *函数名称: Bsp_tmc7300_delay()
 *功能描述: 延时
 *作	者: 	Smark.Zhang
 *输入参数: ms 延时毫秒数
 *返 回 值: 
 *其他说明: 
 */
void Bsp_tmc7300_delay(uint16_t ms)
{
	// 实现延时，ms毫秒
}


