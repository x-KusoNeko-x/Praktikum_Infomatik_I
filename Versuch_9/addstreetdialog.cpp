#include "addstreetdialog.h"
#include "ui_addstreetdialog.h"

#include "map.h"

AddStreetDialog::AddStreetDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddStreetDialog)
{
    ui->setupUi(this);
}

AddStreetDialog::~AddStreetDialog()
{
    delete ui;
}

Street* AddStreetDialog::getStreet(Map map){

    QString nameS = ui->lineEdit_addStrStart->text();
    City* cityS = map.findCity(nameS);
    QString nameT = ui->lineEdit_addStrTarget->text();
    City* cityT = map.findCity(nameT);

    Street* street = new Street(cityS,cityT);

    return street;
}

bool AddStreetDialog::addStrCorr(Map map){
    bool tmpCorr = true;

    QString nameS = ui->lineEdit_addStrStart->text();
    City* cityS = map.findCity(nameS);
    QString nameT = ui->lineEdit_addStrTarget->text();
    City* cityT = map.findCity(nameT);

    if(cityS == nullptr || cityT == nullptr){
        tmpCorr = false;
    }

    return tmpCorr;
}
