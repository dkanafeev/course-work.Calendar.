#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "adddatadialog.h"
#include "helpdialog.h"
#include "settingdialog.h"
#include "textcongratulationdialog.h"




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QAction* pSettingAction;
    QAction* pHelpAction;
    SettingDialog *settingDialog;
    HelpDialog *helpDialog;
    AddDataDialog *addHolidayButton;
    AddDataDialog *editHolidayButton;


private slots:
    //void dateProcessing(const QDate & date);
    //void test();

    void createSettingDialog();
    void createHelpDialog();
    void createAddDataDialog();

};

#endif // MAINWINDOW_H
