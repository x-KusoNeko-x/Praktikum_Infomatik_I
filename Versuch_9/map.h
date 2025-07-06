#ifndef MAP_H
#define MAP_H

#include <QVector>
#include <QGraphicsScene>

#include "city.h"
#include "street.h"
#include "abstractmap.h"

class Map : public AbstractMap
{
public:
    Map();
    void addCity(City* city) override;
    void addStreet(Street* street) override;
    City* findCity(const QString cityName) const override;
    QVector<Street*> getStreetList(const City* city) const override;
    City* getOppositeCity(const Street* street, const City* city) const override;
    double getLength(const Street* street) const override;

    void draw(QGraphicsScene* scene);

private:
    QVector<City*> cityList;
    QVector<Street*> streetList;
};

#endif // MAP_H
