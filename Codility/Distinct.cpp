// See https://codility.com/train/ - Lesson 4
//

#include "stdafx.h"
#include "Distinct.h"

#include <limits>
#include <algorithm>

using namespace std;

// For Codility the solutions need to be written in C++ 98
// Parameter names as per Codility.
int Distinct(const std::vector<int> &A) 
{
	vector<int> B(A);
	sort(B.begin(), B.end());

	long numDistinctVals = 0;
	long lastDistinctVal = numeric_limits<long>::max();
	for (vector<int>::const_iterator it = B.begin(); it != B.end(); ++it)
	{
		if (*it != lastDistinctVal)
		{
			numDistinctVals++;
			lastDistinctVal = *it;
		}
	}

	return numDistinctVals;
}
