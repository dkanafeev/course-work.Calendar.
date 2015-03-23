#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "adddatadialog.h"
#include "helpdialog.h"
#include "settingdialog.h"
#include "textcongratulationdialog.h"
#include <QSqlDatabase>
#include <QSqlTableModel>





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
    QSqlDatabase db;
    QSqlTableModel *model;


private slots:
    //void dateProcessing(const QDate & date);
    //void test();

    void createSettingDialog();
    void createHelpDialog();
    void createAddDataDialog();
    void on_pushButton_clicked();


//    void on_holidaysSelectedHolidaysWidget_activated(const QModelIndex &index);
//    void on_choiceListHolidayDate_currentIndexChanged(const QString &arg1);
};

#endif // MAINWINDOW_H
