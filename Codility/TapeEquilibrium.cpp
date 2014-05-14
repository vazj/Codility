// See https://codility.com/train/ - Lesson 1
//

#include "stdafx.h"
#include "TapeEquilibrium.h"

#include <limits>

using namespace std;

// For Codility the solutions need to be written in C++ 98
// Parameter names as per Codility.
int TapeEquilibrium(std::vector<int> &A) 
{
	vector<int> leftSlice;
	leftSlice.reserve(A.size());

	// Sum up the total vector contents
	long sum = 0;
	for (vector<int>::iterator it = A.begin(); it != A.end(); ++it)
	{
		sum += *it;
	}

	// Move through a second time adjusting sums for the current element
	long leftSum = 0;
	long rightSum = sum;
	long minDiff = numeric_limits<long>::max();
	for (unsigned long l = 1; l < A.size(); l++)
	{
		leftSum += A[l - 1];
		rightSum -= A[l - 1];

		long diff = abs(leftSum - rightSum);
		if (diff < minDiff)
		{
			minDiff = diff;
		}
	}

	return minDiff;
}
