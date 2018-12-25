#include  "pch.h"
#include "MyRandom.h"
#include <random>
#include <ctime>

int MyRandom::Range(int low, int high)
{
	std::default_random_engine generator;
	generator.seed(time(0));
	std::uniform_int_distribution<int> distribution1(low, high);
	return distribution1(generator);
}
