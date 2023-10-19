#pragma once

#include <iostream>
#include "ap_axi_sdata.h"
#include "hls_stream.h"

// 24-bits for 8-bit R,G,B
typedef ap_axiu<24, 1, 1, 1> axis_t;

void frame_read(int* height, int* width, int* stride, int* baseAddr, hls::stream<axis_t>& s_axis_video);
