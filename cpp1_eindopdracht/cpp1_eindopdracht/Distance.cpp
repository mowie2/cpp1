#include "pch.h"
#include "Distance.h"

Distance::Distance(const MyString& city_name, const int distance)
{
	city_name_ = city_name;
	distance_ = distance;
}

MyString Distance::get_name() const
{
	return city_name_;
}

int Distance::get_distance() const
{
	return distance_;
}
