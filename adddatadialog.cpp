#include "adddatadialog.h"
#include "ui_adddatadialog.h"

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

    chooseButton = NULL;

    ///@brief обработка нажатия на кнопку "chooseButton" и открытие окна"TextCongratulationDialog"
    connect(this->ui->chooseButton, SIGNAL(clicked()), this, SLOT(createTextCongratulationDialog()) );
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
