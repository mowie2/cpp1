#pragma once
#include  "MyString.h"

class City
{
public:
	City() = default;

	City(const MyString cityName) : cityName_(cityName)
	{
	};
	~City() = default;

	MyString GetName() const;
private:
	const MyString cityName_;
};
