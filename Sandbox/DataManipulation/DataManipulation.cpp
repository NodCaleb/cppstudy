#include "DataManipulation.h"

const int powers[8] = {1, 2, 4, 8, 16, 32, 64, 128};

void transponseSegment(char * data) {
    
    int matrix[8][8];

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            matrix[i][j] = (data[j] >> i) & 1;
        }
    }

    for (int i = 0; i < 8; i++)
    {
        int val = 0;

        for (int j = 0; j < 8; j++)
        {
            val += matrix[i][j] * powers[7 - j];
        }

        data[7 - i] = (char)val;
    }
}

int main() {

	char initial[8] = { 0xC0, 0x27, 0x20, 0x18, 0x18, 0x18, 0x26, 0x13 };

    transponseSegment(initial);

	return 0;
}