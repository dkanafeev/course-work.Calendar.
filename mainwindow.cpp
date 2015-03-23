#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../calendarKursovaya/DB.db");

    //pToolBar = new ToolBar(this);
    pSettingAction = new QAction (tr("Settings"), this);
    pHelpAction = new QAction (tr("Help"), this);
    settingDialog = NULL;
    helpDialog = NULL;
    addHolidayButton = NULL;
    editHolidayButton =NULL;


    ui->mainToolBar->addAction(pSettingAction);
    ui->mainToolBar->addAction(pHelpAction);

     //connect(ui->calendarWidget, SIGNAL(clicked(QDate)), this, SLOT(dateProcessing(QDate)));
   ///@brief обрабка нажатия на кнопку "settingDialog" и открытие окна "SettingDialog"
    connect(pSettingAction, SIGNAL(triggered()), this, SLOT(createSettingDialog()));
    ///@brief обработка нажатия на кнопку "helpDialog" и открытие окна "HelpDialog"
    connect(pHelpAction, SIGNAL(triggered()), this , SLOT(createHelpDialog()));
    ///@brief обработка нажатия на кнопки "addHolidayButton" и "editHolidayButton" и открытие окон "AddDataDialog"
    connect(this->ui->addHolidayButton, SIGNAL(clicked()), this, SLOT(createAddDataDialog()));
    connect(this->ui->editHolidayButton, SIGNAL(clicked()), this, SLOT(createAddDataDialog()));
   connect(this->ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));

}


MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::dateProcessing(const QDate & date)
//{
//    qDebug() << date;

//}

/**
 * @brief метод описывающий открытие окно SettingDialog
 */
void MainWindow::createSettingDialog()
{

    if (settingDialog == NULL)
       settingDialog = new SettingDialog();
    settingDialog->show();
}

/**
 * @brief метод описывающий открытие окно HelpDialog
 */
void MainWindow::createHelpDialog()
{

    if (helpDialog == NULL)
        helpDialog = new HelpDialog();
    helpDialog->show();
}

/**
 * @brief метод описывающий открытие окно AddDataDialog
 */
void MainWindow ::createAddDataDialog()
{
    if ((addHolidayButton == NULL) && (editHolidayButton == NULL))
        addHolidayButton = new AddDataDialog();
       // editHolidayButton = new AddDataDialog();
    addHolidayButton->show();
}




//void MainWindow::on_holidaysSelectedHolidaysWidget_activated(const QModelIndex &index)
//{

//}

//void MainWindow::on_choiceListHolidayDate_currentIndexChanged(const QString &arg1)
//{

//}

void MainWindow::on_pushButton_clicked()
{


    model = new QSqlTableModel(this, db);
    model->setTable("Data");
    model->select();
    ui->displayingComingHolidaysWidget->setModel(model);

}
