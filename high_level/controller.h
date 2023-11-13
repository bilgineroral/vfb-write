#pragma once

void control( /* AXI4-Lite Slave interface */
			  int* rwAddr0,
			  int* rwAddr1,
			  int* rwAddr2,
			  int* rWidth, int* rHeight, int* rStride,
			  int* wWidth, int* wHeight, int* wStride,

			  /* AXI4-Lite Master interface */
			  int rBaseAddr[1000], int wBaseAddr[1000]
			  );
