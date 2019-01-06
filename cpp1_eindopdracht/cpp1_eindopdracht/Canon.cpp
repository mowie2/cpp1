#include "pch.h"
#include "Canon.h"
#include "MyRandom.h"


Canon::Canon()
{
}

Canon::Canon(const MyString & type, const int min, const int max)
{
	type_ = type;
	min_damage_ = min;
	max_damage_ = max;
}


Canon::~Canon()
{
}

int Canon::getDamage() const
{
	MyRandom rand;
	int totalDamage = 0;
	for (int i = 0;i < quantity_;i++) {
		totalDamage += rand.Range(min_damage_, max_damage_);
	}
	return totalDamage;
}

void Canon::add(int amount)
{
	quantity_ += amount;
}

bool Canon::remove(int amount)
{
	if(amount > quantity_)
	{
		return false;
	}
	quantity_ -= amount;
	return true;
}
