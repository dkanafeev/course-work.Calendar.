#include "textconfiguratulatiodialog.h"
#include "ui_textconfiguratulatiodialog.h"

TextCongratulationDialog::TextCongratulationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TextCongratulationDialog)
{
    ui->setupUi(this);
    connect(this->ui->okSaveCongratulationButton, SIGNAL(clicked()), this, SLOT(okSaveTextCongratulation()));
    connect(this->ui->cancelButton ,SIGNAL(clicked()), this, SLOT(cancelCloseTextCongratulation()));
    on_openTextCongratulationDialog();
}

void TextCongratulationDialog::changeEvent(QEvent *apcEvt)
{
    if(apcEvt->type()== QEvent::LanguageChange)
    {
        ui->congratulationGroup->setTitle(tr("Шаблон текста поздравления"));
        ui->txtChoosePattern->setText(tr("Выберете шаблон:"));
        ui->txtPattern->setText(tr("Текст выбранного шаблона:"));
        ui->cancelButton->setText(tr("Отмена"));
    }
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

void TextCongratulationDialog::on_choiceListPattern_activated(const int arg1)
{
    QString q = DBManager::getInstance()->getTextFor(arg1);
    ui->displayPattern->setText(q);
}

void TextCongratulationDialog::on_openTextCongratulationDialog()
{
    // получить модель для combobox
    ui->choiceListPattern->setModel(DBManager::getInstance()->selectQuery(DBManager::QUERY_SELECT_NAMES_FROM_CONGRATULATIONS_TEXT));
    // получить тексты
    on_choiceListPattern_activated(0);
}
