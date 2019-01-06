#include "pch.h"
#include "City.h"
#include "Player.h"
#include "MyRandom.h"

City::City(const MyString& name, const MyList<Ship>& shipList)
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


void City::EnterCity()
{
	MyRandom rand;
	for (int i = 0; i < items.get_size(); i++)
	{
		items[i].set_Price(rand.Range(items[i].get_min_price(), items[i].get_max_price()));
		items[i].get_item().set_quantity(rand.Range(items[i].get_min_quantities(), items[i].get_max_quantities()));
	}
}
MyString City::get_name() const
{
	return city_name_;
}

int City::get_distance_index(const MyString & city_name)
{
	for (auto c = 0; c < distances.get_size(); c++)
	{
		if (distances[c].get_name().equals(city_name))
		{
			return c;
		}
	}
	return -1;
}

int City::get_item_index(const MyString & item_name)
{
	for (auto c = 0; c < items.get_size(); c++)
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
	if (system(NULL))
	{
		system("CLS");
	}

	int cmd;
	while (true)
	{
		std::cout << "Which ship would you like to buy?\n";
		std::cout << "You have: " << p.gold << " gold to spend\n";
		for (auto i = 1; i < shipFactory_.shipList.get_size(); i++)
		{
			MyString shipName = shipFactory_.shipList[i - 1].get_type();
			std::cout << "====================================\n";
			std::cout << "\t\t[" << i << "]\n";
			std::cout << "Name: " << shipName.GetString() << "\n";
			std::cout << "Price: " << shipFactory_.shipList[i - 1].get_price() << "\n";
			std::cout << "Health: " << shipFactory_.shipList[i - 1].get_hp() << "\n";
			std::cout << "Cannon slots: " << shipFactory_.shipList[i - 1].get_max_canons() << "\n";
			std::cout << "Cargo space: " << shipFactory_.shipList[i - 1].get_max_items() << "\n";
			std::cout << "misc: " << shipFactory_.shipList[i - 1].get_misc().GetString() << "\n";
		}
		std::cout << "====================================\n";
		std::cout << "\t\t[0]\n";
		std::cout << "\t      Return\n";
		std::cin >> cmd;

		if (system(NULL))
		{
			system("CLS");
		}
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Please select a valid option\n";
			continue;
		}
		if (cmd == 0)
		{
			return;
		}
		if (cmd < 1 || cmd > 13)
		{
			std::cout << "Please select a valid option\n";
			continue;
		}
		switch (cmd)
		{
		case 1:
			if (p.gold < shipFactory_.getPinnace().get_price())
			{
				std::cout << "You do not have enough gold to buy this ship \n";
				continue;
			}
			p.playerShip = shipFactory_.getPinnace();
			break;
		case 2:
			if (p.gold < shipFactory_.getSloep().get_price())
			{
				std::cout << "You do not have enough gold to buy this ship \n";
				continue;
			}
			p.playerShip = shipFactory_.getSloep();
			break;
		case 3:
			if (p.gold < shipFactory_.getBrigg().get_price())
			{
				std::cout << "You do not have enough gold to buy this ship \n";
				continue;
			}
			p.playerShip = shipFactory_.getBrigg();
			break;
		case 4:
			if (p.gold < shipFactory_.getBarque().get_price())
			{
				std::cout << "You do not have enough gold to buy this ship \n";
				continue;
			}
			p.playerShip = shipFactory_.getBarque();
			break;
		case 5:
			if (p.gold < shipFactory_.getKorvet().get_price())
			{
				std::cout << "You do not have enough gold to buy this ship \n";
				continue;
			}
			p.playerShip = shipFactory_.getKorvet();
			break;
		case 6:
			if (p.gold < shipFactory_.getFluyt().get_price())
			{
				std::cout << "You do not have enough gold to buy this ship \n";
				continue;
			}
			p.playerShip = shipFactory_.getFluyt();
			break;
		case 7:
			if (p.gold < shipFactory_.getFregat().get_price())
			{
				std::cout << "You do not have enough gold to buy this ship \n";
				continue;
			}
			p.playerShip = shipFactory_.getFregat();
			break;
		case 8:
			if (p.gold < shipFactory_.getGaljoen().get_price())
			{
				std::cout << "You do not have enough gold to buy this ship \n";
				continue;
			}
			p.playerShip = shipFactory_.getGaljoen();
			break;
		case 9:
			if (p.gold < shipFactory_.getHandelsFluyt().get_price())
			{
				std::cout << "You do not have enough gold to buy this ship \n";
				continue;
			}
			p.playerShip = shipFactory_.getHandelsFluyt();
			break;
		case 10:
			if (p.gold < shipFactory_.getCaravel().get_price())
			{
				std::cout << "You do not have enough gold to buy this ship \n";
				continue;
			}
			p.playerShip = shipFactory_.getCaravel();
			break;
		case 11:
			if (p.gold < shipFactory_.getCarrack().get_price())
			{
				std::cout << "You do not have enough gold to buy this ship \n";
				continue;
			}
			p.playerShip = shipFactory_.getCarrack();
			break;
		case 12:
			if (p.gold < shipFactory_.getOorlogsGaljoen().get_price())
			{
				std::cout << "You do not have enough gold to buy this ship \n";
				continue;
			}
			p.playerShip = shipFactory_.getOorlogsGaljoen();
			break;
		case 13:
			if (p.gold < shipFactory_.getShipOfTheLine().get_price())
			{
				std::cout << "You do not have enough gold to buy this ship \n";
				continue;
			}
			p.playerShip = shipFactory_.getShipOfTheLine();
			break;
		}
		break;
	}
}

void City::buyItems(Player& p)
{

	if (system(NULL))
	{
		system("CLS");
	}
	int cmd;
	int itemAmount;

	while (true)
	{
		std::cout << "Which Item would you like to buy?\n";
		std::cout << "You have: " << p.gold << " gold to spend\n";
		for (auto i = 0; i < items.get_size(); i++)
		{
			MyString itemName = items[i].get_item().get_name();
			std::cout << "====================================\n";
			std::cout << "\t\t[" << i + 1 << "]\n";
			std::cout << "Name: " << itemName.GetString() << "\n";
			std::cout << "Price: " << items[i].get_Price() << "\n";
			std::cout << "Quantity: " << items[i].get_item().get_quantity() << "\n";
		}
		std::cout << "====================================\n";
		std::cout << "\t\t[0]\n";
		std::cout << "\t      Return\n";
		std::cin >> cmd;

		if (system(NULL))
		{
			system("CLS");
		}
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Please select a valid option\n";
			continue;
		}
		if (cmd == 0)
		{
			return;
		}
		if (cmd < 1 || cmd > items.get_size())
		{
			std::cout << "Please select a valid option\n";
			continue;
		}

		int currentShipItems = 0;

		for (int x = 0; x < p.playerShip.storage.get_size(); x++)
		{
			currentShipItems += p.playerShip.storage[x].get_quantity();
		}

		std::cout << "you have selected: " << items[cmd - 1].get_item().get_name().GetString() << "\n";
		std::cout << "They are: " << items[cmd - 1].get_Price() << " gold each\n";
		std::cout << "You have: " << p.gold << " gold to spend\n";
		std::cout << "You have: " << p.playerShip.get_max_items() - currentShipItems << " cargo space\n";
		std::cout << "How many would you like to buy?\n";
		std::cin >> itemAmount;

		if (system(NULL))
		{
			system("CLS");
		}
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Please select a valid option\n";
			continue;
		}
		if (itemAmount == 0)
		{
			continue;;
		}
		auto item = items[cmd - 1];

		if (items[cmd - 1].get_item().get_quantity() < itemAmount)
		{
			std::cout << "The city does not have enough of  " << item.get_item().get_name().GetString() << "\n";
			continue;
		}

		if (items[cmd - 1].get_item().get_quantity() > p.playerShip.get_max_items() - currentShipItems)
		{
			std::cout << "Your ship does not have enough cargo space! \n";
			continue;
		}
		

		if (item.get_Price()* itemAmount > p.gold)
		{
			std::cout << "You do not have enough gold to buy this amount of " << item.get_item().get_name().GetString() << "\n";
			continue;
		}

		p.playerShip.storage[cmd - 1].set_quantity(p.playerShip.storage[cmd - 1].get_quantity() + itemAmount);
		p.gold -= item.get_Price()* itemAmount;
		items[cmd - 1].get_item().set_quantity(items[cmd - 1].get_item().get_quantity() - itemAmount);
	}
}

void City::sellItems(Player& p)
{
	if (system(NULL))
	{
		system("CLS");
	}
	int cmd;
	int itemAmount;

	while (true)
	{
		std::cout << "Which Item would you like to sell?\n";
		std::cout << "You have: " << p.gold << " gold\n";
		for (auto i = 0; i < p.playerShip.storage.get_size(); i++)
		{
			MyString itemName = items[i].get_item().get_name();
			std::cout << "====================================\n";
			std::cout << "\t\t[" << i + 1 << "]\n";
			std::cout << "Name: " << itemName.GetString() << "\n";
			std::cout << "Price: " << items[i].get_Price() << "\n";
			std::cout << "Quantity: " << p.playerShip.storage[i].get_quantity() << "\n";
		}
		std::cout << "====================================\n";
		std::cout << "\t\t[0]\n";
		std::cout << "\t      Return\n";
		std::cin >> cmd;

		if (system(NULL))
		{
			system("CLS");
		}
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Please select a valid option\n";
			continue;
		}
		if (cmd == 0)
		{
			return;
		}
		if (cmd < 1 || cmd > items.get_size())
		{
			std::cout << "Please select a valid option\n";
			continue;
		}

		int currentShipItems = 0;

		for (int x = 0; x < p.playerShip.storage.get_size(); x++)
		{
			currentShipItems += p.playerShip.storage[x].get_quantity();
		}

		std::cout << "you have selected: " << items[cmd - 1].get_item().get_name().GetString() << "\n";
		std::cout << "You have: " << p.playerShip.storage[cmd -1].get_quantity() << " in your cargo space\n";
		std::cout << "How many would you like to sell?\n";
		std::cin >> itemAmount;

		if (system(NULL))
		{
			system("CLS");
		}
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Please select a valid amount\n";
			continue;
		}
		if (itemAmount == 0)
		{
			continue;;
		}
		auto item = items[cmd - 1];

		if (p.playerShip.storage[cmd - 1].get_quantity() < itemAmount)
		{
			std::cout << "You cannot sell this many " << item.get_item().get_name().GetString() << "\n";
			continue;
		}

		p.playerShip.storage[cmd - 1].set_quantity(p.playerShip.storage[cmd - 1].get_quantity() - itemAmount);
		p.gold += item.get_Price()* itemAmount;
		items[cmd - 1].get_item().set_quantity(items[cmd - 1].get_item().get_quantity() + itemAmount);
	}
}

Distance City::getDisance(const MyString & cityName) const
{
	for(int i = 0;i<distances.get_size()-1;i++)
	{
		if(distances[i].get_name() == cityName)
		{
			return distances[i];
		}
	}
	throw std::exception("city does not exist");
}
