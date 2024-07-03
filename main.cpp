#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//   执行a.exec()，当退出时，a.exec()返回一个值  从而return
    return a.exec();
}
