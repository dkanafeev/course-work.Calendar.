#ifndef ADDDATADIALOG_H
#define ADDDATADIALOG_H

#include <QDialog>
#include "textcongratulationdialog.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>




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
    QSqlDatabase db;
    QSqlTableModel *model;


private slots:
void createTextCongratulationDialog();
void saveCloseAddDataDialog();
void choiceListReminder(int index);

void choiceListHoursReminder(const QTime &time);
void choiceListYear();
};


#endif // ADDDATADIALOG_H
