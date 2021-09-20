#ifndef __INCLUDE_H_
#define __INCLUDE_H_

/*оƬ֧��*/
#include "stm32f4xx.h"
#include "sys.h"
#include "debug.h"
#include "delay.h"
/*
stm32F4xxʱ��
AHB 168M
APB1 42M
APB2 84M
*/

/*��׼C��*/
//#include <stdarg.h>
#include <string.h>
//#include <stdlib.h>
#include <stdio.h>
//#include  <math.h>
//#include  <ctype.h>


/**/
#include "config.h"
#include "errorno.h"

#ifndef TRUE
typedef enum
{
    TRUE=1,
    FALSE=0,
}BOOL;
#endif

typedef union
{
    int16_t    V16;
    int32_t    V32;
    int64_t    V64;
    uint16_t    UV16;
    uint32_t    UV32;
    uint64_t    UV64;
    double      F64;
    float       F32;
    uint8_t     V8[8];
}T_TransType; //������byt�����벻ͬ����֮�����ת��

typedef void(*pvFunType)(void);

#ifndef true
#define true 1
#define false 0
#endif


#endif /*__INCLUDE_H_*/
