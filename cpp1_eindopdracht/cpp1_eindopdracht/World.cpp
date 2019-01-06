#include "pch.h"
#include "World.h"
#include "MyString.h"
#include <iostream>
#include <fstream>
#include <string>
#include "City.h"
#include "File.h"
#include "MyRandom.h"

World::World()
{
	read();
	currentPlayerLocation_ = "sea";
	player_.gold = 999999 + 1;
	cities_[getCityByName("Roatan")].buyShip(player_);
}

World::~World()
{
	//delete[] cities_;
	//delete[] ships_;
}

void World::start()
{
	while (true)
	{
		if (gameIsOver())
		{
			return;
		}

		//TODO: logica voor de stad/shop
		

		if (currentPlayerLocation_ == AT_SEA)
		{
			DoSeaLogic();
		}
	}
}

void World::DoSeaLogic()
{
	while (currentPlayerLocation_ != destinationPlayer_)
	{
		calculateEvent();
	}
}

void World::calculateEvent()
{
	MyRandom random;
	int randomNumber = random.Range(1, 20);

	if (randomNumber == 1 || randomNumber == 2)
	{

	}
	if (randomNumber == 3 || randomNumber == 4)
	{
		Briesje();
	}
	if (randomNumber >= 5 && randomNumber <= 7)
	{
		Zwak();
	}
	if (randomNumber >= 8 && randomNumber <= 17)
	{
		Normaal();
	}
	if (randomNumber == 18 || randomNumber == 19)
	{
		Sterk();
	}
	if (randomNumber == 20)
	{
		Storm();
	}
}

void World::Geen()
{
	//TODO: implimenteer dat er niks gebeurd
}
void World::Briesje()
{
	//TODO: Heeft het schip als bijzonderheid “licht” dan geldt hetzelfde effect
	//als bij normale wind.Zo niet, dan geldt hetzelfde effect als bij geen
	//	wind.
}

void World::Zwak()
{
	//TODO:Heeft het schip als bijzonderheid “log” dan geldt hetzelfde effect
//als bij geen wind.Zo niet, dan geldt hetzelfde effect als bij normale
//	wind..
}
void World::Normaal()
{
	//TODO:al Het schip heeft gevaren en is daarom één beurt dichter genaderd
//tot de haven die het tot doel heeft.
}

void World::Sterk()
{
	//TODO: Er staat zo veel wind dat het schip twee beurten dichter genaderd
// is tot de haven die het tot doel heeft.
}
void World::Storm()
{
	//TODO: Er is 40% kans dat het schip van de koers is geblazen en er één
//beurt langer over doet om bij de haven te komen die het tot doel
	//heeft.
	//Er is 40 % kans dat het schip niet bewogen heeft(hetzelfde
	//	resultaat dus als geen wind).
	//Er is 20 % kans dat het schip de goede richting in geblazen is
	//(hetzelfde resultaat als normale wind).
	//Welk van voorgaande drie resultaten ook, het schip heeft sowieso
	//averij opgelopen en verliest 1 – 100 % van zijn schadepunten.
	//Indien het schip eindigt met 0 of minder schadepunten is het dus
	//in de storm gezonken.
}
bool World::gameIsOver()
{
	return player_.playerHas1milGold() || player_.playerhasDied();
}

//TODO : loading csv files is not exception safe

int World::city_index(const char * name)
{
	for (auto i = 0; i < cities_.get_size(); i++)
	{
		if (cities_[i].get_name().equals(name))
		{
			return i;
		}
	}
	return -1;
}

int World::getCityByName(const MyString & name)
{
	return city_index(name.GetString());
}

void World::load_cities(MyList<MyString>& cities)
{
	cities_ = MyList<City>(cities.get_size() - 1);
	for (auto c = 0; c < cities.get_size() - 1; c++)
	{
		cities_[c] = City(cities[c + 1], ships_);
		std::cout << cities_[c].get_name().GetString() << std::endl;
	}
}

bool World::load_city_distances(MyList<MyList<MyString>> data)
{
	for (auto r = 1; r < data.get_size(); r++)
	{
		cities_[r - 1].distances = MyList<Distance>(data[0].get_size());
		for (auto c = 0; c < data[r].get_size(); c++)
		{
			cities_[r - 1].distances[c] = Distance(data[0][c], data[r][c].Parse());
			std::cout << cities_[r - 1].distances[c].get_name().GetString() << std::endl;
			std::cout << cities_[r - 1].distances[c].get_distance() << std::endl;
		}
	}
	return true;
}

void World::load_items(MyList<MyString>& items)
{
	if (cities_.get_size() == 0) {
		std::cout << "there are no cities" << std::endl;
	}
	else {
		for (auto c = 0; c < cities_.get_size(); c++) {
			cities_[c].items = MyList<ItemStock>(items.get_size() - 1);
			for (auto i = 0; i < items.get_size() - 1; i++)
			{
				cities_[c].items[i] = ItemStock(Item(items[i + 1]));
				std::cout << cities_[c].items[i].get_item().get_name().GetString() << std::endl;
			}
		}
	}
}

bool World::load_item_amount(MyList<MyList<MyString>> data)
{
	for (auto r = 0; r < data.get_size() - 1; r++)
	{
		for (auto c = 0; c < data[r].get_size() - 1; c++)
		{
			auto index = data[r + 1][c + 1].get_occurrence_index('-');
			if (index.get_size() != 1)
			{
				std::cout << "no - sign found" << std::endl;
				return false;
			}
			auto k = data[r + 1][c + 1];
			const auto min = data[r + 1][c + 1].subset(0, index[0]).Parse();
			const auto max = data[r + 1][c + 1].subset(index[0] + 1, data[r + 1][c + 1].GetLength()).Parse();
			cities_[r].items[c].set_quantities(min, max);
			std::cout << cities_[r].items[c].get_min_quantities() << std::endl;
			std::cout << cities_[r].items[c].get_max_quantities() << std::endl;
		}
	}
	return true;
}

bool World::load_item_price(MyList<MyList<MyString>> data)
{
	for (auto r = 0; r < data.get_size() - 1; r++)
	{
		for (auto c = 0; c < data[r].get_size() - 1; c++)
		{
			auto index = data[r + 1][c + 1].get_occurrence_index('-');
			if (index.get_size() != 1)
			{
				std::cout << "no - sign found" << std::endl;
				return false;
			}
			auto k = data[r + 1][c + 1];
			const auto min = data[r + 1][c + 1].subset(0, index[0]).Parse();
			const auto max = data[r + 1][c + 1].subset(index[0] + 1, data[r + 1][c + 1].GetLength()).Parse();
			cities_[r].items[c].set_prices(min, max);
			std::cout << cities_[r].items[c].get_min_price() << std::endl;
			std::cout << cities_[r].items[c].get_max_price() << std::endl;
		}
	}
	return true;
}

void World::load_ships(MyList<MyList<MyString>> data)
{
	ships_ = MyList<Ship>(data.get_size());
	for (auto r = 1; r < data.get_size(); r++)
	{
		ships_[r - 1] = Ship(
			data[r][0],
			data[r][1].Parse(),
			data[r][2].Parse(),
			data[r][3].Parse(),
			data[r][4].Parse(),
			data[r][5]
		);
		std::cout << ships_[r - 1].get_type().GetString() << std::endl;
	}
}

void World::load_item_ships()
{
	for (auto s = 0; s < ships_.get_size(); s++) {
		ships_[s].storage = MyList<Item>(cities_[0].items.get_size());
		for (auto i = 0; i < cities_[0].items.get_size(); i++)
		{
			ships_[s].storage[i] = cities_[0].items[i].get_item();
			std::cout << ships_[s].storage[i].get_name().GetString() << std::endl;
		}
	}
}

bool World::read()
{
	//check if files are loaded
	File city_distance;
	const auto d = city_distance.init(".\\Files\\afstanden tussen steden.csv");
	File item_amount;
	const auto a = item_amount.init(".\\Files\\goederen hoeveelheid.csv");
	File item_price;
	const auto p = item_price.init(".\\Files\\goederen prijzen.csv");
	File ships;
	const auto s = ships.init(".\\Files\\schepen.csv");
	if (!d || !a || !p || !s)
	{
		std::cout << "not all files could be read" << std::endl;
		return false;
	}

	//checks amount cities are correct; 
	const auto check1 = city_distance.file[0].get_size() == city_distance.file.get_size();
	const auto check2 = city_distance.file.get_size() == item_amount.file.get_size() && city_distance.file.get_size() == item_price.file.get_size();

	//check amount items are correct;
	const auto check3 = item_amount.file[0].get_size() == item_price.file[0].get_size();

	//check if all parameters are available in file ships
	const auto check4 = ships.file[0].get_size() == 6;

	if (check1 && check2 && check3 && check4) {
		load_ships(ships.file);

		load_cities(city_distance.file[0]);
		load_city_distances(city_distance.file);
		load_items(item_amount.file[0]);


		load_item_ships();

		load_item_amount(item_amount.file);
		load_item_price(item_price.file);

	}
	else
	{
		std::cout << "files do not follow same format" << std::endl;
		return false;
	}
	return true;
}
