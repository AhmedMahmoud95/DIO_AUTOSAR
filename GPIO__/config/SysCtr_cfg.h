/*
 * SysCtr_cfg.h
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_
#define E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_
#include "mcal/SysCtr/SysCtr_types.h"

/*
 * Used crystal
 */
uint8 gu8_MOSC = SYSCTRL_XTAL_16000;

/*
 * Configuration
 */
SYSCTRL_t gstr_SYSCTRL_Object = { SYSCTRL_MOSC, 4000 };
#endif /* E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_ */
