#include "Karta.h"





Karta::Karta(int pcislo, char ppismeno)
{
	cislo = pcislo;
	pismeno = ppismeno;
}

Karta::~Karta()
{
}

int Karta::getCislo()
{
	return cislo;
}

char Karta::getPismeno()
{
	return pismeno;
}
