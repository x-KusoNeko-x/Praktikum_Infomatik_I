#ifndef CITY_H
#define CITY_H

#include <QString>
#include <QGraphicsScene>

class City
{
public:
    City(QString name, int x, int y, QString type);
    void draw(QGraphicsScene* scene);
    QString getname();
    int getX();
    int getY();
    QString gettypt();

private:
    QString name;
    int x;
    int y;
    QString type;
};

#endif // CITY_H
