#ifndef ADDCITYDIALOG_H
#define ADDCITYDIALOG_H

#include <QDialog>

#include "city.h"

namespace Ui {
class AddCityDialog;
}

class AddCityDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCityDialog(QWidget *parent = nullptr);
    ~AddCityDialog();
    City* getCity();
    bool addCityCorr();

private:
    Ui::AddCityDialog *ui;
};

#endif // ADDCITYDIALOG_H
