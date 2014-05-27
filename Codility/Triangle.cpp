// See https://codility.com/train/ - Lesson 4
//

#include "stdafx.h"
#include "Triangle.h"

#include <algorithm>

using namespace std;

// For Codility the solutions need to be written in C++ 98
// Parameter names as per Codility.
int Triangle(const vector<int> &A) 
{
	vector<long long> B(A.begin(), A.end());

	// Sort to ensure we have the smallest possible 
	// gaps between consecutive numbers
	sort(B.begin(), B.end());

	// Once sorted do the triangle checks
	for (long l = 0; l < (long)B.size() - 2; l++)
	{
		long P = l;
		long Q = l + 1;
		long R = l + 2;

		if (B[P] + B[Q] > B[R] &&
			B[Q] + B[R] > B[P] &&
			B[R] + B[P] > B[Q])
		{
			return 1;
		}
	}

	return 0;
}
