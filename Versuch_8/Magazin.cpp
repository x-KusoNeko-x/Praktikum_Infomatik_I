#include "Magazin.h"

#include <string>
#include <iostream>

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte)
	:Medium(initTitel),
	datumAusgabe(initDatumAusgabe),
	sparte(initSparte)
{
	
}

Magazin::~Magazin(void)
{
}

void Magazin::ausgabe() const {
	std::cout << "ID: " << ID << std::endl
		<< "Titel: " << titel << std::endl
		<< "AusgabeDatum: " << datumAusgabe << std::endl
		<< "Sparte: " << sparte << std::endl;
	if (status)
	{
		std::cout << "Status : Das Medium ist seit dem " << datumAusgeliehen << " an " << personAusgeliehen.getName() << " ausgeliehen." << std::endl;
	}
	else
	{
		std::cout << "Status: Medium ist zurzeit nicht verliehen." << std::endl;
	}
}