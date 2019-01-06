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
	currentPlayerLocation_ = "Roatan";
	player_.gold = 0 + 1;
	player_.playerShip = ships_[0];
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
			if(player_.playerHas1milGold())
			{
				std::cout << "Congratulations you have 1 million gold and won the game!!!\n";
			} else
			{
				std::cout << "Your ship has sunk\n";
			}
			return;
		}

		//TODO: logica voor de stad/shop
		

		if (currentPlayerLocation_ == AT_SEA)
		{
			DoSeaLogic();
		} 
		else
		{
			DoCityLogic();
		}
	}
}

void World::DoSeaLogic()
{
	std::cin.get();
	while (remainingDistance > 0 && !gameIsOver())
	{
		if (system(NULL))
		{
			system("CLS");
		}
		//std::cin.get();
		std::cout << "Sailing towards : " << destinationPlayer_.GetString() << "\n";
		std::cout << "Turns left : " << remainingDistance << '\n';
		std::cout << "HP left : %" << player_.playerShip.get_hp() << "\n\n";
		calculateEvent();
		
		std::cin.get();
	}
	currentPlayerLocation_ = destinationPlayer_;
}

void World::DoCityLogic()
{
	if (system(NULL))
	{
		system("CLS");
	}
	while (!gameIsOver()) {	
		std::cout << "Current city: " << currentPlayerLocation_.GetString() << "\n\n";

		std::cout << "Choose one of the following actions by entering its number" << '\n';
		std::cout << "[1] : buy stock\n";
		std::cout << "[2] : buy cannons\n";
		std::cout << "[3] : buy ship\n";
		std::cout << "[4] : sail\n";
		//std::cout << "[0] : quit game\n";

		int cmd;
		while (true)
		{
			std::cin >> cmd;

			if (std::cin.fail())
			{
				std::cout << "Please type the number of the action you would like to perform.";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			break;
		}

		switch (cmd)
		{
		case 4:
			if (SetDestination()) {
				DoSeaLogic();
				if (system(NULL))
				{
					system("CLS");
				}
			}
			break;
		default:
			std::cout << "Please type in a valid number\n";
			break;
		}
	}
}

bool World::SetDestination()
{   
	//print
	if (system(NULL))
	{
		system("CLS");
	}
	std::cout << "Current city: " << currentPlayerLocation_.GetString() << "\n\n";

	std::cout << "Action sail\n";
	std::cout << "Choose one of the following destinations by entering its number" << '\n';
	for(int i = 0;i<cities_.get_size()-1;i++)
	{
		std::cout << '[' << (i + 1) << "] : " << cities_[i].get_name().GetString() << '\n';
		//////////////////////////////
		// exception on getcitybyname
		// exception on getdistance
		try {
			std::cout << "Distance: " << cities_[getCityByName(currentPlayerLocation_)].distances[i].get_distance() << "\n";
		} catch(...)
		{
			std::cout << "error";
			return false;
		}
		//////////////////////////////
		std::cout << "====================================\n";
	}
	std::cout << "[0] : Return\n";
	std::cout << "====================================\n";

	//get command
	int cmd;
	while (true)
	{
		std::cin >> cmd;

		if (std::cin.fail())
		{
			std::cout << "Please type the number of the destination\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if(cmd == 0)
		{
			return false;
		}
		else if (cmd < 1 || cmd > cities_.get_size())
		{
			std::cout << "Please select a valid option\n";
		}
		else {
			destinationPlayer_ = cities_[cmd - 1].get_name();
			//////////////////////////////
			// exception on getcitybyname
			// exception on getdistance
			try {
				remainingDistance = cities_[getCityByName(currentPlayerLocation_)].getDisance(destinationPlayer_).get_distance();
			} catch(...)
			{
				std::cout << "error could not get distance";
				return false;
			}
			/////////////////////////////
			return true;
		}
	}
}

void World::calculateEvent()
{
	MyRandom random;
	int randomNumber = random.Range(1, 20);

	if (randomNumber == 1 || randomNumber == 2)
	{
		std::cout << "There was no wind\n";
		Geen();
	}
	if (randomNumber == 3 || randomNumber == 4)
	{
		std::cout << "There was a breeze\n";
		Briesje();
	}
	if (randomNumber >= 5 && randomNumber <= 7)
	{
		std::cout << "The wind was weak\n";
		Zwak();
	}
	if (randomNumber >= 8 && randomNumber <= 17)
	{
		std::cout << "The wind was normal\n";
		Normaal();
	}
	if (randomNumber == 18 || randomNumber == 19)
	{
		std::cout << "The wind was strong\n";
		Sterk();
	}
	if (randomNumber == 20)
	{
		std::cout << "The was a storm\n";
		Storm();
	}
	int randomPirate = random.Range(1, 100);
	if(randomPirate<=20)
	{
		DoCombatLogic();
	}
}

void World::DoCombatLogic()
{	
	std::cout << "A random pirate ship has appeared!\n\n";
	

	MyRandom rand;
	int index = rand.Range(0, ships_.get_size() - 1);
	Ship pirateShip = ships_[index];

	const auto fleeChance = player_.playerShip.calculateFleeChance(pirateShip);

	auto fighting = true;
	while (fighting) {
		std::cin.get();
		if (system(NULL))
		{
			system("CLS");
		}
		std::cout << "A random pirate ship has appeared!\n\n";
		
		std::cout << "Pirate ship :\n";
		std::cout << "type : " << pirateShip.get_type().GetString() << '\n';;
		std::cout << "hp   : " << pirateShip.get_hp() << '\n';
		std::cout << "Amount Canons :\n";
		std::cout << pirateShip.getHeavyCanons().getQuantity() << " : " << pirateShip.getHeavyCanons().getType().GetString() << '\n';
		std::cout << pirateShip.getLightCanons().getQuantity() << " : " << pirateShip.getLightCanons().getType().GetString() << '\n';
		std::cout << pirateShip.getLightCanons().getQuantity() << " : " << pirateShip.getLightCanons().getType().GetString() << '\n';
		std::cout << "====================================\n";

		std::cout << "Your ship :\n";
		std::cout << "type : " << player_.playerShip.get_type().GetString() << '\n';;
		std::cout << "hp   : " << player_.playerShip.get_hp() << '\n';
		std::cout << "Amount Canons :\n";
		std::cout << player_.playerShip.getHeavyCanons().getQuantity() << " : " << player_.playerShip.getHeavyCanons().getType().GetString() << '\n';
		std::cout << player_.playerShip.getLightCanons().getQuantity() << " : " << player_.playerShip.getLightCanons().getType().GetString() << '\n';
		std::cout << player_.playerShip.getLightCanons().getQuantity() << " : " << player_.playerShip.getLightCanons().getType().GetString() << '\n';
		std::cout << "====================================\n\n";

		std::cout << "Choose one of the following actions by entering its number" << '\n';
		std::cout << "[1] : attack\n";
		std::cout << "[2] : flee (%" << fleeChance << ")\n";
		std::cout << "[3] : give up\n";

		int cmd;
		while (true)
		{
			std::cin >> cmd;

			if (std::cin.fail())
			{
				std::cout << "Please type the number of the action you would like to perform.";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			break;
		}

		const auto damage = player_.playerShip.calculateDamage();
		const auto pirateDamage = pirateShip.calculateDamage();
		const auto flee = rand.Range(1, 100);

		switch (cmd)
		{
		case 1:
			pirateShip.takeDamage(damage);
			std::cout << "You did %" << pirateDamage << " damage to the pirates\n";
			player_.playerShip.takeDamage(pirateDamage);
			std::cout << "The pirates did %" << damage << " damage to your ship\n";
			std::cin.get();
			break;
		case 2:
			if(flee<=fleeChance)
			{
				std::cout << "You have successfully fled\n";
				fighting = false;
			}
			else
			{
				std::cout << "You could not flee\n";
				player_.playerShip.takeDamage(pirateDamage);
				std::cout << "The pirates did %" << damage << " damage to your ship\n";
			}
			std::cin.get();
			break;
		case 3:
			//todo steal cargo
			std::cout << "The pirates let you go but steal all your cargo\n";
			fighting = false;
			std::cin.get();
			break;
		default:
			std::cout << "Please type in a valid number.\n";
			break;
		}
		//player_.playerShip.takeDamage(100);
		if(pirateShip.get_hp() == 0 || player_.playerShip.get_hp() == 0)
		{
			fighting = false;
		}

		
	}
}

void World::Geen()
{
	std::cout << "The ship has not moved\n";
}
void World::Briesje()
{
	if(player_.playerShip.get_misc().contains("licht"))
	{
		Normaal();
	} else
	{
		Geen();
	}
}
void World::Zwak()
{
	if (player_.playerShip.get_misc().contains("log"))
	{
		Geen();
	}
	else
	{
		Normaal();
	}
}
void World::Normaal()
{
	std::cout << "The ship is one turn closer to its destination\n";
	remainingDistance -= 1;
}
void World::Sterk()
{
	std::cout << "The ship is two turns closer to its destination\n";
	remainingDistance -= 2;
}
void World::Storm()
{
	MyRandom random;
	const auto randomChance = random.Range(1, 100);
	if(randomChance<=40)
	{
		std::cout << "The storm had no effect\n";
		Geen();
	} else if(randomChance>40 && randomChance <=80)
	{
		std::cout << "The ship was blown out of course\n";
		remainingDistance += 1;
	}
	else
	{
		std::cout << "The ship was blown in the right course\n";
		Normaal();
	}
	const auto randomDamage = std::ceil(player_.playerShip.get_hp()*(random.Range(1, 100) / 100.0));
	std::cout << "The ship took %" << randomDamage << " damage\n";
	player_.playerShip.takeDamage(randomDamage);
}

bool World::gameIsOver()
{
	return player_.playerHas1milGold() || player_.playerHasDied() || player_.playerHasQuit();
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
		cities_[r - 1].distances = MyList<Distance>(data[0].get_size()-1);
		for (auto c = 1; c < data[r].get_size(); c++)
		{
			cities_[r - 1].distances[c - 1] = Distance(data[0][c], data[r][c].Parse());
			std::cout << cities_[r - 1].distances[c - 1].get_name().GetString() << std::endl;
			std::cout << cities_[r - 1].distances[c - 1].get_distance() << std::endl;
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
	ships_ = MyList<Ship>(data.get_size()-1);
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
