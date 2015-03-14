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
}

TextCongratulationDialog::~TextCongratulationDialog()
{
    delete ui;
}
