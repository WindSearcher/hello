#ifndef DIGITCHAR_H
#define DIGITCHAR_H

#include <iostream>
#include <stdio.h>
#include "CConsole.h"


#define ROWS 5
#define COLS 3

class DigitChar
{
private:
	static char* DIGITCHAR;		// Ë«×Ö·û
	static char* SPACECHAR;		// Ë«×Ö·û

	CConsole console;
	char* CHART[ROWS][COLS]; // ¶þÎ¬×Ö·ûÊý×é
	
public:
	void getDigit(char digit);
	void printDigit(int r, int c);
	
};

#endif