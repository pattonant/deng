#include <STC8G.H>

#include <stdio.h>



sbit LED = P2^3;//����ԭ��ͼ����·ͼ�����豸����led2ָ��P3��IO�ڵĵ�6��
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
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;
	TH0 = 0;
	TL0 = 0;
	
	
	
	//���ö�ʱ��0����ģʽ1����ʼֵ�趨0��ʼ���������ż�������ʱ��
}


/*
ʮ����2����1λ�����20���൱�ڳ���10
����ֹ1����1λ�����10��2�����൱�ڳ���2������8λ������2��8�η�=256��*/
 
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


	
	
	

EA=1;                  //�����ж�
	ET0=1;                 //��ʱ��T0�ж�����         
	TMOD=0x01;             //ʹ�ö�ʱ��T0��ģʽ2
	TH0=(65536-46083)/256; //��ʱ��T0�ĸ�8λ����ֵ
	TL0=(65536-46083)%256; //��ʱ��T0�ĸ�8λ����ֵ
	EX0=1; //�����ⲿ�ж�
	IT1=1;
	EX1=1;
	
	

	TR0=1;                 //������ʱ��T0
		
		
		
	

	Time0Init();
	
	while(1){
		
		
		//1. �������Ͳ�����Trig�˿�����10us�ĸߵ�ƽ
		startHC();
		//2. ��ʼ���Ͳ���Echo�ź��ɵ͵�ƽ��ת���ߵ�ƽ
		while(Echo == 0);
		//   ��ʼ���Ͳ���������ʱ��
		TR0 = 1;
		//3. ���շ��ز���Echo�ź��ɸߵ�ƽ��ת�ص͵�ƽ
		while(Echo == 1);
		//   ���շ��ز���ֹͣ��ʱ��
		TR0 = 0;
		//4. ����ʱ��
		
		time = (TH0 * 256 + TL0)*1.085;//usΪ��λ
		//5. ���� = �ٶ� ��340m/s��* ʱ��/2
		dis = time * 0.017;
		
		if(dis < 35){
				LED = 0;
		
			
				
		}
		
		else{
				LED = 1;
			
			
				
		}
	
		
		
		
		
		
		
		
		
		
			
		
		
		
			
		
		
		
			
		
	
		
		//��ʱ���������㣬�Ա���һ�β��
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



		
		
