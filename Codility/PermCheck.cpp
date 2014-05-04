// See https://codility.com/train/ - Lesson 2
//

#include "stdafx.h"
#include "PermCheck.h"

using namespace std;

// For Codility the solutions need to be written in C++ 98
int PermCheck(std::vector<int> &A) 
{
	long N = A.size();

	// If we can go through the loop from A to N without hitting a number we've
	// seen before then we must have a permutation.
	vector<bool> B(N + 1, false);
	for (long l = 0; l < N; l++)
	{
		if (A[l] > N || B[A[l]])
		{
			return 0;
		}

		B[A[l]] = true;
	}

	return 1;
}
