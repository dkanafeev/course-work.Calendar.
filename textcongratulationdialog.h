#ifndef TEXTCONGRATULATIONDIALOG_H
#define TEXTCONGRATULATIONDIALOG_H

#include <QDialog>

namespace Ui {
class TextCongratulationDialog;
}

class TextCongratulationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TextCongratulationDialog(QWidget *parent = 0);
    ~TextCongratulationDialog();

private slots:
    void okSaveTextCongratulation();

    void cancelCloseTextCongratulation();

private:
    Ui::TextCongratulationDialog *ui;
};

#endif // TEXTCONGRATULATIONDIALOG_H
