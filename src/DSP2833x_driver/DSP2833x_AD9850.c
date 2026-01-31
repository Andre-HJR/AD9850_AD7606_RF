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
	GpioDataRegs.GPASET.all = (1UL << (h->ctx->gpio_rst)); // GPIO_SET 引脚电压上拉
	asm ( " NOP "); asm (" NOP "); // 电压上拉，之后需要等一段时间
	GpioDataRegs.GPACLEAR.all = (1UL << (h->ctx->gpio_rst));
	GpioDataRegs.GPACLEAR.all = (1UL << (h->ctx->gpio_wclk));
	GpioDataRegs.GPACLEAR.all = (1UL << (h->ctx->gpio_fqud));
}

void DSP_TMS320F28335_AD9850_Write_Fxn(void *handle, Uint32 ftw)
{
	DSP_TMS320F28335_AD9850_Handle h = (DSP_TMS320F28335_AD9850_Handle)handle;
	long long data = ((long long)ftw << 8); // 这里似乎有点问题
	Uint32 i = 0;
	for (i = 0; i < 40; ++i)
	{
		if ((long long)data & 0x01)
		{
			GpioDataRegs.GPASET.all = (1UL << (h->ctx->gpio_data));
		} else
		{
			GpioDataRegs.GPACLEAR.all = (1UL << (h->ctx->gpio_data));
		}

		GpioDataRegs.GPASET.all = (1UL << (h->ctx->gpio_wclk));
		asm (" NOP "); asm (" NOP ");
		GpioDataRegs.GPACLEAR.all = (1UL << (h->ctx->gpio_wclk));

		data >>= 1;
	}
	GpioDataRegs.GPASET.all = (1UL << (h->ctx->gpio_fqud));
	asm (" NOP "); asm (" NOP ");
	GpioDataRegs.GPACLEAR.all = (1UL << (h->ctx->gpio_fqud));
}
