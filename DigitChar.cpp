#include "stdafx.h"
#include "DigitChar.h"


char* DigitChar::DIGITCHAR = "¡ö"; //¡õ¡ö¡ï¡î¡ô¡ó¡ñ¡ð¦æ¦ç
char* DigitChar::SPACECHAR = "  "; // Á½¸ö¿Õ¸ñ

void DigitChar::getDigit(char digit)
{
	int row = 0;
	int col = 0;

	switch(digit)
	{
	case '0':
		for(row = 0; row < ROWS; row++)
		{
			for(col = 0; col < COLS; col++)
			{
				if((row ==1 && col==1)||(row ==2 && col==1) || (row ==3 && col==1))
				{
					CHART[row][col] = SPACECHAR;
				}
				else
				{
					CHART[row][col] = DIGITCHAR;
				}
			}
		}
		break;

	case '1':
		for(row = 0; row < ROWS; row++)
		{
			for(col = 0; col < COLS; col++)
			{
				if(col<2)
				{
					CHART[row][col] = SPACECHAR;
				}
				else
				{
					CHART[row][col] = DIGITCHAR;
				}
			}
		}
		break;

	case '2':
		for(row = 0; row < ROWS; row++)
		{
			for(col = 0; col < COLS; col++)
			{
				if((row ==1 && col==0)||(row ==1 && col==1) || (row ==3 && col==1) || (row ==3 && col==2))
				{
					CHART[row][col] = SPACECHAR;
				}
				else
				{
					CHART[row][col] = DIGITCHAR;
				}
			}
		}
		break;
		
	case '8':
		for(row = 0; row < ROWS; row++)
		{
			for(col = 0; col < COLS; col++)
			{
				if((row ==1 && col==1)||(row ==3 && col==1))
				{
					CHART[row][col] = SPACECHAR;
				}
				else
				{
					CHART[row][col] = DIGITCHAR;
				}
			}
		}
	}
}

void DigitChar::printDigit(int col, int row)
{
	int cX = col;
	int cY = row;
	console.SetCoord(cX, cY);

	for(int r = 0; r < ROWS; r++)
	{
		for(int c = 0; c < COLS; c++)
		{
			printf("%s", CHART[r][c]);
		}
		cY = cY + 1;
		console.SetCoord(cX, cY);
	}
}