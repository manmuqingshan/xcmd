#ifndef __DEBUG_DEBUG_H_
#define __DEBUG_DEBUG_H_

#include "stdio.h"	
#include "stm32f4xx_conf.h"
#include "sys.h"

	#if !defined DEBUG_LEVEL_H && !defined DEBUG_LEVEL_M && !defined DEBUG_LEVEL_L && !defined DEBUG_LEVEL_NONE
		/*****************************************************************/ 
		#define DEBUG_LEVEL_L //����Ĭ����ʾ��־�ļ��� 
		/*****************************************************************/ 
	#endif
	
	#ifdef DEBUG_FULL_DIS //��ʾ��ϸ��Ϣ 
		#define _DEBUG(format,arg...)	 printf("FUN:%-10s " "LINE:%-4d ==>"format, __FUNCTION__  ,__LINE__, ##arg)
	#else  //ֻ��ʾ������������� 
		#define _DEBUG(format,arg...)	 printf(format, ##arg)
	#endif
	
	#ifdef DEBUG_LEVEL_H //ֻ��ʾ��߼������־ 
		#define DEBUG_H(format,arg...)	_DEBUG(format, ##arg)
		#define DEBUG_M(format,arg...)	((void)0) 
		#define DEBUG_L(format,arg...)	((void)0) 
	#endif
	
	#ifdef DEBUG_LEVEL_M //��ʾ��ߺ��е����ȼ���־ 
		#define DEBUG_H(format,arg...)	_DEBUG(format, ##arg)
		#defi ne DEBUG_M(format,arg...)	_DEBUG(format, ##arg)
		#define DEBUG_L(format,arg...)	((void)0) 
	#endif 
	
	#ifdef DEBUG_LEVEL_L //ȫ����ʾ
		#define DEBUG_H(format,arg...)	_DEBUG(format, ##arg)
		#define DEBUG_M(format,arg...)	_DEBUG(format, ##arg)
		#define DEBUG_L(format,arg...)	_DEBUG(format, ##arg)
	#endif
	
	#ifdef DEBUG_LEVEL_NONE //������ʾ
		#define DEBUG_H(format,arg...)	((void)0) 
		#define DEBUG_M(format,arg...)	((void)0) 
		#define DEBUG_L(format,arg...)	((void)0)
	#endif


#define DEBUG(format,arg...)	DEBUG_L(format,##arg)	

#define configLIBRARY_KERNEL_INTERRUPT_PRIORITY 6
#define EN_USART1_RX 1

/*
ʹ�ø�ʽΪ�� printf("\033[�ֱ�����ɫ;������ɫm�ַ���\033[0m" ); 

    ���磺printf("\033[47;31mhello world\033[5m");
   47���ֱ�����ɫ, 31���������ɫ, hello world���ַ���.  �����\033[5m�ǿ�����.
��ɫ����:
�ֱ�����ɫ��Χ: 40--49     ����ɫ: 30--39
                40: ��                           30: ��
                41: ��                           31: ��
                42: ��                           32: ��
                43: ��                           33: ��
                44: ��                           34: ��
                45: ��                           35: ��
                46: ����                         36: ����
*/
typedef enum
{
    _BLACK,
    _RED,
    _GREEN,
    _YELLOW,
    _BLUE,
    _PURPLE,
    _DARKGREEN
}LogColor_e;

#define PLOG(backColor, foregColor,format,arg...)     printf("\033[1m\033[%d;%dm" format " \033[0m\r\n",40+backColor,color+foregColor, ##arg)
#define PINFO(format,arg...)         printf(format"\r\n", ##arg)
#define PSUCCEED(format,arg...)      printf("\033[1m\033[40;32m" format " \033[0m\r\n", ##arg) /*��ɫ*/     
#define PWARN(format,arg...)         printf("\033[1m\033[40;33m" "WARN:F[%s]-L[%d]: " format " \033[0m\r\n",__FUNCTION__, __LINE__, ##arg) /*��ɫ*/
#define PERROR(format,arg...)        printf("\033[1m\033[40;31m" "ERROR:F[%s]-L[%d]: " format " \033[0m\r\n",__FUNCTION__, __LINE__, ##arg) /*��ɫ*/
#define PFATAL(format,arg...)        printf("\033[1m\033[40;35m" "FATAL:F[%s]-L[%d]: " format " \033[0m\r\n",__FUNCTION__, __LINE__, ##arg) /*��ɫ*/

void debugInit(uint8_t ch, uint32_t baudrate);
#endif /*__DEBUG_DEBUG_H_*/

