#include "helpdialog.h"
#include "ui_helpdialog.h"

HelpDialog::HelpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpDialog)
{
    ui->setupUi(this);

    connect(this->ui->okCloseHelpDialogButton, SIGNAL(clicked()), this, SLOT(okCloseHelpDialogButton()));
}


HelpDialog::~HelpDialog()
{
    delete ui;
}

void HelpDialog::okCloseHelpDialogButton()
{
    close();
}
