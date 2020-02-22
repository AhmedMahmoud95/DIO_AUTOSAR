/*
 * nvic.c
 *
 *  Created on: Aug 17, 2019
 *      Author: kareem
 */


#include "../../utils/Std_Types.h"
#include "../../utils/Bit_Math.h"
/*TODO include processor.h*/

#include "../../config/nvic_cfg.h"
#include "../mcu_hw.h"
#include "nvic_types.h"
#include "nvic.h"
#include "../../utils/Std_Types.h"


void NVIC_init(void)
{
    /*TODO : switch to privilege mode - use switch function in processor.h*/


    /*TODO :loop for NVIC_CfgArr configure each Interrupt
     *  as stated in Cfg (Enable/Priority/sub-priority)
     *  */

    uint8 u8_InterruptIndex;
    uint8 u8_NVICRegOffset;
    uint8 u8_NVICBitOffset;
    uint8 u8_PRIRegOffset;
    uint8 u8_PRIBitOffset;
    uint8 u8_PriorityValue;

    //| (gu8_PriGroupBitsConfig << 8)
    SCB_APINT = (uint32)(0x05FA0000 | (gu8_PriGroupBitsConfig << 8) );

    for(u8_InterruptIndex=0 ; u8_InterruptIndex < NVIC_NUM_OF_ENABLED_INT;u8_InterruptIndex++)
    {

        u8_NVICRegOffset=0;
        u8_NVICBitOffset=0;
        u8_PRIRegOffset=0;
        u8_PRIBitOffset=0;
        u8_PriorityValue=0;

        u8_NVICRegOffset=(NVIC_CfgArr[u8_InterruptIndex].INT_NUM/32)*4;
        u8_NVICBitOffset=(NVIC_CfgArr[u8_InterruptIndex].INT_NUM%32);
        *(NVIC_REG_ADDRESSE+u8_NVICRegOffset)  |= (1<<u8_NVICBitOffset);



        u8_PRIRegOffset=(NVIC_CfgArr[u8_InterruptIndex].INT_NUM/4)*4;
        u8_PRIBitOffset=(NVIC_CfgArr[u8_InterruptIndex].INT_NUM%4);



        switch(gu8_PriGroupBitsConfig)
        {
           case INT_PRIORITY_XXX:
               u8_PriorityValue = NVIC_CfgArr[u8_InterruptIndex].u8_GroupPriority;
               break;
           case INT_PRIORITY_XXY:
               u8_PriorityValue = NVIC_CfgArr[u8_InterruptIndex].u8_GroupPriority<<1;
               u8_PriorityValue |= NVIC_CfgArr[u8_InterruptIndex].u8_SubGroupPriority;
               break;
           case INT_PRIORITY_XYY:
               u8_PriorityValue = NVIC_CfgArr[u8_InterruptIndex].u8_GroupPriority<<2;
               u8_PriorityValue |= NVIC_CfgArr[u8_InterruptIndex].u8_SubGroupPriority;
               break;
           case INT_PRIORITY_YYY:
               u8_PriorityValue = NVIC_CfgArr[u8_InterruptIndex].u8_SubGroupPriority;
               break;
           default:
               break;
        }
               /* configure Priority register of dedicated interrupt */
        switch(u8_PRIBitOffset)
        {
        case 0 :
            *(PRI_REG_ADDRESSE+u8_PRIRegOffset)|=(u8_PriorityValue << 5 );
            break;
        case 1 :
            *(PRI_REG_ADDRESSE+u8_PRIRegOffset)|=(u8_PriorityValue << 13 );
            break;
        case 2 :
            *(PRI_REG_ADDRESSE+u8_PRIRegOffset)|=(u8_PriorityValue << 21 );
            break;
        case 3 :
            *(PRI_REG_ADDRESSE+u8_PRIRegOffset)|=(u8_PriorityValue << 29 );
            break;
        default:
            break;
        }

    }

    /*TODO : return to non-privilege mode */

}



