#include "adddatadialog.h"
#include "ui_adddatadialog.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQuery>


/**
 * @class AddDataDialog
 * @brief В данном классе реализуется окно «добавить/редактировать данные»
 *
 */

AddDataDialog::AddDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDataDialog)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../calendarKursovaya/DB.db");

    chooseButton = NULL;

    ///@brief обработка нажатия на кнопку "chooseButton" и открытие окна"TextCongratulationDialog"
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

    if (!db.open())
    {
       QMessageBox::information(this, "title", "wrong");
    }

    QSqlQuery query;\
    QDateTime dateTime = QDateTime::currentDateTime();

    query.prepare("INSERT INTO Data ( lastName, firstName, patronimicName, email  )"
                         "VALUES(?, ?, ?, ?)");
    query.addBindValue( ui->lastNameField->text());
    query.addBindValue(ui->firstNameField->text());
    query.addBindValue(ui->patronimicNameField->text());
    query.addBindValue(ui->emailFieldSender->text());
    //query.addBindValue(ui->dateEdit->setDate(dateTime.date()));
    query.exec();


    close();
}

void AddDataDialog::choiceListReminder(int index)
{

}

void AddDataDialog::choiceListHoursReminder(const QTime&time)
{

}

void AddDataDialog::choiceListYear()
{

}
