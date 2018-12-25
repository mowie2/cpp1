#pragma once
#include  "MyString.h"
#include "Inventory.h"

class City
{
public:
	City() = default;

	City(MyString* cityName) : cityName_(cityName)
	{
	};
	~City() = default;

	MyString& getName() const;

private:

	MyString* cityName_;
	Inventory* inventory_;

	void generateItems();

};
