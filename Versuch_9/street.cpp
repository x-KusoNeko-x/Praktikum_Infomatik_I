#include "street.h"

Street::Street(City* anfang,City* end) : city1(anfang), city2(end) {}

void Street::draw(QGraphicsScene* scene){
    QPen pen(Qt::blue);
    pen.setWidth(5);
    scene->addLine(city1->getX(),city1->getY()+2,city2->getX(),city2->getY()+2,pen);
}

City* Street::getcity1() const{
    return city1;
}

City* Street::getcity2() const{
    return city2;
}

void Street::drawRed(QGraphicsScene* scene){
    QPen pen(Qt::red);
    pen.setWidth(6);
    scene->addLine(city1->getX(),city1->getY(),city2->getX(),city2->getY(),pen);
}
