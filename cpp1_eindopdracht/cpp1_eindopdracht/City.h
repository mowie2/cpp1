#pragma once
#include "MyString.h"
#include "Distance.h"
#include "MyList.h"
#include "ItemStock.h"
#include "CanonStock.h"
#include "Player.h"
#include "ShipFactory.h"

class City
{
public:
	//City(MyList<Ship> shipList);
	//City(const MyString &city_name) : city_name(city_name){};
	//City(const City & other);
	//City(City && other);
	//City& operator=(const City & other);
	//City& operator=(City && other);
	//~City();
	City() = default;
	City(const MyString& name, MyList<Ship>);
	void set_name(const MyString& name);
	MyString get_name() const;

	//void set_distance_count(const int count);
	//void set_distance(const int index,const MyString name,const int distance);
	int get_distance_index();
	//Distance& get_distance(const int index);

	//void set_items_count(const int count);
	//void set_item(const int index, const MyString name, const int min, const int max);
	int get_item_index();
	//Item& get_item(const int index);

	MyList<ItemStock> items;
	void buyShip(Player& p);
	MyList<Distance> distances;
private:
	MyList<CanonStock> canons_;
	MyString city_name_;
	ShipFactory shipFactory_;
};
