#include <STC8G.H>

#include <stdio.h>



sbit LED = P2^3;//根据原理图（电路图），设备变量led2指向P3组IO口的第6口
sbit Trig = P5^4;
sbit Echo = P5^3;
sbit LED1=P5^5;
sbit H=P4^4;




	 




 
void Delay10us()		//@11.0592MHz
{
	unsigned char i;
 
	i = 2;
	
	while (--i);
	

}





 
void Time0Init()
{	
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;
	TH0 = 0;
	TL0 = 0;
	
	
	
	//设置定时器0工作模式1，初始值设定0开始数数，不着急启动定时器
}


/*
十进制2左移1位，变成20。相当于乘以10
二禁止1左移1位，变成10（2）。相当于乘以2，左移8位，乘以2的8次方=256；*/
 
void startHC()
{
	Trig = 0;
	Trig = 1;
	Delay10us();
	Trig = 0;
	
}
void delayxx(unsigned long timee)
{
	unsigned long x,m;
	for(x=0;x<timee;x++)
		for(m=0;m<19;m++)
		{}
}


void main()
{
	
	
	double time;
	double dis;

	   P5M0 = 0x00; P5M1 = 0x00; 
	    P2M0 = 0x00; P2M1 = 0x00; 
	    
    P5M0 = 0x24; P5M1 = 0x00; 


	
	
	

EA=1;                  //开总中断
	ET0=1;                 //定时器T0中断允许         
	TMOD=0x01;             //使用定时器T0的模式2
	TH0=(65536-46083)/256; //定时器T0的高8位赋初值
	TL0=(65536-46083)%256; //定时器T0的高8位赋初值
	EX0=1; //启动外部中断
	IT1=1;
	EX1=1;
	
	

	TR0=1;                 //启动定时器T0
		
		
		
	

	Time0Init();
	
	while(1){
		
		
		//1. 让它发送波：给Trig端口至少10us的高电平
		startHC();
		//2. 开始发送波：Echo信号由低电平跳转到高电平
		while(Echo == 0);
		//   开始发送波，启动定时器
		TR0 = 1;
		//3. 接收返回波：Echo信号由高电平跳转回低电平
		while(Echo == 1);
		//   接收返回波，停止定时器
		TR0 = 0;
		//4. 计算时间
		
		time = (TH0 * 256 + TL0)*1.085;//us为单位
		//5. 距离 = 速度 （340m/s）* 时间/2
		dis = time * 0.017;
		
		if(dis < 35){
				LED = 0;
		
			
				
		}
		
		else{
				LED = 1;
			
			
				
		}
	
		
		
		
		
		
		
		
		
		
			
		
		
		
			
		
		
		
			
		
	
		
		//定时器数据清零，以便下一次测距
		TH0 = 0;
		TL0 = 0;
		
		
		
		if(H==0)
		{
			P55 = 1;
		}
		
		else
		{
			P55 = 0;
		}
		
		
}
}



		
		
