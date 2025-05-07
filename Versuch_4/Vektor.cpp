//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

//Laenge rechnen
double Vektor::laenge() const
{
    double tmp_xpow = pow(x,2);
    double tmp_ypow = pow(y,2);
    double tmp_zpow = pow(z,2);

    double tmp_laenge = sqrt(tmp_xpow + tmp_ypow + tmp_zpow);

    return tmp_laenge;
}

Vektor Vektor::plus(const Vektor& input) const
{
    double tmp_x = x + input.x;
    double tmp_y = y + input.y;
    double tmp_z = z + input.z;
    Vektor plusVektor(tmp_x,tmp_y,tmp_z);
    return plusVektor;
}

Vektor Vektor::sub(const Vektor& input) const
{
    double tmp_x = x - input.x;
    double tmp_y = y - input.y;
    double tmp_z = z - input.z;
    Vektor subVektor(tmp_x,tmp_y,tmp_z);
    return subVektor;
}

double Vektor::skalarProd(const Vektor& input) const
{
    double skalarProdWert = (x*input.x) + (y*input.y) + (z*input.z);
    return skalarProdWert;
}

double Vektor::winkel(const Vektor& input) const
{
    double winkelWert;
    double tmp_skalarProd = skalarProd(input);
    double tmp_laenge = laenge();
    double tmp_laengeInput = input.laenge();
    if (tmp_skalarProd == 0)
    {
        winkelWert = M_PI/2;
    }
    else
    {
        winkelWert = acos(tmp_skalarProd / (tmp_laenge*tmp_laengeInput));
    }
    
    
    return winkelWert;
}

void Vektor::rotiereUmZ(const double rad)
{
    double tmpX = x;
    x = (cos(rad)*x) - (sin(rad)*y);
    y = (sin(rad)*tmpX) + (cos(rad)*y);
}
