#include "MainListeEtudiants2019.h"
#include <QApplication>
#include <QTextCodec>
#include <stdio.h>

int main(int argc, char *argv[])
{
QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

FILE*	hfF = fopen("Trace.log","w+");
dup2(fileno(hfF),2);

QApplication a(argc, argv);
MainListeEtudiants2019 w;
w.show();

return a.exec();
}
