/*
 * SysCtr_Types.h
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef TM4C123_FIRMWARE_MCAL_SYSCTR_SYSCTR_TYPES_H_
#define TM4C123_FIRMWARE_MCAL_SYSCTR_SYSCTR_TYPES_H_

/********************************************************************************/
/*                          Global defines                                      */
/********************************************************************************/
#define SYSCTRL_MOSC                        0
#define SYSCTRL_PIOSC                       1
#define SYSCTRL_PIOSC_DIV_4                 2
#define SYSCTRL_LFIOSC                      3

#define SYSCTRL_XTAL_4000                   0x06
#define SYSCTRL_XTAL_4096                   0x07
#define SYSCTRL_XTAL_49152                  0x08
#define SYSCTRL_XTAL_5000                   0x09
#define SYSCTRL_XTAL_5120                   0x0A
#define SYSCTRL_XTAL_6000                   0x0B
#define SYSCTRL_XTAL_6144                   0x0C
#define SYSCTRL_XTAL_7372                   0x0D
#define SYSCTRL_XTAL_8000                   0x0E
#define SYSCTRL_XTAL_8192                   0x0F
#define SYSCTRL_XTAL_10000                  0x10
#define SYSCTRL_XTAL_12000                  0x11
#define SYSCTRL_XTAL_12288                  0x12
#define SYSCTRL_XTAL_13560                  0x13
#define SYSCTRL_XTAL_14318                  0x14
#define SYSCTRL_XTAL_16000                  0x15
#define SYSCTRL_XTAL_16384                  0x16
#define SYSCTRL_XTAL_18000                  0x17
#define SYSCTRL_XTAL_20000                  0x18
#define SYSCTRL_XTAL_24000                  0x19
#define SYSCTRL_XTAL_25000                  0x1A

/********************************************************************************/
/*                          Global structs                                      */
/********************************************************************************/
typedef struct
{
    uint32 MOSDIS   :1;
    uint32          :3;
    uint32 OSCSRC   :2;
    uint32 XTAL     :5;
    uint32 BYPASS   :1;
    uint32          :1;
    uint32 PWRDN    :1;
    uint32          :3;
    uint32 PWMDIV   :3;
    uint32          :1;
    uint32 USEPWMDIV:1;
    uint32 USESYSDIV:1;
    uint32 SYSDIV   :4;
    uint32 ACG      :1;
    uint32          :4;
}SYSCTRL_RCC_type;
/*
 * TODO implement suitable container to store the followings
 *
 * which peripheral clock gate Enabled
 * Desired System clock Source
 * Desired System CLock Frequency
 */
typedef struct
{
   uint32 oscilatorSource   :2;
   uint32 desiredFrequency  :30;

}SYSCTRL_t;





#endif /* TM4C123_FIRMWARE_MCAL_SYSCTR_SYSCTR_TYPES_H_ */
