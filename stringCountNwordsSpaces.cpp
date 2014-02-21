// stringCountNwordsSpaces.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<stdio.h>
#include<conio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 0, chr = 0, sp = 0, words = 1, ss = 0, digits = 0;
	char line[100], temp = 32;
	//clrscr();
	printf("\nEnter the line:\n");
	gets_s(line);

	while (line[i] != '\0')                                            //to check for string termination
	{
		if ((line[i]>64 && line[i]<91) || (line[i]>96 && line[i]<123))               // ascii range of capital and lowercase characters
			chr++;
		else
		{
			if (line[i] == 32)                                                                  //ascii value of  space is 32
			{
				sp++;
				if (temp != 32) //temp holds the previous charachter we tracked
					words++;
			}
			else
			{
				if (line[i]>47 && line[i]<58)                                     //ascii range of digits
					digits++;
				else
					ss++; //special signs
			}
		}
		temp = line[i]; //remember prevous character into the temp
		i++; //then continue to the next character
	}
	printf("\nNumber of characters = %d words = %d spaces %d special symbols = %d digits = %d", chr, words, sp, ss, digits);

	getchar();
	return 0;
}
