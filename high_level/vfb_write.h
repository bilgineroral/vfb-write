#pragma once

#include <iostream>
#include "ap_axi_sdata.h"
#include "hls_stream.h"

// 24-bits for 8-bit R,G,B
typedef ap_axiu<24,0,0,0> axisPixel;

void frame_write(hls::stream<axisPixel>& s_axis_video, int* height, int* width, int* stride, int* baseAddr);
