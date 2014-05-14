// See https://codility.com/train/ - Lesson 3
//

#include "stdafx.h"
#include "PassingCars.h"

using namespace std;

// For Codility the solutions need to be written in C++ 98
// Parameter names as per Codility.
int PassingCars(std::vector<int> &A)
{
	long zeroCount = 0L;
	long passingCars = 0L;
	for (long l = 0; l < (long)A.size(); l++)
	{
		if (A[l] == 0)
		{
			zeroCount++;
		}
		else
		{
			passingCars += zeroCount;
			if (passingCars > 1000000000L)
			{
				return -1;
			}
		}
	}

	return passingCars;
}