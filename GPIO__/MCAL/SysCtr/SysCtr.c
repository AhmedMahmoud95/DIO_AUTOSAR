/*
 * SysCtr.c
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../mcu_hw.h"
#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"

/*TODO include SysCtr_cfg.h*/
#include "config/SysCtr_cfg.h"


/****************************************************/
/*          Global variables                        */
/****************************************************/
uint32 gu32_Timer = 0;
/****************************************************/
void SysCtr_init(void)
{

    /*TODO Enable configured Peripherals CLock gates*/
    RCC.BYPASS = 1;
    RCC.USESYSDIV = 0;
    if (gstr_SYSCTRL_Object.oscilatorSource != SYSCTRL_MOSC)
    {
        RCC.MOSDIS = 1;
    }
    else
    {
        RCC.MOSDIS = 0;
    }
    RCC.XTAL = gu8_MOSC;        //16MHZ Main oscillator
    RCC.OSCSRC = gstr_SYSCTRL_Object.oscilatorSource;
    RCC.PWRDN = 0;
    /*
     * Divisors are given from 5-4 table. BYPASS = 0.
     * For undefined frequencies, result is approximated to the nearest (Larger).
     */
    RCC.SYSDIV = (uint32) (200000 / gstr_SYSCTRL_Object.desiredFrequency  + 1);
    RCC.USESYSDIV = 1;
    /*TODO Set System CLock Source as configured*/

    /* Polling on PLLLRIS bit in the Raw Interrupt Status (RIS) register */
    while (!(RIS_REG & 0x0040));

    /*TODO set CLock Frequency as configured -
     * use Figure 5-5. Main Clock Tree Page.222 in DATASHEET as reference.
     * */

    RCC.BYPASS = 0;

}
uint32 SysCtr_getSysClockFreq(void)
{
    /*TODO return the current system clock frequency */
    return gstr_SYSCTRL_Object.desiredFrequency;
}

