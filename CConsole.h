#ifndef CCONSOLE_H
#define CCONSOLE_H

#include <windows.h>	// HANDLE
#include <stdio.h>		// sprintf

class CConsole
{
private:
	COORD coord;
	HANDLE HConsole;

public:
	CConsole();
	~CConsole();
	
	void SetCoord(int x, int y);
	void HideCursor(bool hide);
	void SetTitle(char* title);
	void SetSize(int width, int height);
	void SetColor(char* cl);
};

#endif