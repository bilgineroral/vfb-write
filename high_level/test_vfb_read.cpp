#include "vfb_read.h"
#include <random>

int main() {

	// Providing a seed value
	// srand((unsigned) time(NULL));

	std::cout << "~~ Starting C simulation ~~" << std::endl;
	const int ARRSIZE = 640;
	int height = 10;
	int width = 10;
	int stride = 64;
	//int* baseAddr = new int[ARRSIZE];

	/*std::cout << "~~ Initializing array with random numbers ~~" << std::endl;
	int ctr = 0;
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			//int randomNum = rand() % 999999;
			//baseAddr[row * (stride/4) + col] = randomNum;

		}
	}*/

	std::cout << "~~ Initializing array ~~" << std::endl;
	/*for (int n = 0; n < ARRSIZE; n++) {
		// baseAddr[n] = n;
		int randomNum = rand() % 1000;
		baseAddr[n] = randomNum;
	}*/

	int baseAddr[] = {316, 817, 582, 68, 712, 10, 125, 166, 920, 541, 317, 914, 440, 565, 107, 720, 415, 659, 121, 739, 614, 531, 428, 905, 758, 297, 702, 133, 183, 600, 614, 499, 418, 548, 567, 130, 910, 45, 296, 830, 586, 613, 96, 26, 530, 203, 98, 946, 214, 220, 685, 828, 103, 465, 85, 213, 762, 788, 699, 297, 388, 313, 797, 158, 213, 364, 640, 123, 761, 289, 954, 347, 254, 50, 725, 785, 606, 824, 731, 820, 396, 768, 1, 851, 585, 438, 65, 699, 226, 764, 997, 967, 429, 794, 477, 642, 510, 118, 117, 272, 759, 71, 971, 13, 474, 697, 150, 432, 873, 233, 604, 269, 1, 605, 120, 938, 396, 537, 638, 622, 653, 635, 941, 434, 429, 771, 76, 939, 889, 546, 563, 0, 969, 535, 13, 443, 584, 164, 227, 457, 397, 832, 78, 751, 789, 550, 689, 185, 88, 327, 160, 93, 314, 101, 528, 743, 872, 956, 35, 113, 502, 950, 113, 472, 837, 479, 267, 421, 995, 495, 230, 744, 327, 308, 495, 116, 859, 537, 654, 299, 216, 814, 392, 531, 915, 920, 626, 140, 229, 13, 605, 731, 964, 71, 555, 801, 550, 823, 575, 897, 318, 805, 641, 997, 466, 137, 465, 325, 26, 119, 624, 242, 933, 368, 125, 201, 289, 752, 693, 518, 765, 298, 601, 81, 721, 157, 235, 271, 980, 810, 168, 650, 967, 162, 999, 433, 651, 464, 110, 677, 936, 86, 271, 221, 455, 397, 422, 96, 501, 467, 966, 618, 766, 567, 700, 487, 76, 287, 111, 408, 97, 631, 58, 64, 793, 57, 850, 444, 874, 960, 473, 162, 47, 745, 383, 502, 494, 158, 598, 995, 625, 916, 613, 391, 483, 665, 231, 912, 952, 694, 320, 401, 677, 379, 818, 471, 788, 668, 267, 14, 628, 741, 176, 675, 838, 912, 529, 332, 70, 479, 327, 695, 395, 292, 439, 231, 310, 22, 143, 614, 716, 463, 16, 745, 194, 834, 568, 335, 854, 836, 701, 834, 929, 230, 510, 767, 142, 391, 451, 212, 871, 778, 259, 618, 422, 698, 849, 732, 720, 344, 699, 788, 808, 715, 534, 354, 901, 102, 689, 107, 290, 743, 941, 219, 973, 803, 338, 115, 195, 789, 679, 418, 919, 938, 36, 342, 637, 886, 426, 709, 230, 125, 498, 390, 192, 32, 97, 445, 486, 786, 552, 777, 881, 494, 348, 854, 297, 687, 321, 492, 828, 0, 910, 748, 291, 299, 442, 280, 185, 868, 989, 767, 346, 839, 510, 538, 223, 607, 984, 710, 745, 536, 839, 627, 382, 187, 833, 680, 226, 155, 172, 55, 507, 435, 803, 798, 734, 597, 430, 271, 465, 420, 390, 163, 259, 252, 54, 483, 859, 390, 545, 957, 278, 384, 936, 661, 571, 769, 341, 798, 276, 865, 853, 784, 652, 8, 934, 386, 605, 365, 9, 422, 137, 752, 938, 748, 4, 992, 583, 216, 382, 128, 525, 660, 512, 461, 321, 436, 582, 14, 234, 859, 880, 439, 995, 532, 799, 281, 271, 756, 998, 280, 530, 135, 384, 468, 884, 389, 812, 467, 605, 194, 948, 482, 855, 460, 943, 528, 248, 525, 543, 834, 736, 775, 625, 83, 307, 424, 365, 930, 532, 363, 211, 415, 851, 595, 883, 735, 336, 696, 554, 293, 242, 502, 775, 449, 315, 70, 978, 915, 948, 873, 750, 684, 648, 375, 768, 307, 152, 485, 238, 684, 848, 801, 99, 699, 748, 335, 786, 437, 383, 693, 730, 625, 547, 858, 427, 214, 928, 757, 130, 876, 630, 880, 913, 630, 255, 33, 289, 407, 518, 879, 444, 718, 32, 543, 418, 781, 230, 556, 218, 613, 249, 300, 591, 797, 158, 18, 363, 439, 775, 493, 315, 757, 373, 580, 739, 981, 613, 28, 388};

	hls::stream<axis_t> mockImageStream;

	std::cout << "~~ Calling the frame_read() function ~~" << std::endl;
	frame_read(&height, &width, &stride, baseAddr, mockImageStream);

	std::cout << "~~ Comparing read values with the expected values ~~" << std::endl;

	bool error = false;
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			axis_t pixel = mockImageStream.read();
			std::cout << "TDATA: " << pixel.data << std::endl;
			std::cout << "TLAST: " << pixel.last << std::endl;
			std::cout << "TSTRB: " << pixel.strb << std::endl;
			std::cout << "TKEEP: " << pixel.keep << std::endl;
			std::cout << "TUSER: " << pixel.user << std::endl;
			std::cout << "mockImageStream.empty(): " << mockImageStream.empty() << std::endl;
			std::cout << "baseAddr[row * (stride/4) + col] = " << baseAddr[row * (stride/4) + col] << std::endl;
			if (baseAddr[row * (stride/4) + col] != pixel.data) {
				std::cout << "~~ MISMATCH DETECTED, SIMULATION FAILED ~~" << std::endl;
				std::cout << "~~ READ VALUE: " << pixel.data << "~~" << std::endl;
				std::cout << "~~ EXPECTED VALUE: " << baseAddr[row * (stride/4) + col] << "~~" << std::endl;
				error = true;
			}
			if (col == width - 1 && pixel.last != 1) {
				std::cout << "~~ INCORRECT TLAST VALUE, SIMULATION FAILED ~~" << std::endl;
				std::cout << "~~ READ VALUE: " << pixel.last << "~~" << std::endl;
				std::cout << "~~ EXPECTED VALUE: 1 ~~" << std::endl;
				error = true;
			}
			if (col == 0 && row == 0 && pixel.user != 1) {
				std::cout << "~~ INCORRECT TUSER VALUE, SIMULATION FAILED ~~" << std::endl;
				std::cout << "~~ READ VALUE: " << pixel.user << "~~" << std::endl;
				std::cout << "~~ EXPECTED VALUE: 1 ~~" << std::endl;
				error = true;
			}

			if (error) {
				std::cout << "~~ ERROR DETECTED AT col=" << col << ", row=" << row << " ~~" << std::endl;
				return 1;
			}
		}
	}

	std::cout << "~~ Simulation finished without errors ~~" << std::endl;
	return 0;
}
