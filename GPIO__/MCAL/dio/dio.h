/*
 * dio.h
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_MCAL_DIO_DIO_H_
#define E15_ARM_REPO_MCAL_DIO_DIO_H_

#include "../../utils/Std_Types.h"
#include "DIO_types.h"

/*=========================================
 * FUNCTIONS PROTOTYPES
 =========================================*/
/*  Std_levelType Dio_ReadChannel(Dio_ChannelType ChannelId);*/
/*    void Dio_WriteChannel(Dio_ChannelType ChannelId, Std_levelType Level);*/
/* uint8 Dio_ReadPort(Dio_PortType PortId ); */
/*  void Dio_WritePort( Dio_PortType PortId, uint8 Level);  */
void Dio_FlipPort(Dio_PortType PortId);

/********************************************************************/
/*                       Autosar functions                          */
/********************************************************************/
void Dio_WriteChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level );
Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr );
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId );
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
#endif /* E15_ARM_REPO_MCAL_DIO_DIO_H_ */
