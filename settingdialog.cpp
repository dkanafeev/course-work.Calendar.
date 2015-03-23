#include "settingdialog.h"
#include "ui_settingdialog.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQuery>



/**
 * @class SettingDialog
 * @brief В данном классе реализуется окно «Настройки», содержащее 4 вкладки: «Стили», «Языки», «Рассылка», «Уведомление»
 */

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{

    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../calendarKursovaya/DB.db");
    //ui->choiceListLanguage->addItems("Russian","English");

    //    model = new QSqlTableModel(this, db);
    //    model->setTable("Languages");
    //    model->select();
    //    ui->choiceListLanguage->setModel(model);
    //    ui->choiceListLanguage->setModelColumn(1);





    connect(this->ui->okSaveSettingButton, SIGNAL(clicked()), this, SLOT(okSaveSettingButton()));
    connect(this->ui->cancelButton, SIGNAL(clicked()), this, SLOT(cancelSettingButton()));
    connect(this->ui->applyButton, SIGNAL(clicked()), this, SLOT(applySettingButton()));
    connect(this->ui->choiceListLanguage, SIGNAL(activated(QString)), this, SLOT(on_choiceListLanguage_activated(QString)));

}

SettingDialog::~SettingDialog()
{

    delete ui;
}

void SettingDialog::okSaveSettingButton()
{
    close();
}

void SettingDialog::cancelSettingButton()
{
    close();
}


void SettingDialog::applySettingButton()
{
      close();
}

void SettingDialog::on_choiceListLanguage_activated(const QString &arg1)
{

}



