#include "adddatadialog.h"
#include "ui_adddatadialog.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDate>



///В данном классе реализуется окно «добавить/редактировать данные»


AddDataDialog::AddDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDataDialog)
{
    ui->setupUi(this);

    chooseButton = NULL;

    ///@обработка нажатия на кнопку "chooseButton" и открытие окна"TextCongratulationDialog"
    connect(this->ui->chooseButton, SIGNAL(clicked()), this, SLOT(createTextCongratulationDialog()) );
    connect(this->ui->okSaveDataButton, SIGNAL(clicked()), this, SLOT(saveCloseAddDataDialog()));


}

AddDataDialog::~AddDataDialog()
{
    delete ui;
}

/**
 * @brief метод описывающий открытие окна TextCongratulationDialog
 */
void AddDataDialog::createTextCongratulationDialog()
{
    if (chooseButton == NULL)
        chooseButton = new TextCongratulationDialog();
    chooseButton->show();
}


void AddDataDialog::saveCloseAddDataDialog()
{
    QString lastName = ui->lastNameField->text();
    QString firstName = ui->firstNameField->text();
    QString patronimicName = ui->patronimicNameField->text();
    QString email = ui->emailFieldSender->text();
    QDate date = ui->dateEdit->date();
    QTime hoursReminder = ui->choiceListHoursReminder->time();
    QDate userReminderDate = ui->choiceListRemindDateUser->date();
    QTime userReminderTime = ui->choiceListRemindTimeUser->time();
    DBManager::getInstance()->addRecordToData(lastName, firstName, patronimicName, email, date, hoursReminder, userReminderDate, userReminderTime);
    ui->lastNameField->clear();
    ui->firstNameField->clear();
    ui->patronimicNameField->clear();
    ui->emailFieldSender->clear();


    close();
//    QMessageBox::information(this, "error",QString("day %1 month %2 year %3 bool %4").arg(ui->dateEdit->date().day()).arg(ui->dateEdit->date().month()).arg(ui->dateEdit->date().year()).arg(query.exec()));
}


void AddDataDialog::choiceListReminder(int index)
{

}

void AddDataDialog::choiceListHoursReminder(const QTime &time)
{

}

void AddDataDialog::choiceListYear()
{

}
