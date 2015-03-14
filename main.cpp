#include "mainwindow.h"
#include <QApplication>

/**
 * @class main
 * @brief класс main
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
