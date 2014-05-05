// See https://codility.com/train/ - Lesson 2
//

#include "stdafx.h"
#include "FrogRiverOne.h"

using namespace std;

// For Codility the solutions need to be written in C++ 98
int FrogRiverOne(int X, std::vector<int> &A)
{
	long count = X;
	vector<bool> leafAt(X, false);

	for (long l = 0; l < (long)A.size(); l++)
	{
		// If we've not seen a leaf fall at this position before then
		// mark it as there and reduce our count by one. Doing this will mean
		// that once we've seen leaf at every spot between 1 and X inclusive count
		// will be 0.
		long val = A[l] - 1;
		if (leafAt[val] == false)
		{
			leafAt[val] = true;
			count--;
		}

		if (count == 0)
		{
			return l;
		}
	}

	return -1;
}
