#include "pch.h"
#include "Canon.h"


Canon::Canon()
{
}

Canon::Canon(const MyString & type, const int min, const int max)
{
	type_ = type;
	min_damage_ = min;
	max_damage_ = max;
}


Canon::~Canon()
{
}
