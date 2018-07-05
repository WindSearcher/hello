// Practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Screen.h"
#include "CConsole.h"
#include <iostream>
#include <string>
#pragma warning(disable:4996)

using namespace std;

int main() {
	Screen s;
	CConsole console;
	console.HideCursor(true);
	s.Initial();
	
	return 0;
}
