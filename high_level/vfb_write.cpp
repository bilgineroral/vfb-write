#include "vfb_write.h"

void frame_write (hls::stream<axisPixel> &s_axis_video, int* height, int* width, int* stride, int* baseAddr) {
#pragma HLS INTERFACE axis register_mode=both register port=s_axis_video
#pragma HLS INTERFACE mode=s_axilite port=height
#pragma HLS INTERFACE mode=s_axilite port=width
#pragma HLS INTERFACE mode=s_axilite port=stride
#pragma HLS INTERFACE mode=s_axilite port=return
#pragma HLS INTERFACE mode=m_axi depth=51200 port=baseAddr offset=slave

	/* 	access the side channel variables to read/write like this:
		pixelValue = axisPixel.data;
		while (!axisPixel.last) { ... }
		axisPixel.keep = -1; // -1 in decimal means all ones in binary e.g. "11111...1" (2's complement)

		write (push) / read (pop) from the stream (FIFO) like this:
		val = in_stream.read();
		in_stream.write(...);
	*/
	axisPixel readData;
	for (int row = 0; row < *height; row++) {
		for (int col = 0; col < *width; col++) {
			readData = s_axis_video.read();
		}
	}
}

