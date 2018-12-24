#pragma once
#include "MyString.h"
#include "Distance.h"
#include "Item.h"

class City
{
public:
	City() = default;
	City(const MyString &city_name) : city_name_(city_name){};
	City(const City & other);
	City(City && other);
	City& operator=(const City & other);
	City& operator=(City && other);
	~City();

	MyString get_name() const;

	void set_distance_count(const int count);
	void set_distance(const int index,const MyString name,const int distance);
	int get_distance_index();
	Distance& get_distance_to(const int index) const;

	void set_items_count(const int count);
	void set_item(const int index, const MyString name, const int min, const int max);
	int get_item_index();
	Item& get_items(const int index) const;

	
	
private:
	Item * items_;
	Distance * distances_;
	MyString city_name_;
	//Distance * distances_;
	//Item * items_;
	int amount_distances_ = 0;
	int amount_items_ = 0;
};
