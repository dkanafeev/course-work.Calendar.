#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QApplication>
#include <QTranslator>
#include <QDialog>
#include <QMessageBox>

#include <dbmanager.h>
#include <iostream>

namespace Ui {
class SettingDialog;
}

/**
 * @class SettingDialog
 * @brief В данном классе реализуется окно «Настройки», содержащее 4 вкладки: «Стили», «Языки», «Рассылка», «Уведомление»
 */

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = 0);
    ~SettingDialog();

    void fillListOfEmails();
    void getCheckedEmails();

private slots:
    void okSaveSettingButton();

    void cancelSettingButton();

    void applySettingButton();

    void on_choiceListLanguage_activated(const QString choiceLanguage);

    void on_okSaveEmailButton_clicked();

    void on_tabWidget_tabBarClicked(int index);

protected:
    void changeEvent(QEvent *apcEvt);

private:
    QTranslator translator;
    Ui::SettingDialog *ui;
    QSqlDatabase db;
    QSqlTableModel *model;




};

#endif // SETTINGDIALOG_H
