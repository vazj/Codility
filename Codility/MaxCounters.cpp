// See https://codility.com/train/ - Lesson 2
//

#include "stdafx.h"
#include "MaxCounters.h"

using namespace std;

// For Codility the solutions need to be written in C++ 98
std::vector<int> MaxCounters(int N, std::vector<int> &A)
{
	long M = A.size();
	vector<int> counters(N, 0);

	long jumpToValue = 0;
	long maxCounter = 0;

	for (long l = 0; l < M; l++)
	{
		int val = A[l];
		if (val <= N)
		{
			// We should already be at jumpToValue if it's higher than us
			if (counters[val - 1] < jumpToValue)
			{
				counters[val - 1] = jumpToValue;
			}

			counters[val - 1]++;

			// Record the current highest value
			if (counters[val - 1] > maxCounter)
			{
				maxCounter = counters[val - 1];
			}
		}
		else if (val == (N + 1))
		{
			jumpToValue = maxCounter;
		}
	}

	// Ensure everything is at least the jumpToValue
	for (long l = 0; l < N; l++)
	{
		if (counters[l] < jumpToValue)
		{
			counters[l] = jumpToValue;
		}
	}

	return counters;
}