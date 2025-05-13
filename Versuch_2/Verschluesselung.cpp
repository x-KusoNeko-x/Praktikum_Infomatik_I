///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>

/**
 * @brief nach klartext fragen und klartext verschluesseln
 * 
 * @param laenge laenge von klartext
 * @param n index in klartext
 * @param m index in lookup-table
 * 
 * @return verschluesselte geheimtext
 */
string verschluesseln(char schluessel[2][26], string wort)
{
	// Hier folgt Ihr Code
	std::cout << "klartext ist?" << std::endl;
	std::cin >> wort;
	std::cout << "Klartext ist:   " << wort << std::endl;

	int laenge = (int)size(wort);
	int n = 0;
	int m = 0;
	int i = 0;

	for (i = 0; i < laenge; i++)
	{
		if (wort[n] == schluessel[0][m])
		{
			wort[n] = schluessel[1][m];
			n++;
			m = 0;
		}
		else
		{
			m++; 
			i--;
		}
		
	}

	return wort;
}

/**
 * @brief geheimtext wieder entschluesseln
 * 
 * @param laenge laenge von geheinmtext
 * @param m
 * @param n
 * 
 * @return rekonstruntuirtes kalrtext
 */
string entschluesseln(char schluessel[2][26], string wort)
{
	// Hier folgt Ihr Code
	int laenge = (int)size(wort);
	int n = 0;
	int m = 0;
	int i = 0;

	for (i = 0; i < laenge; i++)
	{
		if (wort[n] == schluessel[1][m])
		{
			wort[n] = schluessel[0][m];
			n++;
			m = 0;
		}
		else
		{
			m++; 
			i--;
		}
		
	}

	return wort;
}

int main()
{
	// Hier folgt Ihr Code
	char lookUpTable[2][26];
	
	for (int i = 0; i < 26; i++)
	{
		lookUpTable[0][i] = 'A' + i;
		// std::cout << lookUpTable[0][i] << " ";
	}

	std::cout << std::endl;

	std::string lookUpTable2 = "QWERTYUIOPASDFGHJKLZXCVBNM";

	for (int i = 0; i < 26; i++)
	{
		lookUpTable[1][i] = lookUpTable2[i];
		// std::cout << lookUpTable[1][i] << " ";
	}

	 std::string klarText;
	 
	std::string geheimText = verschluesseln(lookUpTable,klarText);
	std::cout << "Geheimtext ist: " << geheimText << std::endl;

	std::string klarTextRE = entschluesseln(lookUpTable,geheimText);
	std::cout << "KlartextRE ist: " << klarTextRE << std::endl;
	

	return 0;
}
