#include "Karta.h"
#include "Hra.h"
int main(int argc, char * argv[])
{
	Hra *h = new Hra();
	h->zacniHru();
	h->zapisDoSuboru("suborNaCitanie.txt");
	h->najdiKartu();

}