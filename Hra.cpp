#include "Hra.h"



Hra::Hra()
{
	char x = 'A';
	x--;
	for (int i = 0; i < 4; i++)
	{
		x++;
		for (int j = 1; j < 9; j++)
		{
			zoznamKariet.push_back(new Karta(j,x));
		}
	}
}


Hra::~Hra()
{
}

void Hra::zacniHru()
{
	vector <int> pole;
	for (int i = 0; i < 32; i++)
	{
		pole.push_back(i);
	}
	random_shuffle(pole.begin(), pole.end());

	for (int i = 0; i < 16; i++)
	{
		cout << zoznamKariet[pole[i]]->getCislo() << "-" << zoznamKariet[pole[i]]->getPismeno() << " : " << zoznamKariet[pole[i+16]]->getCislo() << "-" << zoznamKariet[pole[i+16]]->getPismeno() ;
		
		if (zoznamKariet[pole[i]]->getCislo() > zoznamKariet[pole[i+16]]->getCislo())
		{
			cout << " //berie Hrac1" << endl;
			kartyPrvehoHraca.push_back(zoznamKariet[pole[i]]);
			kartyPrvehoHraca.push_back(zoznamKariet[pole[i+16]]);
		}
		if (zoznamKariet[pole[i]]->getCislo() < zoznamKariet[pole[i+16]]->getCislo())
		{
			cout << " //berie Hrac2" << endl;
			kartyDruhehoHraca.push_back(zoznamKariet[pole[i]]);
			kartyDruhehoHraca.push_back(zoznamKariet[pole[i+16]]);
		}
		if (zoznamKariet[pole[i]]->getCislo() == zoznamKariet[pole[i+16]]->getCislo())
		{
			if (zoznamKariet[pole[i]]->getPismeno() < zoznamKariet[pole[i+16]]->getPismeno())
			{
				cout << " //berie Hrac1" << endl;
				kartyPrvehoHraca.push_back(zoznamKariet[pole[i]]);
				kartyPrvehoHraca.push_back(zoznamKariet[pole[i+16]]);
			}
			else
			{
				cout << " //berie Hrac2" << endl;
				kartyDruhehoHraca.push_back(zoznamKariet[pole[i]]);
				kartyDruhehoHraca.push_back(zoznamKariet[pole[i+16]]);
			}

		}

	}
	if (kartyDruhehoHraca.size() < kartyPrvehoHraca.size())
	{
		cout << "Vyhral hrac1" << endl;
	}
	if (kartyDruhehoHraca.size() > kartyPrvehoHraca.size())
	{
		cout << "Vyhral hrac2" << endl;
	}
	if (kartyDruhehoHraca.size() == kartyPrvehoHraca.size())
	{
		int pom = 0;
		for (int i = 0; i < kartyPrvehoHraca.size(); i++)
		{
			if (kartyPrvehoHraca[i]->getCislo() == 1 && kartyPrvehoHraca[i]->getPismeno() == 'A')
			{
				pom = 1;
			}
		}
		if(pom == 1)
			cout << "Vyhral hrac1" << endl;
		else
			cout << "Vyhral hrac2" << endl;

	}
}

void Hra::zapisDoSuboru(const char * menoSuboru)
{
	fstream zapisovac(menoSuboru);
	zapisovac << "Hrac1 pocet získanych kariet: " << kartyPrvehoHraca.size() << endl;
	for (int i = 0; i < kartyPrvehoHraca.size(); i++)
	{
		zapisovac << kartyPrvehoHraca[i]->getCislo() << "-" << kartyPrvehoHraca[i]->getPismeno() << endl;
	}
	zapisovac << "Hrac2 pocet získanych kariet: " << kartyDruhehoHraca.size() << endl;
	for (int i = 0; i < kartyDruhehoHraca.size(); i++)
	{
		zapisovac << kartyDruhehoHraca[i]->getCislo() << "-" << kartyDruhehoHraca[i]->getPismeno() << endl;
	}

}

void Hra::najdiKartu()
{
	int c = -1;
	char p = 'x';	
	int pom = 0;
	cin >> c >> p;
	for (int i = 0; i < kartyPrvehoHraca.size(); i++)
	{
		if (kartyPrvehoHraca[i]->getCislo() == c && kartyPrvehoHraca[i]->getPismeno() == p)
		{
			pom = 1;			
		}
	}
	if(pom == 1)
		cout << "Kartu ma hrac1" << endl;
	else
		cout << "Kartu ma hrac2" << endl;
}
