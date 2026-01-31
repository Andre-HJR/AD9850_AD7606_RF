/*
 * DSP2833x_AD9850.h
 *
 *  Created on: 2026年1月31日
 *      Author: X1C
 */

#ifndef INC_DSP2833X_DRIVER_DSP2833X_AD9850_H_
#define INC_DSP2833X_DRIVER_DSP2833X_AD9850_H_

#include "DSP2833x_Device.h"     // DSP2833x 头文件
#include "DSP2833x_Examples.h"   // DSP2833x 例子相关头文件

/// AD9850 -- 125MHz




struct DSP_TMS320F28335_AD9850_Ctx
{
	Uint16 gpio_data;
	Uint16 gpio_wclk;
	Uint16 gpio_fqud;
	Uint16 gpio_rst;
};


struct DSP_TMS320F28335_AD9850_Param
{
	float fout_hz; // Output FZ.
	Uint32 ftw;
};

struct DSP_TMS320F28335_AD9850_Fxn
{
	void (*reset)(void*);
	void (*write)(void*, Uint32 ftw);
	void (*update)(void*);
};


struct DSP_TMS320F28335_AD9850_Obj
{
	struct DSP_TMS320F28335_AD9850_Ctx *ctx;
	struct DSP_TMS320F28335_AD9850_Param *param;
	struct DSP_TMS320F28335_AD9850_Fxn *fxn;
};

typedef struct DSP_TMS320F28335_AD9850_Obj * DSP_TMS320F28335_AD9850_Handle;










#endif /* INC_DSP2833X_DRIVER_DSP2833X_AD9850_H_ */
