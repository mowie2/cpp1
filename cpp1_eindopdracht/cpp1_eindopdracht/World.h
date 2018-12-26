#pragma once
#include "MyString.h"
#include "Ship.h"
#include "City.h" 
#include "MyList.h"
#include "File.h"
#include "Player.h"

class World
{
public:
	World();
	World(const World & other) = delete;
	World(World && other) = delete;
	World& operator= (World & other) = delete;
	World& operator= (World && other) = delete;
	~World();

	bool read();

	//todo wordt nog niet gecheck of cities bestaan
	bool load_city_distances(MyList<MyList<MyString>> data);

	int city_index(const char* name);
	int city_index(const MyString &name);
	City & get_city(const int index);



	MyList<City> cities_;
	int count_cities_ = 0;
	MyList<Ship> ships_;

	void start();

private:
	//MyList<City> cities_;
	//int count_cities_ = 0;
	//MyList<Ship> ships_;
	//City * cities_ ;
	bool gameIsOver();
	void load_cities(MyList<MyString>& cities);
	void load_items(MyList<MyString>& items);

	//todo wordt nog niet gecheck of cities of items bestaan. not exception safe
	bool load_item_amount(MyList<MyList<MyString>> data);
	//todo wordt nog niet gecheck of cities of items bestaan. not exception safe
	bool load_item_price(MyList<MyList<MyString>> data);

	void load_ships(MyList<MyList<MyString>> data);

	Player player_;
};

