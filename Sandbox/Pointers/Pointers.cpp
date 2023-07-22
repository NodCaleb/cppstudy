#include "Pointers.h"
#include <iostream>
using namespace std;

void fillArray(int * pointerToArray) {

	
	for (int i = 0; i < 4; i++)
	{
		pointerToArray[i] = (i + 1) * 15;
	}

}

int main() {

	int array[4];

	fillArray(array);

	for (int i = 0; i < 4; i++)
	{
		cout << array[i] << ";";
	}

	return 0;
}