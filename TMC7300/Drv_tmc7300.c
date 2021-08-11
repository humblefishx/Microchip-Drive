/*
  *函数名称: Drv_tmc7300_writeReg()
  *功能描述: tmc7300写寄存器
  *作	 者: Smark.Zhang
  *输入参数: addr	 tmc7300地址 A1，A2 PIN确定
			 reg	 寄存器
			 data	 需要写入的值
  *返 回 值: void
  *其他说明: 
  */
 static void Drv_tmc7300_writeReg(uint8_t addr,uint8_t reg,uint32_t data)
 {
	 uint8_t i;
	 uint8_t sendBuf[8]={0,0,0,0,0,0,0,0};
	 sendBuf[0]= 0x05;			 // sync+reserved		 1010 0000
	 sendBuf[1]= addr;			 // slave address
	 sendBuf[2]= 0x80 | reg;	 // RW + 7 bits register addr
	 sendBuf[3]= (data>>24)& 0xff;
	 sendBuf[4]= (data>>16)& 0xff;
	 sendBuf[5]= (data>>8)& 0xff;
	 sendBuf[6]= data& 0xff;
	 sendBuf[7]= Drv_tmc7300_CRC(sendBuf,7);
	 
	 Bsp_tmc7300_interruptSet(0);//关中断	 避免操作系统中调度，打断传输
	 for(i=0;i<8;i++)
	 {
		 Bsp_tmc7300_sendByte(sendBuf[i]);
	 }
	 Bsp_tmc7300_interruptSet(1);//开中断
 }

 /*
  *函数名称: Drv_tmc7300_writeReg()
  *功能描述: tmc7300写寄存器
  *作	 者: Smark.Zhang
  *输入参数: addr	 tmc7300地址 A1，A2 PIN确定
			 reg	 寄存器
  *返 回 值: 读取的寄存器信息
  *其他说明: 
  */

 static uint32_t Drv_tmc7300_readReg(uint8_t addr,uint8_t reg)
 {
	 uint8_t i;
	 uint8_t Buf[8]={0,0,0,0,0,0,0,0};
	 Buf[0]= 0x05;
	 Buf[1]= addr;
	 Buf[2]= 0x7f & reg; 
	 Buf[3]= Drv_tmc7300_CRC(Buf,3);
	 
	 Bsp_tmc7300_interruptSet(0);
	 for(i=0;i<4;i++)
	 {
		 Bsp_tmc7300_sendByte(Buf[i]);
	 }
	 
	 for(i=0;i<8;i++)
	 {
		 Buf[i]= Bsp_tmc7300_readByte();
	 }
	 Bsp_tmc7300_interruptSet(1);
	 
	 return *((uint32_t*)(Buf+3));
 }
 
 /*
 *函数名称: Drv_tmc7300_CRC()
 *功能描述: 计算CRC值
 *作    者: Smark.Zhang
 *输入参数: data	参数头指针
 			len		参数长度
 *返 回 值: CRC值
 *其他说明: 
 */
 static uint8_t Drv_tmc7300_CRC(uint8_t * ptr,uint8_t len)
 {
	 uint8_t i, j;
	 unsigned char crc;// = datagram[datagramLength - 1]; // CRC located in last byte of message
	 unsigned char currentByte;
	 crc = 0;
	 for (i = 0; i < (len); i++) 
	 { 
		 currentByte = ptr[i]; 
		 for (j = 0; j < 8; j++) 
		 {
			 if ((crc >> 7) ^ (currentByte & 0x01)) 
			 {
				 crc = (crc << 1) ^ 0x07;
			 }
			 else
			 {
				 crc = (crc << 1);
			 }
			 currentByte = currentByte >> 1;
		 } // for CRC bit
	 } // for message byte
	 return (crc);
 }
 
 static void Drv_tmc7300_setGCONF(uint8_t addr,uint8_t pwm_direct,uint8_t extcap,uint8_t par_mode,uint8_t test_mode)
 {
	 TMC_GCONF config;
	 
	 memset(&config,0,sizeof(TMC_GCONF));
	 config.TEMP.PWM_direct= pwm_direct;
	 config.TEMP.extcap= extcap;
	 config.TEMP.par_mode= par_mode;
	 config.TEMP.test_mode= test_mode;
	 
	 Drv_tmc7300_writeReg(addr,TMC7300Reg_GCONF,(uint32_t)config.data);
 }
 
 static void Drv_tmc7300_setGSTAT(uint8_t addr,uint8_t reset,uint8_t drv_err,uint8_t u3v5)
 {
	 TMC_GSTAT gStat;
	 
	 memset(&gStat,0,sizeof(gStat));
	 gStat.TEMP.reset= reset;
	 gStat.TEMP.drv_err= drv_err;
	 gStat.TEMP.u3v5= u3v5;
 
	 Drv_tmc7300_writeReg(addr,TMC7300Reg_GSTAT,(uint32_t)gStat.data);
 }
 
 static void Drv_tmc7300_setSLAVECONF(uint8_t addr,uint8_t senddelay)
 {
	 TMC_SLAVECONF slaveConf;
 
	 memset(&slaveConf,0,sizeof(TMC_SLAVECONF));
	 slaveConf.TEMP.senddelay= senddelay;
	 
	 Drv_tmc7300_writeReg(addr,TMC7300Reg_SLAVECONF,(uint32_t)slaveConf);	 
 }

  /*
  *函数名称: App_tmc7300_setPWM()
  *功能描述: 设置tmc7300的运行电流
  *作	 者: 	Smark.Zhang
  *输入参数: 	pwmA	A相电机运行PWM
  				pwmB	B相电机运行的PWM
  *返 回 值: 
  *其他说明: 	PWM值 正负代表方向，数值大小为:0-255， 255速度最大
			
  */
 static void Drv_tmc7300_setPWM(uint8_t addr,uint16_t pwmA,uint16_t pwmB)
 {
	 TMC_PWMAB pwm;
 
	 memset(&pwm,0,sizeof(TMC_PWMAB));
	 pwm.TEMP.PWM_A= pwmA;
	 pwm.TEMP.PWM_B= pwmB;
 
	 Drv_tmc7300_writeReg(addr,TMC7300Reg_PWMAB,(uint32_t)pwm.data);
 }
 
 /*
  *函数名称: Drv_tmc7300_SetCurrent()
  *功能描述: 设置tmc7300的运行电流
  *作	 者: Smark.Zhang
  *输入参数: 
  *返 回 值: 
  *其他说明: 每个芯片设置，芯片控制的两个电机是同一个电流	 
			 电阻为 0.15Ω
  */
 void Drv_tmc7300_setCurrent(uint8_t addr,uint16_t current)
 {
	 uint8_t IRUN=0;
	 double voltage= 325,res= 150 + 30;
	 double temp;
	 TMC_CURRENTLIMIT limit;
 
	 temp= current;
	 temp /= 1000;
	 temp= temp*32*res/voltage;
	 IRUN= temp-1;
	 
	 limit.TEMP.motorrun= 1;
	 limit.TEMP.IRUN= IRUN;
	 Drv_tmc7300_writeReg(addr,TMC7300Reg_CURRENT_LIMIT,(uint32_t)limit.data);//设置电流
 }

 void Drv_tmc7300_run(uint8_t addr,uint16_t speedA,uint16_t speedB)
 {
	 Drv_tmc7300_setPWM(addr,speedA,speedB);
 }

 /*
  *函数名称: App_tmc7300_Init()
  *功能描述: 初始化TMC7300驱动
  *作	 者: Smark.Zhang
  *输入参数: 
  *返 回 值: 
  *其他说明: 
  */
 void Drv_tmc7300_Init(uint8_t addr)
 {
	 uint8_t i;
 
	Bsp_tmc7300_enable(0);	 //CLOSE
	
	Bsp_tmc7300_delay(2);
	Drv_tmc7300_setGCONF(addr,0x01,0x01,0x00,0x00);
	Bsp_tmc7300_delay(2);
	Drv_tmc7300_setGSTAT(addr,0x00,0x00,0x00);
	Bsp_tmc7300_delay(2);
	Drv_tmc7300_setSLAVECONF(addr,0x00);
	Bsp_tmc7300_delay(2);
	Drv_tmc7300_setCurrent(addr,500);//  力矩电流最大为 500ma
	Bsp_tmc7300_delay(2);
	Drv_tmc7300_setPWM(addr,0x00,0x00);// 左右电机都停止

	Bsp_tmc7300_enable(1);	 //OPEN  
 }


