#pragma once
#include "Karta.h"
class Hra
{
	vector <Karta*> zoznamKariet;
	vector <Karta*> kartyPrvehoHraca;
	vector <Karta*> kartyDruhehoHraca;
public:
	Hra();
	~Hra();
	void zacniHru();
	void zapisDoSuboru(const char * menoSuboru);
	void najdiKartu();
	
};

