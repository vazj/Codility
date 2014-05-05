#include "stdafx.h"
#include <iostream>
#include "TapeEquilibrium.h"
#include "FrogJmp.h"
#include "PermMissingElem.h"
#include "PermCheck.h"
#include "FrogRiverOne.h"
#include "MaxCounters.h"

using namespace std;

// Little test output helper
template<typename resultType>
bool Test(string& name, resultType expectedResult, resultType result)
{
	if (result == expectedResult)
	{
		cout << name.c_str() << " - Passed" << endl;
		return true;
	}
	else
	{
		cout << name.c_str() << " - Failed" << endl;
		return false;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	// Run through all the codility challenges completed so far.
	// All challenges have been completed at 100% on the codility site so
	// no serious testing is done here.
	cout << "Codilty Tests:" << endl << endl;

	// Lesson 1 - Time Complexity
	// TapeEquilibrium
	std::vector<int> A = { 3, 1, 2, 4, 3 };
	Test<int>(string("TapeEquilibrium"), 1, TapeEquilibrium(A));

	// FrogJmp
	Test<int>(string("FrogJmp"), 3, FrogJmp(10, 85, 30));

	// PermMissingElem
	A = { 2, 3, 1, 5 };
	Test<int>(string("PermMissingElem"), 4, PermMissingElem(A));

	// Lesson 2 - Counting Elements
	// PermCheck
	A = { 4, 1, 3, 2 };
	Test<int>(string("PermCheck"), 1, PermCheck(A));

	// FrogRiverOne
	A = { 1, 3, 1, 4, 2, 3, 5, 4 };
	Test<int>(string("FrogRiverOne"), 6, FrogRiverOne(5, A));

	// MaxCounters
	A = { 3, 4, 4, 6, 1, 4, 4 };
	vector<int> B = { 3, 2, 2, 4, 2 };
	Test<vector<int>>(string("MaxCounters"), B, MaxCounters(5, A));


	getchar();

	return 0;
}

