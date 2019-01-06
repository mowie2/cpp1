#include "pch.h"
#include "City.h"
#include "Player.h"

City::City(const MyString& name,const MyList<Ship>& shipList)
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
	if (system(NULL))
	{
		system("CLS");
	}

	int cmd;
	while(true)
	{
		std::cout << "Which ship would you like to buy?\n";
		for (auto i = 1; i < shipFactory_.shipList.get_size(); i++)
		{
			MyString shipName = shipFactory_.shipList[i-1].get_type();
			std::cout << "====================================\n";
			std::cout << "\t\t"<< i << "\n";
			std::cout << "Name: " << shipName.GetString() << "\n";
			std::cout << "Price: " << shipFactory_.shipList[i - 1].get_price() <<"\n";
			std::cout << "Health: " << shipFactory_.shipList[i - 1].get_hp() <<"\n";
			std::cout << "Cannon slots: " << shipFactory_.shipList[i - 1].get_max_canons()<<"\n";
			std::cout << "Cargo space: " << shipFactory_.shipList[i - 1].get_max_items() <<"\n";
			std::cout << "misc: " << shipFactory_.shipList[i - 1].get_misc().GetString() <<"\n";
		}
		std::cin >> cmd;
		if(system( NULL))
		{
			system("CLS");			
		}
		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		if (cmd < 1 || cmd > 13)
		{
			std::cout << "Please select a valid option\n";
			continue;
		}
		break;
	}

	switch (cmd)
	{
	case 1:
		p.playerShip = shipFactory_.getPinnace();
		break;
	case 2:
		p.playerShip = shipFactory_.getSloep();
		break;
	case 3:
		p.playerShip = shipFactory_.getBrigg();
		break;
	case 4:
		p.playerShip = shipFactory_.getBarque();
		break;
	case 5:
		p.playerShip = shipFactory_.getKorvet();
		break;
	case 6:
		p.playerShip = shipFactory_.getFluyt();
		break;
	case 7:
		p.playerShip = shipFactory_.getFregat();
		break;
	case 8:
		p.playerShip = shipFactory_.getGaljoen();
		break;
	case 9:
		p.playerShip = shipFactory_.getHandelsFluyt();
		break;
	case 10:
		p.playerShip = shipFactory_.getCaravel();
		break;
	case 11:
		p.playerShip = shipFactory_.getCaravel();
		break;
	case 12:
		p.playerShip = shipFactory_.getOorlogsGaljoen();
		break;
	case 13:
		p.playerShip = shipFactory_.getShipOfTheLine();
		break;
	}
	
}
