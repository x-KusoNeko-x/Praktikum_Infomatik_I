#include "addcitydialog.h"
#include "ui_addcitydialog.h"

#include<QRegularExpression>

AddCityDialog::AddCityDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddCityDialog)
{
    ui->setupUi(this);
}

AddCityDialog::~AddCityDialog()
{
    delete ui;
}

City* AddCityDialog::getCity(){
    QString name = ui->lineEdit_addCityName->text();
    int x = ui->lineEdit_addCityx->text().toInt();
    int y = ui->lineEdit_addCityy->text().toInt();
    QString type;
    if(ui->checkBox_bigCity->isChecked()){
        type = "BigCity";
    }else{
        type = "SmallTown";
    }

    City* city = new City(name,x,y,type);

    return city;
}

bool AddCityDialog::addCityCorr(){
    QString name = ui->lineEdit_addCityName->text();
    int x = ui->lineEdit_addCityx->text().toInt();
    int y = ui->lineEdit_addCityy->text().toInt();

    bool tmpCorr = true;

    if(name.contains(QRegularExpression("\\d"))){
        tmpCorr = false;
    }

    if(!x){
        tmpCorr = false;
    }

    if(!y){
        tmpCorr = false;
    }
    return tmpCorr;
}


