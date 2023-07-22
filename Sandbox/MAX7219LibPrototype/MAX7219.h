#include<string>

#pragma once
class MAX7219
{
public:
	int getCharSize(char);
	int getCharOffset(char);
	void fillDisplayBuffer(void);
	void scrollDisplay(void);
	void transponseDisplayBuffer(void);
	void fillText(std::string text);	
};

