#pragma once
#include "Ship.h"

class ShipFactory
{
public:
	ShipFactory() = default;
	ShipFactory(MyList<Ship> listOfShips);
	~ShipFactory() = default;
	Ship getPinnace();
	Ship getSloep();
	Ship getBrigg();
	Ship getBarque();
	Ship getKorvet();
	Ship getFluyt();
	Ship getFregat();
	Ship getGaljoen();
	Ship getHandelsFluyt();
	Ship getCaravel();
	Ship getCarrack();
	Ship getOorlogsGaljoen();
	Ship getShipOfTheLine();
private:
	MyList<Ship> shipList;
	Ship GetShip(MyString name);
};
