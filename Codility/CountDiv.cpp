// See https://codility.com/train/ - Lesson 3
//

#include "stdafx.h"
#include "CountDiv.h"
#include <cmath>

using namespace std;

// For Codility the solutions need to be written in C++ 98
// Parameter names as per Codility.
int CountDiv(int A, int B, int K)
{
	unsigned long kInB = (unsigned long)floor((double)B / (double)K);
	unsigned long kInA = (unsigned long)floor((double)(A - 1.0) / (double)K);

	return kInB - kInA;
}
