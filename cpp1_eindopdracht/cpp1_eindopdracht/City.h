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
	City() = default;
	City(const MyString& name,const MyList<Ship>& shipList);
	//City(const MyString& name,const MyList<Ship>& shipList);
	MyString get_name() const;

	int get_distance_index(const MyString & city_name);
	int get_item_index(const MyString & item_name);

	MyList<ItemStock> items;
	void buyShip(Player& p);
	MyList<Distance> distances;
private:
	MyList<CanonStock> canons_;
	MyString city_name_;
	ShipFactory shipFactory_;
};
