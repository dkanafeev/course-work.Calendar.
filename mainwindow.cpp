#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //pToolBar = new ToolBar(this);
    pSettingAction = new QAction (tr("Настройки"), this);
    pHelpAction = new QAction (tr("Помощь"), this);
    settingDialog = NULL;
    helpDialog = NULL;
    hollidayDialog = NULL;

    ui->mainToolBar->addAction(pSettingAction);
    ui->mainToolBar->addAction(pHelpAction);
    ui->mainToolBar->setMovable(false);

     //connect(ui->calendarWidget, SIGNAL(clicked(QDate)), this, SLOT(dateProcessing(QDate)));

    connect(pSettingAction, SIGNAL(triggered()), this, SLOT(createSettingDialog()));

    connect(pHelpAction, SIGNAL(triggered()), this , SLOT(createHelpDialog()));

    connect(this->ui->addHolidayButton, SIGNAL(clicked()), this, SLOT(createAddDataDialog()));
    connect(this->ui->editHolidayButton, SIGNAL(clicked()), this, SLOT(createAddDataDialog()));
    connect(this->ui->choiceListHolidayDate, SIGNAL(activated(int)), this, SLOT(on_choiceListHolidayDate_activated(int)));

}


MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::dateProcessing(const QDate & date)
//{
//    qDebug() << date;

//}


/// метод описывающий открытие окно SettingDialog

void MainWindow::createSettingDialog()
{

    if (settingDialog == NULL)
       settingDialog = new SettingDialog();
    settingDialog->show();
}


/// метод описывающий открытие окно HelpDialog

void MainWindow::createHelpDialog()
{

    if (helpDialog == NULL)
        helpDialog = new HelpDialog();
    helpDialog->show();
}


 ///метод описывающий открытие окно AddDataDialog

void MainWindow ::createAddDataDialog()
{
    if (hollidayDialog != NULL)
        delete hollidayDialog;
    hollidayDialog = new AddDataDialog();
    hollidayDialog->show();
}




void MainWindow::on_choiceListHolidayDate_activated(const int &arg1)
{
    int mode = (arg1 == 0) ? DBManager::QUERY_SELECT_FROM_DATA_BY_BIRTH_MONTH
                           : DBManager::QUERY_SELECT_FROM_DATA ;
    ui->displayingComingHolidaysWidget->setModel(DBManager::getInstance()->selectQuery(mode));
}

void MainWindow::changeEvent(QEvent *apcEvt)
{
    if(apcEvt->type()== QEvent::LanguageChange)
    {
        pSettingAction->setText(tr("Настройки"));
        pHelpAction->setText(tr("Помощь"));
    }
}
