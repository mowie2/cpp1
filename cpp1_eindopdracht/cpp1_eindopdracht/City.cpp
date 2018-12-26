#include "pch.h"
#include "City.h"
#include "Player.h"

City::City(const MyString& name, MyList<Ship> shipList)
{
	shipFactory_ = ShipFactory(shipList);
	this->city_name_ = name;
	canons_ = MyList<CanonStock>(3);
	canons_[0] = CanonStock(Canon("licht", 0, 2));
	canons_[1] = CanonStock(Canon("middelgroot", 0, 3));
	canons_[2] = CanonStock(Canon("zwaar", 0, 6));
}
/*
void City::set_name(const MyString& name)
{
	this->city_name_ = name;
}*/

MyString City::get_name() const
{
	return city_name_;
}

int City::get_distance_index(const MyString & city_name)
{
	for(auto c = 0;c<distances.get_size();c++)
	{
		if(distances[c].get_name().equals(city_name))
		{
			return c;
		}
	}
	return -1;
}

int City::get_item_index(const MyString & item_name)
{
	for (auto c = 0;c < items.get_size();c++)
	{
		if (items[c].get_item().get_name().equals(item_name))
		{
			return c;
		}
	}
	return -1;
}

void City::buyShip(Player& p)
{
	p.playerShip = shipFactory_.getFregat();
}
