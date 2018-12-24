#include "pch.h"
#include "Distance.h"


Distance::Distance()
{
}

void Distance::set_distance(const MyString& city_name,const int distance)
{
	city_name_ = city_name;
	distance_ = distance;
}