/*
 * nvic_cfg.h
 *
 *  Created on: Aug 17, 2019
 *      Author: kareem
 */

#ifndef E15_ARM_REPO_CONFIG_NVIC_CFG_H_
#define E15_ARM_REPO_CONFIG_NVIC_CFG_H_

#include "../utils/Std_Types.h"
#include "../mcal/nvic/nvic_types.h"


#define NVIC_NUM_OF_ENABLED_INT                     5

extern const NVIC_CfgType NVIC_CfgArr[NVIC_NUM_OF_ENABLED_INT];

extern const uint8 gu8_PriGroupBitsConfig;

#endif /* E15_ARM_REPO_CONFIG_NVIC_CFG_H_ */
