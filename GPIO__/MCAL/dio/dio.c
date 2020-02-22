/*
 * dio.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"
/*TODO: include the header file that contains register definitions */
#include "../mcu_hw.h"
#include "dio.h"


#define MAX_NUM_OF_PORTS        6
static volatile PORT_RegType* BaseAddrArr[MAX_NUM_OF_PORTS] = {PORTA_BaseAddr,PORTB_BaseAddr,
                                                               PORTC_BaseAddr,PORTD_BaseAddr,
                                                               PORTE_BaseAddr,PORTF_BaseAddr};
#if 0
void Dio_FlipChannel( Dio_ChannelType ChannelId)
{
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;
    volatile PORT_RegType* BaseAddr;

    BaseAddr = BaseAddrArr[PortId];
    /* TODO: toggle the corresponding ChannelId */

    BaseAddr->GPIODATA[1<<ChannelPos] ^=1<<ChannelPos;


}
#endif

void Dio_FlipPort(Dio_PortType PortId)
{
    volatile PORT_RegType* BaseAddr;

    BaseAddr = BaseAddrArr[PortId];

    /*TODO: toggle the port value */
    BaseAddr->GPIODATA[255] ^=0xff;


}

/********************************************************************/
/*                       Autosar functions                          */
/********************************************************************/

/**
 * Input: Dio_PortType PortId, Dio_PortLevelType Level
 * Output:
 * In/Out:
 * Return: Void.
 * Description: Writes a group of channels
 *
 */
void Dio_WriteChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level )
{
    Dio_PortType PortId = ChannelGroupIdPtr ->port;
    volatile PORT_RegType* BaseAddr = BaseAddrArr[PortId];
    /*      Channel group calculation       */
    /*      Required GPIODATA register calculation      */
    uint8 GroupID = ((ChannelGroupIdPtr -> mask) << (ChannelGroupIdPtr->offset));
    BaseAddr ->GPIODATA [GroupID] = STD_high;
}

/**
 * Input: const Dio_ChannelGroupType* ChannelGroupIdPtr
 * Output:
 * In/Out:
 * Return: Dio_PortLevelType.
 * Description: Reads a group of channels.
 *
 */
Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr )
{
    Dio_PortType PortId = ChannelGroupIdPtr ->port;
       volatile PORT_RegType* BaseAddr ;
       BaseAddr = BaseAddrArr[PortId];
       /*      Channel group calculation       */
       /*      Required GPIODATA register calculation      */
       uint8 GroupID = (ChannelGroupIdPtr -> mask) << (ChannelGroupIdPtr->offset);
       return (BaseAddr ->GPIODATA [GroupID]);
}

/**
 * Input: Dio_PortType PortId
 * Output:
 * In/Out:
 * Return: Dio_PortLevelType PortLevel
 * Description: Reads Port Level
 *
 */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    Dio_PortLevelType PortLevel;
    volatile PORT_RegType* ReadPortBaseAddr;
    ReadPortBaseAddr = BaseAddrArr[PortId];
    PortLevel=(Dio_PortLevelType)ReadPortBaseAddr->GPIODATA[255];
    return PortLevel;
}

/**
 * Input: Dio_PortType PortId, Dio_PortLevelType Level
 * Output:
 * In/Out:
 * Return: Void.
 * Description: Writes a port with indicated Port level
 *
 */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    volatile PORT_RegType* WritePortBaseAddr;
    WritePortBaseAddr = BaseAddrArr[PortId];
    WritePortBaseAddr->GPIODATA[255]=Level;
}

/**
 * Input:  Dio_ChannelType ChannelId
 * Output:
 * In/Out:
 * Return: Dio_PortLevelType PortLevel
 * Description: Reads a channel Level
 *
 */
Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId )
{
    Std_levelType ret;
    volatile PORT_RegType* BaseAddr;
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;
    BaseAddr = BaseAddrArr[PortId];

    /*TODO: Return the level value of given Channel */
    //GET_BIT(BaseAddr->GPIODATA[ChannelPos],ChannelPos);
    ret=(BaseAddr->GPIODATA[1<<ChannelPos])>>ChannelPos;
    return ret;

}

/**
 * Input: Dio_ChannelType ChannelId, Dio_LevelType Level
 * Output:
 * In/Out:
 * Return: Void.
 * Description: Writes a channel in a specific port with indicated level
 *
 */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;
    volatile PORT_RegType* BaseAddr;

    BaseAddr = BaseAddrArr[PortId];

    /*TODO: Write the input value in the corresponding ChannelId */
    BaseAddr->GPIODATA[1<<ChannelPos]=Level<<ChannelPos;

}

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;
    volatile PORT_RegType* BaseAddr;

    BaseAddr = BaseAddrArr[PortId];
    /* TODO: toggle the corresponding ChannelId */

    BaseAddr->GPIODATA[1<<ChannelPos] ^=1<<ChannelPos;
    return BaseAddr->GPIODATA[1<<ChannelPos];
}
