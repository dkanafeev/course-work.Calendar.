#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>

namespace Ui {
class HelpDialog;
}

/**
 * @class HelpDialog
 * @brief The HelpDialog class
 * В данном классе реализуется окно «Помощь»
 */
class HelpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HelpDialog(QWidget *parent = 0);
    ~HelpDialog();

private slots:
    void okCloseHelpDialogButton();

private:
    Ui::HelpDialog *ui;
};

#endif // HELPDIALOG_H
