#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
class Karta
{
	int cislo;
	char pismeno;

public:
	Karta(int pcislo, char ppismeno);
	~Karta();
	int getCislo();
	char getPismeno();
};

