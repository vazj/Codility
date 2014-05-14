// See https://codility.com/train/ - Lesson 1
//

#include "stdafx.h"
#include "PermMissingElem.h"

using namespace std;

// For Codility the solutions need to be written in C++ 98
// Parameter names as per Codility.
int PermMissingElem(std::vector<int> &A) 
{
	unsigned long total = 0;
	for (vector<int>::iterator it = A.begin(); it != A.end(); ++it)
	{
		total += *it;
	}

	// Range is 1..N+1 
	unsigned long N = A.size() + 1;
	long theoTotal = (long)((double)(N * (N + 1)) / 2.0);

	return theoTotal - total;
}
