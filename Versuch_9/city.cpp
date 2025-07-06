#include "city.h"

#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QPen>

City::City(QString name, int x, int y, QString type) : name(name),x(x),y(y),type(type) {};

void City::draw(QGraphicsScene* scene){
    qDebug() << "Drawing: " << name;

    QBrush brush(Qt::red);
    QPen pen;
    if(type == "BigCity"){
        pen.setWidth(4);
        scene->addEllipse(x-7.5,y-7.5,20,20,pen,brush);
    }
    else{
        pen.setWidth(2);
        scene->addEllipse(x-5,y-5,10,10,pen,brush);
    }
    scene->addText(name)->setPos(x+10,y);
}

int City::getX(){
    return x;
}

int City::getY(){
    return y;
}

QString City::getname(){
    return name;
}
