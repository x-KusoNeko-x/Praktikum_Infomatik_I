#include "map.h"
#include <QString>
#include <cmath>

Map::Map() {}

void Map::addCity(City* city){
    cityList.push_back(city);
}

void Map::draw(QGraphicsScene* scene){
    for (Street* street : streetList){
        street->draw(scene);
    }
    for (City* city : cityList){
        city->draw(scene);
    }
}

void Map::addStreet(Street* street){
    streetList.push_back(street);
}

City* Map::findCity(const QString cityName) const{
    for (City* city : cityList){
        if(city->getname() == cityName){
            return city;
        }else{
            continue;
        }
    }
    return nullptr;
}

QVector<Street*> Map::getStreetList(const City* city) const{
    QVector<Street*> tmpStreetList;
    for(Street* street : streetList){
        if(street->getcity1() == city || street->getcity2() == city){
            tmpStreetList.push_back(street);
        }
    }
    return tmpStreetList;
}

City* Map::getOppositeCity(const Street* street, const City* city) const{
    if(street->getcity1() == city){
        return street->getcity2();
    }
    else if(street->getcity2() == city){
        return street->getcity1();
    }
    else{
        return nullptr;
    }
}

double Map::getLength(const Street* street) const{
    int c1x = street->getcity1()->getX();
    int c1y = street->getcity1()->getY();
    int c2x = street->getcity2()->getX();
    int c2y = street->getcity2()->getY();

    double tmpL = sqrt(pow((c1x-c2x),2)+pow((c1y-c2y),2));

    return tmpL;
}
