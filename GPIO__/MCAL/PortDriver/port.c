
/*
 * port.c
 *
 *  Created on: Nov 12, 2019
 *      Author: Muammad Elzeiny
 */
#define MAX_NUM_OF_CH_IN_PORT       8
#define MAX_NUM_OF_PORTS            6

#include "../../utils/Std_Types.h"
#include "../../utils/Bit_Math.h"
#include "../../config/port_cfg.h"
#include "../mcu_hw.h"
#include "port_types.h"
#include "port.h"

extern Port_CfgType PortCfgArr[];
static volatile PORT_RegType* BaseAddrArr[MAX_NUM_OF_PORTS] = {PORTA_BaseAddr,PORTB_BaseAddr,
                                                               PORTC_BaseAddr,PORTD_BaseAddr,
                                                               PORTE_BaseAddr,PORTF_BaseAddr};
void PORT_init(void)
{
    uint8 CfgArrIndex;
    Port_IdType PortId;
    Port_ChIdType ChannelId;
    uint8 ChannelPosInPort;
    volatile PORT_RegType* BaseAddr;

    for (CfgArrIndex = 0; CfgArrIndex < PORT_NUM_OF_ACTIVATED_CH; ++CfgArrIndex)
    {
        /*get channelID from CfgIndex*/
        ChannelId = PortCfgArr[CfgArrIndex].Channel;

        /*get PORTId using ChannelId*/
        PortId = ChannelId / MAX_NUM_OF_CH_IN_PORT;

        /*get baseAddress using PortId*/
        BaseAddr = BaseAddrArr[PortId];

        /*get Channel Position in PortGroup using ChannelId */
        ChannelPosInPort = ChannelId % MAX_NUM_OF_CH_IN_PORT;

        /*NOTE use channel position in Group to write in corresponding bit in Desired Register */

        /*TODO: set channel direction */
        if(PortCfgArr[CfgArrIndex].Dir == port_Dir_Input)
        {
            CLR_BIT(BaseAddr->GPIODIR, ChannelPosInPort);
        }
        else
        {
            SET_BIT(BaseAddr->GPIODIR, ChannelPosInPort);
        }


        /*TODO: set channel mode */
        if(PortCfgArr[CfgArrIndex].Mode == PORT_MODE_PIN_X_DIO)
        {
            CLR_BIT(BaseAddr->GPIOAFSEL, ChannelPosInPort);
        }
        else if((PortCfgArr[CfgArrIndex].Mode != Port_Mode_AIN ) && (PortCfgArr[CfgArrIndex].Mode != PORT_MODE_PIN_X_DIO))
        {
            SET_BIT(BaseAddr->GPIOAFSEL, ChannelPosInPort);
            BaseAddr->GPIOPCTL |= (PortCfgArr[CfgArrIndex].Mode << (ChannelPosInPort*4) );
        }


        /*TODO: set Interrupt configuration */
        if(PortCfgArr[CfgArrIndex].Interrupt == Port_IntDisable)
        {

            CLR_BIT(BaseAddr->GPIOIM, ChannelPosInPort);
        }
        else
        {
            SET_BIT(BaseAddr->GPIOIM, ChannelPosInPort);
            if(PortCfgArr[CfgArrIndex].Interrupt == Port_IntBothEdges)
            {
                SET_BIT(BaseAddr->GPIOIBE, ChannelPosInPort);
            }
            else
            {
                CLR_BIT(BaseAddr->GPIOIBE, ChannelPosInPort);
                if(PortCfgArr[CfgArrIndex].Interrupt == Port_IntRisingEdge)
                {
                    SET_BIT(BaseAddr->GPIOIEV, ChannelPosInPort);
                }
                else
                {
                    CLR_BIT(BaseAddr->GPIOIEV, ChannelPosInPort);
                }
            }
        }






        /*TODO: set Internal Attachment configuration */

        if(PortCfgArr[CfgArrIndex].AttachedRes == Port_InternalAttach_OpenDrain)
        {
            SET_BIT(BaseAddr->GPIOODR, ChannelPosInPort);
        }
        else if(PortCfgArr[CfgArrIndex].AttachedRes == Port_InternalAttach_PullUpRes)
        {
            SET_BIT(BaseAddr->GPIOPUR, ChannelPosInPort);
        }
        else if(PortCfgArr[CfgArrIndex].AttachedRes == Port_InternalAttach_PullDownRes)
        {
            SET_BIT(BaseAddr->GPIOPDR, ChannelPosInPort);
        }



        /*TODO: set current strength configuration */

        if(PortCfgArr[CfgArrIndex].CurrentDrive == Port_CurrDrive_2mA)
        {
            SET_BIT(BaseAddr->GPIODR2R, ChannelPosInPort);
        }
        else if(PortCfgArr[CfgArrIndex].CurrentDrive == Port_CurrDrive_4mA)
        {
            SET_BIT(BaseAddr->GPIODR4R, ChannelPosInPort);
        }
        else if(PortCfgArr[CfgArrIndex].CurrentDrive == Port_CurrDrive_8mA)
        {
            SET_BIT(BaseAddr->GPIODR8R, ChannelPosInPort);
        }




        /*Check if analog functionality is required*/
        if(PortCfgArr[CfgArrIndex].Mode != Port_Mode_AIN )
        {
            /*TODO: enable digital and disable ADC  */
            SET_BIT(BaseAddr->GPIODEN, ChannelPosInPort);

        }
        else
        {
            /*TODO: disable digital and enable ADC */

        }





    }
}
