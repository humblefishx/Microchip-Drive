/*
 *函数名称: Bsp_opb9000_interrupSet()
 *功能描述: 开关中断
 *作    者: Smark.Zhang
 *输入参数: 
 *返 回 值: 
 *其他说明: 
 */
void Bsp_opb9000_interrupSet(uint8_t status)
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
 *函数名称: Bsp_opb9000_delay1us()
 *功能描述: 延时1us
 *作    者: Smark.Zhang
 *输入参数: 
 *返 回 值: 
 *其他说明: 5us 中 num数值除以5
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
 *函数名称: Bsp_opb9000_delay5us()
 *功能描述: 延时5us
 *作    者: Smark.Zhang
 *输入参数: 
 *返 回 值: 
 *其他说明: 需要使用示波器确认输出的方波是不是5us,从而确定num的数值
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
 *函数名称: Bsp_opb9000_CAL_HIGH()
 *功能描述: 设置opb9000 CAL脚为高电平
 *作    者: Smark.Zhang
 *输入参数: index opb9000编号
 *返 回 值: 
 *其他说明: 
 */
void Bsp_opb9000_CAL_HIGH(uint8_t index)
{
	// 实现 cal引脚输出高电平
}

/*
 *函数名称: Bsp_opb9000_CAL_LOW()
 *功能描述: 设置opb9000 CAL脚为低电平
 *作    者: Smark.Zhang
 *输入参数: index opb9000编号
 *返 回 值: 
 *其他说明: 
 */
void Bsp_opb9000_CAL_LOW(uint8_t index)
{
	// 实现 cal引脚输出低电平
}

/*
 *函数名称: Bsp_opb9000_CAL_DIR()
 *功能描述: 设置opb9000 CAL脚方向
 *作    者: Smark.Zhang
 *输入参数: index opb9000编号		dir 端口方向  0 输出  1 输入
 *返 回 值: 
 *其他说明: 
 */
void Bsp_opb9000_CAL_DIR(uint8_t index,uint8_t dir)
{
	// 实现 cal引脚方向设置
}

/*
 *函数名称: Bsp_opb9000_CAL_READ()
 *功能描述: 获取opb9000 CAL脚电平
 *作    者: Smark.Zhang
 *输入参数: index opb9000编号
 *返 回 值: 
 *其他说明: 
 */
uint8_t Bsp_opb9000_CAL_READ(uint8_t index)
{
	// 实现cal引脚读电平操作
}

/*
 *函数名称: Bsp_opb9000_OUT_DIR()
 *功能描述: 设置opb9000 OUT脚方向
 *作    者: Smark.Zhang
 *输入参数: index opb9000编号		dir 端口方向  0 输出  1 输入
 *返 回 值: 
 *其他说明: 
 */
void Bsp_opb9000_OUT_DIR(uint8_t index,uint8_t dir)
{
	// 实现 out引脚方向设置
}

/*
 *函数名称: Bsp_opb9000_outRead()
 *功能描述: 获取光耦输出脚电平
 *作    者: Smark.Zhang
 *输入参数: index opb9000编号
 *返 回 值: 
 *其他说明: 
 */
uint8_t Bsp_opb9000_outRead(uint8_t index)
{
	// 实现out引脚读电平操作

}

/*
 *函数名称: Bsp_opb9000_configure()
 *功能描述: opb9000 初始化
 *作    者: Smark.Zhang
 *输入参数: 
 *返 回 值: 
 *其他说明: 
 */
void Bsp_opb9000_configure(void)
{	
	// 引脚初始化， CAL引脚设置成推挽输出 OUT引脚设置为浮空输入
}


