#include "gereprocessus.h"
#include <QApplication>

GereProcessus* w;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w = new GereProcessus;
    w->show();

    return a.exec();
}
