#ifndef ADDDATADIALOG_H
#define ADDDATADIALOG_H

#include <dbmanager.h>

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QDate>

#include "textconfiguratulatiodialog.h"

namespace Ui {
class AddDataDialog;
}

/**
 * @class AddDataDialog
 * @brief The AddDataDialog class
 */
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
    void saveCloseAddDataDialog();
    void choiceListReminder(int index);

    void choiceListHoursReminder(const QTime &time);
    void choiceListYear();
};


#endif // ADDDATADIALOG_H
