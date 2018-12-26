#pragma once
#include "MyString.h"
class Distance
{
public:
	Distance();
	void set_distance(const MyString& city_name, const int distance);
	MyString get_name() const { return city_name_; }
	int get_distance() const { return distance_; }
	MyString city_name_;
	int distance_ = 0;
private:

};

