#ifndef ADDSTREETDIALOG_H
#define ADDSTREETDIALOG_H

#include <QDialog>

#include "street.h"
#include "map.h"

namespace Ui {
class AddStreetDialog;
}

class AddStreetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddStreetDialog(QWidget *parent = nullptr);
    ~AddStreetDialog();
    Street* getStreet(Map map);
    bool addStrCorr(Map map);

private:
    Ui::AddStreetDialog *ui;
};

#endif // ADDSTREETDIALOG_H
