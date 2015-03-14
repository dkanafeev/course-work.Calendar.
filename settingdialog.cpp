#include "settingdialog.h"
#include "ui_settingdialog.h"

/**
 * @class SettingDialog
 * @brief В данном классе реализуется окно «Настройки», содержащее 4 вкладки: «Стили», «Языки», «Рассылка», «Уведомление»
 */

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);

}

SettingDialog::~SettingDialog()
{
    delete ui;
}
