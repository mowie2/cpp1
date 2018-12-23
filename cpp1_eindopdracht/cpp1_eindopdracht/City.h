#pragma once
#include  "MyString.h"

class City
{
public:
	City() = default;

	City(const MyString &city_name) : city_name_(city_name)
	{
	};

	City(const City & other);

	City(City && other);

	City& operator=(const City & other);

	City& operator=(City && other);

	MyString get_name() const;
private:
	MyString city_name_;
};
