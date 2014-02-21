// stringPermutation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
# include <stdio.h>

/* Function to swap values at two pointers */
void swap(char *x, char *y)
{	
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/* Function to print permutations of string
This function takes three parameters:
1. String
2. Starting index of the string
3. Ending index of the string. */
void permute(char *a, int i, int n)
{
	int j;
	if (i == n)
		printf("%s\n", a);
	else
	{
		for (j = i; j <= n; j++)
		{
			swap((a + i), (a + j));
			permute(a, i + 1, n);
			/*with out backtracking ,The string order will not be changed for every iteration.
			try with string "ABCD".you will find repeated patterns with B.
			Once you swap the elements in the every iteration,it is better to swap the elements back to the original order .*/
			swap((a + i), (a + j)); //backtrack
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char a[] = "ABCD";
	permute(a, 0, 3);

	getchar();
	return 0;
}

