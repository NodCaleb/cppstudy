#include "MAX7219.h"
#include<string>

const int maxDataSize = 1024;
int font[171] = { 0x10, 0x20, 0x7E, 0x26, 0x4A, 0x4A, 0x32, 0x24, 0x42, 0x52, 0x2C, 0x18, 0x28, 0x48, 0x7E, 0x74, 0x52, 0x52, 0x4C, 0x3C, 0x4A, 0x4A, 0x24, 0x46, 0x48, 0x50, 0x60, 0x2C, 0x52, 0x52, 0x2C, 0x24, 0x52, 0x52, 0x3C, 0x3C, 0x4A, 0x52, 0x3C, 0x3E, 0x48, 0x48, 0x3E, 0x7E, 0x52, 0x52, 0x2C, 0x3C, 0x42, 0x42, 0x24, 0x7E, 0x42, 0x42, 0x3C, 0x7E, 0x52, 0x52, 0x42, 0x7E, 0x50, 0x50, 0x40, 0x3C, 0x42, 0x4A, 0x2C, 0x42, 0x7E, 0x42, 0xC, 0x2, 0x2, 0x7C, 0x7E, 0x10, 0x28, 0x46, 0x7E, 0x2, 0x2, 0x2, 0x7E, 0x20, 0x10, 0x20, 0x7E, 0x7E, 0x10, 0x8, 0x7E, 0x3C, 0x42, 0x42, 0x3C, 0x7E, 0x48, 0x48, 0x30, 0x3C, 0x42, 0x42, 0x3E, 0x2, 0x7E, 0x48, 0x48, 0x36, 0x24, 0x52, 0x4A, 0x24, 0x40, 0x40, 0x7E, 0x40, 0x40, 0x7E, 0x2, 0x2, 0x7E, 0x7C, 0x2, 0x2, 0x7C, 0x7C, 0x2, 0xC, 0x2, 0x7C, 0x6E, 0x10, 0x10, 0x6E, 0x60, 0x10, 0xE, 0x10, 0x60, 0x46, 0x4A, 0x52, 0x62, 0x20, 0x4A, 0x48, 0x30, 0x7A, 0x2, 0x3, 0x3C, 0x42, 0x42, 0x3C, 0x2, 0x2, 0x2, 0x24, 0x26, 0x26, 0x8, 0x10, 0x64, 0x30, 0x4C, 0x52, 0x54, 0x4A, 0x0, 0x0, 0x0 };
int displayData[maxDataSize];
int displayBuffer[32];
int displayOffset = 0;
int dataSize = 0;

int MAX7219::getCharSize(char a) {
	switch (a)
	{
	case '1': return 3;
	case '2': return 4;
	case '3': return 4;
	case '4': return 4;
	case '5': return 4;
	case '6': return 4;
	case '7': return 4;
	case '8': return 4;
	case '9': return 4;
	case '0': return 4;
	case 'A': return 4;
	case 'B': return 4;
	case 'C': return 4;
	case 'D': return 4;
	case 'E': return 4;
	case 'F': return 4;
	case 'G': return 4;
	case 'H': return 3;
	case 'I': return 4;
	case 'J': return 4;
	case 'K': return 4;
	case 'L': return 5;
	case 'M': return 4;
	case 'O': return 4;
	case 'P': return 4;
	case 'Q': return 5;
	case 'R': return 4;
	case 'S': return 4;
	case 'T': return 5;
	case 'U': return 4;
	case 'V': return 4;
	case 'W': return 5;
	case 'X': return 4;
	case 'Y': return 5;
	case 'Z': return 4;
	case '?': return 4;
	case '!': return 1;
	case '.': return 1;
	case ',': return 1;
	case '(': return 2;
	case ')': return 2;
	case '_': return 3;
	case ':': return 1;
	case ';': return 1;
	case '%': return 4;
	case '@': return 5;
	case ' ': return 3;
	default: return 0;
	}
}

int MAX7219::getCharOffset(char a) {
	switch (a)
	{
	case '1': return 0;
	case '2': return 3;
	case '3': return 7;
	case '4': return 11;
	case '5': return 15;
	case '6': return 19;
	case '7': return 23;
	case '8': return 27;
	case '9': return 31;
	case '0': return 35;
	case 'A': return 39;
	case 'B': return 43;
	case 'C': return 47;
	case 'D': return 51;
	case 'E': return 55;
	case 'F': return 59;
	case 'G': return 63;
	case 'H': return 67;
	case 'I': return 70;
	case 'J': return 74;
	case 'K': return 78;
	case 'L': return 82;
	case 'M': return 87;
	case 'O': return 91;
	case 'P': return 95;
	case 'Q': return 99;
	case 'R': return 104;
	case 'S': return 108;
	case 'T': return 112;
	case 'U': return 117;
	case 'V': return 121;
	case 'W': return 125;
	case 'X': return 130;
	case 'Y': return 134;
	case 'Z': return 139;
	case '?': return 143;
	case '!': return 147;
	case '.': return 148;
	case ',': return 149;
	case '(': return 150;
	case ')': return 152;
	case '_': return 154;
	case ':': return 157;
	case ';': return 158;
	case '%': return 159;
	case '@': return 163;
	case ' ': return 168;
	default: return 0;
	}
}

void MAX7219::fillDisplayBuffer() {

	for (size_t i = 0; i < 32; i++)
	{
		displayBuffer[i] = displayData[displayOffset + i];
	}
}

void MAX7219::scrollDisplay() {

	if (displayOffset + 32 >= dataSize) displayOffset = 0;
	else displayOffset++;

	fillDisplayBuffer();
}

void MAX7219::transponseDisplayBuffer() {

	int matrix[8];

	for (size_t k = 0; k < 4; k++)
	{
		for (size_t i = 0; i < 8; i++)
		{
			matrix[i] = 0x00;

			for (size_t j = 0; j < 8; j++)
			{
				if (j > 0) matrix[i] = matrix[i] << 1;
				int line = displayBuffer[j + k * 8];
				line = line >> i;
				line = line & 0x01;
				matrix[i] = matrix[i] | line;
			}
		}

		for (size_t i = 0; i < 8; i++)
		{
			displayBuffer[i + k * 8] = matrix[i];
		}
	}
}

void MAX7219::fillText(std::string text) {

	for (size_t i = 0; i < text.size(); i++)
	{
		int charSize = getCharSize(text[i]);

		if (dataSize + charSize > maxDataSize) break;

		for (size_t j = 0; j < charSize; j++)
		{
			displayData[dataSize + j] = font[getCharOffset(text[i]) + j];
		}

		dataSize += charSize;

		if (i < text.size() - 1)
		{
			displayData[dataSize] = 0x00;
			dataSize++;
		}
	}

	while (dataSize < 32)
	{
		displayData[dataSize] = 0x00;
		dataSize++;
	}

}