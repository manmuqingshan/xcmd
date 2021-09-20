#include "delay.h"
#include "sys.h"
#include "include.h"


static u8  fac_us=0;							//us��ʱ������			   
static u16 fac_ms=0;							//ms��ʱ������,��os��,����ÿ�����ĵ�ms��
static uint32_t timerTick = 0;
 
static void(*tickIrqCallBackFun)(void) = NULL;
 
//systick�жϷ�����
void SysTick_Handler(void)
{	
    timerTick++;
    if(tickIrqCallBackFun)
    {
        tickIrqCallBackFun();
    }
}
			   
//��ʼ���ӳٺ���
void delay_init(u8 SYSCLK)
{
 	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);//SYSTICKʹ���ⲿʱ��Դ	 
	fac_us=SYSCLK;						//�����Ƿ�ʹ��OS,fac_us����Ҫʹ��
	fac_ms=(u16)fac_us*1000;				//��OS��,����ÿ��ms��Ҫ��systickʱ����
    SysTick_Config(SystemCoreClock / 1000);
}								    

//��ʱnus
//nusΪҪ��ʱ��us��.	
//ע��:nus��ֵ,��Ҫ����798915us(���ֵ��2^24/fac_us@fac_us=21)
void delay_us(uint32_t nus)
{		
	uint32_t ticks;
	uint32_t told,tnow,tcnt=0;
	uint32_t reload=SysTick->LOAD;				//LOAD��ֵ	    	 
	ticks=nus*fac_us; 						//��Ҫ�Ľ����� 
	told=SysTick->VAL;        				//�ս���ʱ�ļ�����ֵ
	while(1)
	{
		tnow=SysTick->VAL;	
		if(tnow!=told)
		{	    
			if(tnow<told)tcnt+=told-tnow;	//����ע��һ��SYSTICK��һ���ݼ��ļ������Ϳ�����.
			else tcnt+=reload-tnow+told;	    
			told=tnow;
			if(tcnt>=ticks)break;			//ʱ�䳬��/����Ҫ�ӳٵ�ʱ��,���˳�.
		}  
	};
}

//��ʱnms 
void delay_ms(uint32_t nms)
{	 	 
    uint32_t nextTime;
    nextTime = timerTick+nms;
    
    do
    {
        if(nextTime == timerTick)
        {
            break;
        }
    }while(1);
}

void getTick(uint32_t *recTick)
{
    *recTick = timerTick;
}

uint32_t millins(void)
{
    return timerTick;
}

uint64_t microseconds(void)
{
    return timerTick*1000 + (SysTick->LOAD-SysTick->VAL);
}

uint32_t getLapseTime(uint32_t oldTime, uint32_t newTime)
{
    uint32_t ret;
    if(newTime<oldTime)
    {
        ret = (0xFFFFFFFF - oldTime) + newTime;
    }
    else
    {
        ret = newTime - oldTime;
    }
    return ret;
}

void regSysTickCallBackFun(void(*callBackFun)(void))
{
    tickIrqCallBackFun = callBackFun;
}

