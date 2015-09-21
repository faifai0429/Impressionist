#pragma once
#include <stdlib.h>
#include <math.h>
#include <time.h>

class Math
{
public:
	Math();
	~Math();

	static int rand_range(const int a, const int b);
	static float distance(const int a1, const int b1, const int a2, const int b2);
};

