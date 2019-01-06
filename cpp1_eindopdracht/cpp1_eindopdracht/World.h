#pragma once
#include "MyString.h"
#include "Ship.h"
#include "City.h" 
#include "MyList.h"
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

	int city_index(const char* name);
	int getCityByName(const MyString &name);

	

	void DoSeaLogic();
	void DoCityLogic();
	bool SetDestination();

	void calculateEvent();
	void Geen();
	void Briesje();
	void Zwak();
	void Normaal();
	void Sterk();
	void Storm();

	void start();

private:
	const MyString AT_SEA = "sea";
	//MyList<City> cities_;
	//int count_cities_ = 0;
	//MyList<Ship> ships_;
	//City * cities_ ;
	bool gameIsOver();
	void load_cities(MyList<MyString>& cities);
	void load_items(MyList<MyString>& items);


	//todo wordt nog niet gecheck of cities bestaan
	bool load_city_distances(MyList<MyList<MyString>> data);
	//todo wordt nog niet gecheck of cities of items bestaan. not exception safe
	bool load_item_amount(MyList<MyList<MyString>> data);
	//todo wordt nog niet gecheck of cities of items bestaan. not exception safe
	bool load_item_price(MyList<MyList<MyString>> data);

	void load_ships(MyList<MyList<MyString>> data);
	void load_item_ships();

	Player player_;
	MyList<City> cities_;
	MyList<Ship> ships_;
	MyString currentPlayerLocation_;
	MyString destinationPlayer_;
	int remainingDistance;
};

