#include "pch.h"
#include "ShipFactory.h"

ShipFactory::ShipFactory(MyList<Ship> listOfShips)
{
	shipList = listOfShips;
}

Ship ShipFactory::getPinnace()
{
	return GetShip("Pinnace");
}

Ship ShipFactory::getSloep()
{
	return GetShip("Sloep");
}

Ship ShipFactory::getBrigg()
{
	return GetShip("Brigg");
}

Ship ShipFactory::getBarque()
{
	return GetShip("Barque");
}

Ship ShipFactory::getKorvet()
{
	return GetShip("Korvet");
}

Ship ShipFactory::getFluyt()
{
	return GetShip("Fluyt");
}

Ship ShipFactory::getFregat()
{
	return GetShip("Fregat");
}

Ship ShipFactory::getGaljoen()
{
	return GetShip("Galjoen");
}

Ship ShipFactory::getHandelsFluyt()
{
	return GetShip("Handelsfluyt");
}

Ship ShipFactory::getCaravel()
{
	return GetShip("Caraval");
}

Ship ShipFactory::getCarrack()
{
	return GetShip("Carrack");
}

Ship ShipFactory::getOorlogsGaljoen()
{
	return GetShip("Oorlogsgaljoen");
}

Ship ShipFactory::getShipOfTheLine()
{
	return GetShip("Ship of the Line");
}

Ship ShipFactory::GetShip(MyString name)
{
	for (auto i = 0; i < shipList.get_size(); i++)
	{
		Ship s = shipList[i];
		if (shipList[i].get_type().equals(name))
		{
			return shipList[i];
		}
	}

	return Ship();
}
