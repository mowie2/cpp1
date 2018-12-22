#pragma once
#include "City.h" 


class World
{	
public:
	World();
	~World();
	void read(const char * filepath);
	int searchParameters(const char* par);
	int searchStringParameter(const char* par, const char * split);
	int load_cities(const char* par);
private:
	int count_cities = 0;
	City * cities;
};

