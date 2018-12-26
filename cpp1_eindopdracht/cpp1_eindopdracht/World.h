#pragma once
#include "MyString.h"
#include "Ship.h"
//#include "City.h" 

class City;
class World
{	
public:
	World();
	World(const World & other) = delete;
	World(World && other) = delete;
	World& operator= (World & other) = delete;
	World& operator= (World && other) = delete;
	~World();

	void read(const char *filepath, char * &par, int &string_length);

	//also reads city names
	void load_city_distances();

	//also read item names
	bool load_item_stock();
	bool load_item_prices();
	bool load_ships();
	
	int city_index(const char* name) const;
	int city_index(const MyString &name) const;
	City & get_city(const int index) const;

	
private:
	City * cities_;
	int count_cities_ = 0;
	Ship * ships_;
	//City * cities_ ;
};

