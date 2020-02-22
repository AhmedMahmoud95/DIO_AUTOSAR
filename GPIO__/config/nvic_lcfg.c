/*
 * nvic_lcfg.c
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "nvic_cfg.h"
#include "../mcal/nvic/nvic_types.h"


extern const uint8 gu8_PriGroupBitsConfig= INT_PRIORITY_XXX;

const NVIC_CfgType NVIC_CfgArr[NVIC_NUM_OF_ENABLED_INT]=
{

   {    NVIC_GPIOA ,    3,  1},
   {    NVIC_SSI0  ,    0,  1},
   {    NVIC_GPIOB ,    1,  0},
   {    NVIC_GPIOC ,    3,  0},
   {    NVIC_UART0 ,    2,  0},
};
