// See https://codility.com/train/ - Lesson 3
//

#include "stdafx.h"
#include "GenomicRangeQuery.h"

using namespace std;

// For Codility the solutions need to be written in C++ 98
// Parameter names as per Codility.
std::vector<int> GenomicRangeQuery(std::string& S, std::vector<int> &P, std::vector<int> &Q)
{
	// To do this quickly the key is to count how many of each neucleotide we've
	// seen at any given point ie if we were doing slice 3-6 we'd have seen one
	// A by 3 but two by position 6. Two minus one is obviously one so A must be our 
	// minimum neucleotide.
	vector<vector<long> > sumsAtPosition;
	vector<long> currentSums(4, 0);

	// Record the empty starting state 
	sumsAtPosition.push_back(currentSums);

	for (long l = 0; l < (long)S.size(); l++)
	{
		// A = 1, C = 2, G = 3, T = 4 so we can just put them in appropriate order in the currentSums vector
		switch (S[l])
		{
		case 'A':
			currentSums[0]++;
			break;
		case 'C':
			currentSums[1]++;
			break;
		case 'G':
			currentSums[2]++;
			break;
		case 'T':
			currentSums[3]++;
			break;
		}

		sumsAtPosition.push_back(currentSums);
	}

	vector<int> minNeucleotides;
	minNeucleotides.reserve(P.size());

	for (long l = 0; l < (long)P.size(); l++)
	{
		// Given the codility constraints we shouldn't have any infite loop or out of bounds issues here.
		long index = 0;
		long minNeucleotide = 0;

		for (int index = 0; index < 4; index++)
		{
			if (sumsAtPosition[Q[l] + 1][index] - sumsAtPosition[P[l]][index])
			{
				minNeucleotide = index + 1;
				break;
			}
		}

		minNeucleotides.push_back(minNeucleotide);
	}

	return minNeucleotides;
}