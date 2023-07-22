#include <string>
#include "MAX7219.h"

int main(void) {

	std::string text = "SAMPLE TEXT";

	MAX7219 max;

	max.fillText(text);

	/*fillText(text);

	fillDisplayBuffer();

	transponseDisplayBuffer();*/

	return 0;
}