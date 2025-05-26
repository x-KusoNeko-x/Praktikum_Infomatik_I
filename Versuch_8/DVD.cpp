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
		<< "Typ: DVD" << std::endl
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

bool DVD::ausleihen(Person person, Datum ausleihdatum) {
	int alterdiff = ausleihdatum - person.getGeburtsdatum();
	int monatBegrenz = altersfreigabe * 12;
	if (status)
	{
		std::cout << "Das Medium \"" << titel << "\" ist bereits verliehen!" << std::endl;
		return false;
	}
	else if (alterdiff <= monatBegrenz)
	{
		std::cout << std::endl << "Aus Grund Altersfreigabe duerfen Sie dieses DVD nicht ausleihen!" << std::endl;
		return false;
	}
	else
	{
		status = true;
		personAusgeliehen = person;
		datumAusgeliehen = ausleihdatum;
		std::cout << "Das Medium \"" << titel << "\" wird an " << person.getName() << " verliehen." << std::endl;
		return true;
	}
}