#ifndef ADDDATADIALOG_H
#define ADDDATADIALOG_H

#include <QDialog>
#include "textcongratulationdialog.h"

namespace Ui {
class AddDataDialog;
}

class AddDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDataDialog(QWidget *parent = 0);
    ~AddDataDialog();

private:
    Ui::AddDataDialog *ui;
    TextCongratulationDialog *chooseButton;


private slots:
void createTextCongratulationDialog();

};


#endif // ADDDATADIALOG_H
