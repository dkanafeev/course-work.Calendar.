#include "helpdialog.h"
#include "ui_helpdialog.h"

/**
 * @class HelpDialog
 * @brief В данном классе реализуется окно «Помощь»
 */

HelpDialog::HelpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpDialog)
{
    ui->setupUi(this);
}

HelpDialog::~HelpDialog()
{
    delete ui;
}
