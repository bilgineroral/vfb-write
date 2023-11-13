#include "controller.h"

void control( /* AXI4-Lite Slave interface */
			  int* rwAddr0,
			  int* rwAddr1,
			  int* rwAddr2,
			  int* rWidth, int* rHeight, int* rStride,
			  int* wWidth, int* wHeight, int* wStride,

			  /* AXI4-Lite Master interface */
			  int rBaseAddr[1000], int wBaseAddr[1000]
			  ) {
#pragma HLS INTERFACE mode=s_axilite port=rwAddr0
#pragma HLS INTERFACE mode=s_axilite port=rwAddr1
#pragma HLS INTERFACE mode=s_axilite port=rwAddr2

#pragma HLS INTERFACE mode=s_axilite port=rWidth
#pragma HLS INTERFACE mode=s_axilite port=rHeight
#pragma HLS INTERFACE mode=s_axilite port=rStride

#pragma HLS INTERFACE mode=s_axilite port=wWidth
#pragma HLS INTERFACE mode=s_axilite port=wHeight
#pragma HLS INTERFACE mode=s_axilite port=wStride

#pragma HLS INTERFACE mode=m_axi port=rBaseAddr
#pragma HLS INTERFACE mode=m_axi port=wBaseAddr

#pragma HLS INTERFACE mode=s_axilite port=return

	enum cState {
		IDLE,
		W_SET_HEIGHT,
		W_SET_WIDTH,
		W_SET_STRIDE,
		R_SET_HEIGHT,
		R_SET_WIDTH,
		R_SET_STRIDE,
		W_ADDR_CONFIG,
		R_ADDR_CONFIG,
		W_ENABLE,
		R_ENABLE,
		CHECK_W_DONE
	};
	static int writeCount = 0;
	static int readCount = 0;

	static cState currentState = IDLE;
#pragma HLS RESET variable=currentState

	switch(currentState) {
	case IDLE:
		currentState = W_SET_HEIGHT;
		break;

	case W_SET_HEIGHT:
		wBaseAddr[0x10/4] = *wHeight;
		currentState = W_SET_WIDTH;
		break;

	case W_SET_WIDTH:
		wBaseAddr[0x18/4] = *wWidth;
		currentState = W_SET_STRIDE;
		break;

	case W_SET_STRIDE:
		wBaseAddr[0x20/4] = *wStride;
		currentState = W_ADDR_CONFIG;
		break;

	case W_ADDR_CONFIG:
		if (writeCount == 0) {
			wBaseAddr[0x28/4] = *rwAddr0;
		}
		else if (writeCount == 1) {
			wBaseAddr[0x28/4] = *rwAddr1;
		}
		else {
			wBaseAddr[0x28/4] = *rwAddr2;
		}
		writeCount = (writeCount == 2) ? 0 : writeCount + 1;

		currentState = W_ENABLE;
		break;

	case W_ENABLE:
		wBaseAddr[0x0/4] = 1; // ap_start = 1
		currentState = CHECK_W_DONE;
		break;

	case CHECK_W_DONE:
		if ( (wBaseAddr[0x0/4] & 2) == 2)
			currentState = R_SET_HEIGHT;
		else
			currentState = CHECK_W_DONE;
		break;

	case R_SET_HEIGHT:
		rBaseAddr[0x10/4] = *rHeight;
		currentState = R_SET_WIDTH;
		break;

	case R_SET_WIDTH:
		rBaseAddr[0x18/4] = *rWidth;
		currentState = R_SET_STRIDE;
		break;

	case R_SET_STRIDE:
		rBaseAddr[0x20/4] = *rStride;
		currentState = R_ADDR_CONFIG;
		break;

	case R_ADDR_CONFIG:

		if (readCount == 0) {
			rBaseAddr[0x28] = *rwAddr0;
		}
		else if (readCount == 1) {
			rBaseAddr[0x28] = *rwAddr1;
		}
		else {
			rBaseAddr[0x28] = *rwAddr2;
		}
		readCount = (readCount == 2) ? 0 : readCount + 1;

		currentState = R_ENABLE;
		break;

	case R_ENABLE:
		rBaseAddr[0x0/4] = 1; // ap_start = 1
		currentState = W_SET_HEIGHT;
		break;
	default:
		currentState = IDLE;
		break;
	}
}
