/*
 * DSP2833x_AD9850.c
 *
 *  Created on: 2026年1月31日
 *      Author: X1C
 */

#include "DSP2833x_Device.h"     // DSP2833x 头文件
#include "DSP2833x_Examples.h"   // DSP2833x 例子相关头文件


#include "DSP2833x_driver/DSP2833x_AD9850.h"


void DSP_TMS320F28335_AD9850_Reset_Fxn(void *handle)
{
	DSP_TMS320F28335_AD9850_Handle h = (DSP_TMS320F28335_AD9850_Handle)handle;

	// GPIO_SET(g)
	GpioDataRegs.GPASET.all = (1UL << (h->ctx->gpio_rst));
}
