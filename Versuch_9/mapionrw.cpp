///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#include "mapionrw.h"
#include "street.h"
#include "map.h"
#include "abstractmap.h"

MapIoNrw::MapIoNrw()
{
}

MapIoNrw::~MapIoNrw()
{
}

void MapIoNrw::fillMap(AbstractMap &map)
{
    City* aachen = new City("Aachen", -100, 100, "SmallTowm");
    City* bonn = new City("Bonn", 0,200,"SmallTown");
    City* koeln = new City("Koeln", 0,0,"BigCity");
    City* duesseldorf = new City("Duesseldorf", 50,-100,"BigCity");

    Street* aachenKoeln = new Street(aachen, koeln);
    Street* bonnKoeln = new Street(bonn, koeln);
    Street* ddorfKoeln = new Street(duesseldorf, koeln);

    map.addCity(aachen);
    map.addCity(bonn);
    map.addCity(koeln);
    map.addCity(duesseldorf);

    map.addStreet(aachenKoeln);
    map.addStreet(bonnKoeln);
    map.addStreet(ddorfKoeln);
}
