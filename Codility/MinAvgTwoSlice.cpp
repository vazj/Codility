// See https://codility.com/train/ - Lesson 3
//

#include "stdafx.h"
#include "MinAvgTwoSlice.h"
#include <limits>

using namespace std;

// For Codility the solutions need to be written in C++ 98
// Parameter names as per Codility.
int MinAvgTwoSlice(std::vector<int> &A) 
{
	// Looking at the following scenarios, we can see that there are only really a small number of 
	// possible number combinations that could be combined to create a minimum average slice. All 
	// other longer slices would need to be made from a combination of these scenarios.
	// Ones and zeros are just used here to illustrate high and low values.
	// 1,1 - Two the same
	// 0,1 - low,high
	// 1,0 - high, low
	// 0,1,0 If there had already been a 0,1 found this would need to be found as the lowest
	// 1,1,1 - Would have been found as 1,1 and so on for longer slices
	// -ve numbers are covered by the above scenarios, they're just examples of lower values.

	long N = A.size();
	long minSliceStart = 0;
	double minAvg = numeric_limits<double>::max();
	for (long pos = 0; pos < N - 2; pos++)
	{
		// Find the start of the min slice
		double avgOfTwo = ((double)(A[pos] + A[pos + 1]) / 2.0);
		double avgOfThree = ((double)(A[pos] + A[pos + 1] + A[pos + 2]) / 3.0);
		double lowestCurrentAvg = avgOfTwo < avgOfThree ? avgOfTwo : avgOfThree;

		if (lowestCurrentAvg < minAvg)
		{
			minSliceStart = pos;
			minAvg = lowestCurrentAvg;
		}
	}

	// As we're looping through up to the last 3 we need to check the last 2 before we can be sure 
	// of the result
	if (((double)(A[N - 2] + A[N - 1]) / 2.0) < minAvg)
	{
		minSliceStart = A.size() - 2;
	}

	return minSliceStart;
}
