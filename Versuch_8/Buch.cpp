#include "Buch.h"

#include <string>
#include <iostream>

Buch::Buch(std::string initTitel, std::string initAutor)
	:Medium(initTitel),
	autor(initAutor)
{ 
	
}

Buch::~Buch(void)
{
}

void Buch::ausgabe() const {
	std::cout << "ID: " << ID << std::endl
		<< "Typ: Buch" << std::endl
		<< "Titel: " << titel << std::endl
		<< "Autor: " << autor << std::endl;
	if (status)
	{
		std::cout << "Status : Das Medium ist seit dem " << datumAusgeliehen << " an " << personAusgeliehen.getName() << " ausgeliehen." << std::endl;
	}
	else
	{
		std::cout << "Status: Medium ist zurzeit nicht verliehen." << std::endl;
	}
}

bool Buch::ausleihen(Person person, Datum ausleihdatum) {
	int alterdiff = ausleihdatum - person.getGeburtsdatum();
	if (status)
	{
		std::cout << "Das Medium \"" << titel << "\" ist bereits verliehen!" << std::endl;
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