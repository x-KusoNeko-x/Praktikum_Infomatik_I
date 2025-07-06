#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include "mapio.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_teste_clicked();

    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_pushButton_drawCityTest_clicked();

    void on_pushButton_drawMapTest_clicked();

    void on_pushButton_testDrawStreet_clicked();

    void on_pushButton_testAddStreet_clicked();

    void on_checkBox_hideTests_clicked(bool checked);

    void on_pushButton_addCity_clicked();

    void on_pushButton_fillMap_clicked();

    void on_pushButton_testAbsrMap_clicked();

    void on_pushButton_testDij_clicked();

    void on_pushButton_addStrDialg_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;

    MapIo *mapio;
};

#endif // MAINWINDOW_H
