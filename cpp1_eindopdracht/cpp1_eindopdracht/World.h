#pragma once
//#include "City.h" 

class City;
class World
{	
public:
	World();
	World(const World & other) = delete;
	World(World && other) = delete;
	World& operator= (World & other) = delete;
	World& operator= (World && other) = delete;
	~World();

	void read(const char * filepath);
	int search_parameters(const char* par);
	int search_string_parameter(const char* par, const char * split);
	void load_cities(const char* par);
private:
	int count_cities_ = 0;
	City * cities_;
};

