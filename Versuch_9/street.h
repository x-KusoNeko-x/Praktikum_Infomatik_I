#ifndef STREET_H
#define STREET_H

#include "city.h"

#include <QGraphicsScene>

class Street
{
public:
    Street(City* anfang, City* end);
    void draw(QGraphicsScene* scene);
    void drawRed(QGraphicsScene* scene);
    City* getcity1() const;
    City* getcity2() const;

private:
    City* city1;
    City* city2;
};

#endif // STREET_H
