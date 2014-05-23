// See https://codility.com/train/ - Lesson 4
//

#include "stdafx.h"
#include "MaxProductOfThree.h"

#include <algorithm>

using namespace std;

// For Codility the solutions need to be written in C++ 98
// Parameter names as per Codility.
int MaxProductOfThree(std::vector<int> &A) 
{
	sort(A.begin(), A.end());
	long N = A.size();

	long long largestLower = A[0] * A[1] * A[2];
	long long largestTwoLower = A[0] * A[1] * A[N - 1];
	long long largestUpper = A[N - 1] * A[N - 2] * A[N - 3];

	long long largestMin = largestLower > largestTwoLower ? largestLower : largestTwoLower;

	// Obviously a strange cast but done in order to fit with codility. 
	return (int)(largestUpper > largestMin ? largestUpper : largestMin);
}
