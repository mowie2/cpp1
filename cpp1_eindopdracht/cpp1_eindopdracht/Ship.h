#pragma once
#include "MyString.h"
#include "Item.h"
#include "Canon.h"

class  Ship
{
public:
	Ship() = default;
	Ship(const MyString & type, const int price, const int capacity, const int max_canons, const int hp, const MyString& misc);
	~Ship() = default;

	MyString get_type() const;
	int get_price() const;
	int get_max_items() const;
	int get_max_canons() const;
	int get_hp() const;
	int get_max_hp() const;
	void addhp(int hp);
	MyString get_misc() const;
	void takeDamage(const int damageAmount);
	MyList<Item> storage;

	Canon getLightCanons()const;
	Canon getMidCanons()const;
	Canon getHeavyCanons()const;
	void addLightCannons(int c) { light_.add(c); }
	void addMediumCannons(int c) { mid_.add(c); }
	void addHeavyCannons(int c) { heavy_.add(c); }

	void removeLightCannons(int c) { light_.remove(c); }
	void removeMediumCannons(int c) { mid_.remove(c); }
	void removeHeavyCannons(int c) { heavy_.remove(c); }

	int calculateFleeChance(const Ship& other) const;
	int calculateDamage() const;
	void empty();
	Canon light_;
	Canon mid_;
	Canon heavy_;
	MyString shipName_;
	int price_ = 0;
	int max_items_ = 0;
	int max_canons_ = 0;
	int max_hp_ = 0;
	int hp_ = 0;
	MyString characteristics_;
};
