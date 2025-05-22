#include "DVD.h"

#include <string>
#include <iostream>

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre)
	:Medium(initTitel),
	altersfreigabe(initAltersfreigabe),
	genre(initGenre)
{
	
}

DVD::~DVD(void)
{
}

void DVD::ausgabe() const {
	std::cout << "ID: " << ID << std::endl
		<< "Titel: " << titel << std::endl
		<< "Altersfreigabe: " << altersfreigabe << std::endl
		<< "Genre: " << genre << std::endl;
	if (status)
	{
		std::cout << "Status : Das Medium ist seit dem " << datumAusgeliehen << " an " << personAusgeliehen.getName() << " ausgeliehen." << std::endl;
	}
	else
	{
		std::cout << "Status: Medium ist zurzeit nicht verliehen." << std::endl;
	}
}