

/**
 * main.c
 */
#include "mcal/nvic/nvic.h"
#include "mcal/mcu_hw.h"
#include "mcal/PortDriver/port.h"
#include "mcal/dio/dio.h"
#include "mcal/SysCtr/SysCtr.h"

#define RCC_          (*((volatile uint32 *)0x400FE108))

int main(void)
{
    SysCtr_init();
    RCC_ = 0x3F;
    PORT_init();
    //Dio_WriteChannel(Dio_Channel_F3, STD_high);
    Dio_ChannelGroupType str_Group0 = { 7, 1, Dio_Port_F};
    Dio_WriteChannelGroup (&str_Group0, STD_high);
//    Dio_WriteChannel(Dio_Channel_F3, STD_high);
//    Dio_WriteChannel(Dio_Channel_F2, STD_high);

    while(1);
    return 0;
}
