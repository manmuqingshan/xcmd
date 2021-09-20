#ifndef __ERROR_NO_H_
#define __ERROR_NO_H_
#include "include.h"

typedef enum
{
    DISABLED = 1,   /*δʹ��*/
    NON_EXIST,      /*ͨ��������*/
    DEV_UNCONNECT,  /*�豸δ����*/
    TIMEOUT,        /*��ʱ*/
    CLK_UNDEFINE,   /*δʶ�������ʱ��*/
    FIFO_OVERFLOW,  /*���������*/
    PARAM_ERROR,     /*��������*/
    
    ERROR_LAST     /*���ڱ��error no ���ܸ���*/
}M_Errno;

void setErrno(M_Errno aErrno);
uint32_t getErrno(void);
void showErr(char* msg);

#endif /*__ERROR_NO_H_*/
