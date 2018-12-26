#pragma once
#include "MyString.h"
class Distance
{
public:
	Distance() = default;
	Distance(const MyString& city_name, const int distance);
	MyString get_name() const;
	int get_distance() const;
	
private:
	MyString city_name_;
	int distance_ = 0;
};

