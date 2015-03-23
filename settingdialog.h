#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>


#include <QDialog>

namespace Ui {
class SettingDialog;
}

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = 0);
    ~SettingDialog();

private slots:
    void okSaveSettingButton();

    void cancelSettingButton();

    void applySettingButton();

    void on_choiceListLanguage_activated(const QString &arg1);



private:
    Ui::SettingDialog *ui;
    QSqlDatabase db;
    QSqlTableModel *model;




};

#endif // SETTINGDIALOG_H
