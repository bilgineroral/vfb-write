#include <iostream>
#include "controller.h"

int main() {

	int rBaseAddr[1000];
	int wBaseAddr[1000];

	int rwAddr0 = 0x0400a000;
	int rwAddr1 = 0x0410a000;
	int rwAddr2 = 0x0420a000;

	int rWidth = 1920;
	int rHeight = 1080;
	int rStride = 8192;

	int wWidth = 1920;
	int wHeight = 1080;
	int wStride = 8192;

	for (int i = 0; i < 100; i++) {
		control(&rwAddr0, &rwAddr1, &rwAddr2, &rWidth, &rHeight, &rStride, &wWidth, &wHeight, &wStride, rBaseAddr, wBaseAddr);
		if (i % 40 == 0 && i != 0)
			wBaseAddr[0] = wBaseAddr[0] | 2;
		else {
			int mask = 0x3;  // This is a mask with the last 2 bits set to '01'
			wBaseAddr[0] = (wBaseAddr[0] & ~mask) | 1;
		}

	}

	if (wBaseAddr[0x10/4] != wHeight) {
		return 1;
	}

	if (wBaseAddr[0x18/4] != wWidth)
		return 1;

	if (wBaseAddr[0x20/4] != wStride)
		return 1;

	if (wBaseAddr[0x28/4] != rwAddr2) {
		std::cout << "Written: " << wBaseAddr[0x28/4] << std::endl;
		// return 1;
	}

	if (rBaseAddr[0x10/4] != rHeight)
		return 1;

	if (rBaseAddr[0x18/4] != rWidth)
		return 1;

	if (rBaseAddr[0x20/4] != rStride)
		return 1;

	if (rBaseAddr[0x28/4] != rwAddr2) {
		std::cout << "Read: " << rBaseAddr[0x28/4] << std::endl;
		// return 1;
	}

	if (rBaseAddr[0x0/4] != 1)
		return 1;

	std::cout << "bilginer@ubuntu:~$ Simulation successfully finished" << std::endl;
	return 0;
}
