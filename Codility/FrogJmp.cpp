// See https://codility.com/train/ - Lesson 1
//

#include "stdafx.h"
#include "FrogJmp.h"

#include <cmath>

// For Codility the solutions need to be written in C++ 98
int FrogJmp(int X, int Y, int D)
{
	return (int)std::ceil((double)(Y - X) / (double)(D));
}
