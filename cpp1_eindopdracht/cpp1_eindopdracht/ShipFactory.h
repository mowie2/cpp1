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
	MyList<Ship> shipList;
private:
	
	Ship GetShip(MyString name);
};
