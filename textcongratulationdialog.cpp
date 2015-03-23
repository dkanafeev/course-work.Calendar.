#include "textcongratulationdialog.h"
#include "ui_textcongratulationdialog.h"

/**
 * @class TextCongratulationDialog
 * @brief 	В данном классе реализуется окно «поздравление»
 */

TextCongratulationDialog::TextCongratulationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TextCongratulationDialog)
{
    ui->setupUi(this);

    connect(this->ui->okSaveCongratulationButton, SIGNAL(clicked()), this, SLOT(okSaveTextCongratulation()));
    connect(this->ui->cancelButton ,SIGNAL(clicked()), this, SLOT(cancelCloseTextCongratulation()));
}


TextCongratulationDialog::~TextCongratulationDialog()
{
    delete ui;
}

void TextCongratulationDialog::okSaveTextCongratulation()
{
    close();
}

void TextCongratulationDialog::cancelCloseTextCongratulation()
{
    close();
}
