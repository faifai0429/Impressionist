#include "Math.h"

Math::Math()
{
}

int Math::rand_range(int a, int b)
{
	return (double) rand() / (RAND_MAX + 1) * (b - a) + a;
}

float Math::distance(const int a1, const int a2, const int b1, const int b2) {
	return sqrt((float)((a1 - b1) * (a1 - b1) + (a2 - b2) * (a2 - b2)));
}


Math::~Math()
{
}
