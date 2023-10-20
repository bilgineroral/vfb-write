#include "vfb_read.h"

void frame_read (int* height, int* width, int* stride, int* baseAddr, hls::stream<axis_t> &s_axis_video) {
#pragma HLS INTERFACE axis register_mode=both register port=s_axis_video
#pragma HLS INTERFACE mode=s_axilite port=height
#pragma HLS INTERFACE mode=s_axilite port=width
#pragma HLS INTERFACE mode=s_axilite port=stride
#pragma HLS INTERFACE mode=s_axilite port=return
#pragma HLS INTERFACE mode=m_axi depth=640 port=baseAddr offset=slave

	/* 	access the side channel variables to read/write like this:
		pixelValue = axisPixel.data;
		while (!axisPixel.last) { ... }
		axisPixel.keep = -1; // -1 in decimal means all ones in binary e.g. "11111...1" (2's complement)

		write (push) / read (pop) from the stream (FIFO) like this:
		val = in_stream.read();
		in_stream.write(...);
	*/
	axis_t readData;

	uint32_t tdata;
	for (int row = 0; row < *height; row++) {
		for (int col = 0; col < *width; col++) {
			tdata = baseAddr[row * ((*stride)/4) + col];
			readData.data = tdata;
			if (row == 0 && col == 0)
				readData.user = 1;
			else
				readData.user = 0;
			readData.last = col == *width - 1;
			readData.strb = -1; // "1111"
			readData.keep = -1; // "1111"
			s_axis_video.write(readData);
		}
	}
}

