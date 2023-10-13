#include "vfb_write.h"
// #include <fstream>

int main() {

	// std::ofstream outFile;
	// outFile.open("tb_results.txt");

	/* if (!outFile.is_open()) {
		std::cerr << "Failed to open the file for writing." << std::endl;
		return 1;
	}*/

	std::cout << "~~ Starting C simulation ~~" << std::endl;

	hls::stream<axisPixel> mockImageStream;
	int height = 100;
	int width = 100;
	int stride = 512;
	int* baseAddr = new int[51200];
	// int baseAddr[1000];
	axisPixel pixel;

	std::cout << "~~ Creating mock image stream ~~" << std::endl;
	ap_uint<24> data = 0;
	for (int i=0; i<100; i++) {
		for(int j=0;j<100;j++) {

			 pixel.data = data;
			 /* pixel.keep = -1;
			 pixel.strb = -1;
			 pixel.user = 1; */
			 if (j == 9)
				 pixel.last = 1;
			 else
				 pixel.last = 0;

			 mockImageStream.write(pixel);
			 data++;
		}
	}

	std::cout << "~~ Executing frame_write() function ~~" << std::endl;
	frame_write(mockImageStream, &height, &width, &stride, baseAddr);

	int expectedData = 0;
	for (int row = 0; row < 100; row++) {
		for (int col = 0; col < 100; col++) {
			int readData = baseAddr[row * (stride/4) + col];
			bool ok = (expectedData == readData);
			if (!ok) {
				std::cout << "~~ ERROR DETECTED! ~~" << std::endl;
				std::cout << "~~ Expected Data= " << expectedData << std::endl;
				std::cout << "~~ Read data= " << readData << std::endl;
				std::cout << "~~ row= " << row << ", col= " << col << std::endl;
				//outFile.close();
				std::cout << "~~ Simulation failed! ~~" << std::endl;
				return 1;
			}
			expectedData++;
		}
	}

	/* std::cout << "~~ Writing into tb_results.txt ~~" << std::endl;
	for (int k = 0; k < 499; k++) {
		outFile << baseAddr[k] << std::endl;
	}*/

	// outFile.close();
	std::cout << "~~ Simulation finished without errors ~~" << std::endl;
	return 0;
}
