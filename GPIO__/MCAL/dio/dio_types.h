
#ifndef __DIO_TYPES_H__
#define __DIO_TYPES_H__

/*
 * dio_types.h
 *
 *  Created on: 19/02/2020
 *  Author: Ahmed Mahmoud
 */

#include "Std_types.h"

typedef     uint8           Dio_ChannelType;


#define Dio_Channel_A0              0
#define Dio_Channel_A1              1
#define Dio_Channel_A2              2
#define Dio_Channel_A3              3
#define Dio_Channel_A4              4
#define Dio_Channel_A5              5
#define Dio_Channel_A6              6
#define Dio_Channel_A7              7

#define Dio_Channel_B0              8
#define Dio_Channel_B1              9
#define Dio_Channel_B2              10
#define Dio_Channel_B3              11
#define Dio_Channel_B4              12
#define Dio_Channel_B5              13
#define Dio_Channel_B6              14
#define Dio_Channel_B7              15

#define Dio_Channel_C0              16
#define Dio_Channel_C1              17
#define Dio_Channel_C2              18
#define Dio_Channel_C3              19
#define Dio_Channel_C4              20
#define Dio_Channel_C5              21
#define Dio_Channel_C6              22
#define Dio_Channel_C7              23

#define Dio_Channel_D0              24
#define Dio_Channel_D1              25
#define Dio_Channel_D2              26
#define Dio_Channel_D3              27
#define Dio_Channel_D4              28
#define Dio_Channel_D5              29
#define Dio_Channel_D6              30
#define Dio_Channel_D7              31

#define Dio_Channel_E0              32
#define Dio_Channel_E1              33
#define Dio_Channel_E2              34
#define Dio_Channel_E3              35
#define Dio_Channel_E4              36
#define Dio_Channel_E5              37
#define Dio_Channel_E6_NA           38
#define Dio_Channel_E7_NA           39

#define Dio_Channel_F0              40
#define Dio_Channel_F1              41
#define Dio_Channel_F2              42
#define Dio_Channel_F3              43
#define Dio_Channel_F4_NA           44
#define Dio_Channel_F5_NA           45
#define Dio_Channel_F6_NA           46
#define Dio_Channel_F7_NA           47


typedef uint8                       Dio_PortType;

#define Dio_Port_A                  0
#define Dio_Port_B                  1
#define Dio_Port_C                  2
#define Dio_Port_D                  3
#define Dio_Port_E                  4
#define Dio_Port_F                  5


typedef struct
{
    uint8                       mask;
    uint8                       offset;
    Dio_ChannelType             port;

}Dio_ChannelGroupType;


typedef uint8                   Dio_LevelType;
typedef uint8                   Dio_PortLevelType;


#endif
