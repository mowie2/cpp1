#pragma once
#include "MyString.h"
#include "Distance.h"
#include "Item.h"
#include "MyList.h"

class City
{
public:
	City() = default;
	//City(const MyString &city_name) : city_name(city_name){};
	//City(const City & other);
	//City(City && other);
	//City& operator=(const City & other);
	//City& operator=(City && other);
	//~City();

	//MyString get_name() const;

	//void set_distance_count(const int count);
	//void set_distance(const int index,const MyString name,const int distance);
	int get_distance_index();
	//Distance& get_distance(const int index);

	//void set_items_count(const int count);
	//void set_item(const int index, const MyString name, const int min, const int max);
	int get_item_index();
	//Item& get_item(const int index);

	MyList<Item> items;
	MyList<Distance> distances;
	MyString city_name;
	/*
private:
	MyList<Item> items_;
	MyList<Distance> distances_;
	MyString city_name_;
	//int amount_distances_ = 0;
	//int amount_items_ = 0;*/
};
