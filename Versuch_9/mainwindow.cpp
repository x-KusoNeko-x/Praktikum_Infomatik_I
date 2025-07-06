#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "city.h"
#include "map.h"
#include "street.h"
#include "addcitydialog.h"
#include "addstreetdialog.h"
#include "mapionrw.h"
#include "dijkstra.h"

#include <QRandomGenerator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    mapio = new MapIoNrw;
}

MainWindow::~MainWindow()
{
    delete ui;
}

Map map1;

void MainWindow::on_pushButton_teste_clicked()
{
    //button click
    qDebug() << "button clicked";

    // eingabe transfomation
    QString eingabe = ui->lineEdit_teste->text();
    QString ausgabe = QString("Eingebe ist: %1").arg(eingabe);
    qDebug() << ausgabe;

    //eingabe typecasting
    bool ifZahl;
    int zahl = ui->lineEdit_teste->text().toInt(&ifZahl);

    if(ifZahl){
        int ergebniss = zahl*4;
        qDebug() << "ergebniss ist: " << ergebniss;
    }else{
        qDebug() << "eingabe ist kein zahl!";
    }

    //random rechteck
    int a = QRandomGenerator::global()->bounded(1000);
    int b = QRandomGenerator::global()->bounded(1000);
    int c = QRandomGenerator::global()->bounded(1000);
    int d = QRandomGenerator::global()->bounded(1000);

    scene->addRect(a,b,c,d,QPen(Qt::black));
}


void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_actionClear_Scene_triggered()
{
    scene->clear();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this,"About","Das ist ein Strassenplanner");
}



void MainWindow::on_pushButton_drawCityTest_clicked()
{
    City city1("Aachen",100,100,"SmallTown");
    City city2("Koehl",300,100,"BigCity");

    city1.draw(scene);
    city2.draw(scene);
}


void MainWindow::on_pushButton_drawMapTest_clicked()
{
    City* city1 = new City("Aachen",100,100,"SmallTown");
    City* city2 = new City("Koehl",300,100,"BigCity");

    Map map1;
    Street* street1 = new Street(city1,city2);

    map1.addCity(city1);
    map1.addCity(city2);
    map1.addStreet(street1);

    map1.draw(scene);
}


void MainWindow::on_pushButton_testDrawStreet_clicked()
{
    City* city1 = new City("Aachen",100,100,"SmallTown");
    City* city2 = new City("Koehl",300,100,"BigCity");

    Street street1(city1,city2);

    city1->draw(scene);
    city2->draw(scene);
    street1.draw(scene);
}


void MainWindow::on_pushButton_testAddStreet_clicked()
{
    City* city1 = new City("Aachen",100,100,"SmallTown");
    City* city2 = new City("Koehl",300,100,"BigCity");

    Map map1;
    Street* street1 = new Street(city1,city2);

    map1.addCity(city1);
    map1.addCity(city2);
    map1.addStreet(street1);

    map1.draw(scene);
}


void MainWindow::on_checkBox_hideTests_clicked(bool checked)
{
    ui->pushButton_drawCityTest->setVisible(!checked);
    ui->pushButton_testDrawStreet->setVisible(!checked);
    ui->pushButton_drawMapTest->setVisible(!checked);
    ui->pushButton_testAddStreet->setVisible(!checked);
    ui->pushButton_teste->setVisible(!checked);
    ui->pushButton_testAbsrMap->setVisible(!checked);
    ui->lineEdit_testDijAnfang->setVisible(!checked);
    ui->lineEdit_testDijZiel->setVisible(!checked);
    ui->pushButton_testDij->setVisible(!checked);
}


void MainWindow::on_pushButton_addCity_clicked()
{
    bool acc = false;

    while(!acc){
        AddCityDialog dialog(this);
        City* newCity = dialog.getCity();

        if(dialog.exec() == QDialog::Accepted){
            acc = dialog.addCityCorr();
            if(acc){
                map1.addCity(newCity);
                map1.draw(scene);
            }else{
                QMessageBox::warning(nullptr,"Fehler","Falsche Eingabe!!!");
            }
        }else{
            break;
        }
    }
}


void MainWindow::on_pushButton_fillMap_clicked()
{

    mapio->fillMap(map1);

    map1.draw(scene);
}


void MainWindow::on_pushButton_testAbsrMap_clicked()
{
    Map testMap;
    City *a = new City("a", 0, 0,"");
    City *b = new City("b", 0, 100,"");
    City *c = new City("c", 100, 300,"");
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = true;
        testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = true;
        testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = testMap.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}


void MainWindow::on_pushButton_testDij_clicked()
{

    QString dijcityAnfangName = ui->lineEdit_testDijAnfang->text();
    QString dijcityZielName = ui->lineEdit_testDijZiel->text();

    City* dijcityAnfang = map1.findCity(dijcityAnfangName);
    City* dijcityZiel = map1.findCity(dijcityZielName);

    QVector<Street*> dijStreetList = Dijkstra::search(map1,dijcityAnfangName,dijcityZielName);

    for(Street* street : dijStreetList){
        street->drawRed(scene);
    }
}


void MainWindow::on_pushButton_addStrDialg_clicked()
{
    AddStreetDialog dialog(this);
    bool corr = false;

    while(!corr){
        if(dialog.exec() == QDialog::Accepted){
            Street* newStreet = dialog.getStreet(map1);

            corr = dialog.addStrCorr(map1);

            if(corr){
                map1.addStreet(newStreet);
                map1.draw(scene);
            }else{
                QMessageBox::warning(nullptr,"Fehler","Falsche Eingabe!!!");
            }
        }else{
            break;
        }
    }
}

