#include "gereprocessus.h"
#include "ui_gereprocessus.h"

#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <iostream>
using namespace std;
#include "Ecran.h"

void FinFils(int);
extern GereProcessus* w;

GereProcessus::GereProcessus(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GereProcessus)
{
ui->setupUi(this);
this->move(200,200);
struct sigaction Act;
Act.sa_handler = FinFils;
sigemptyset(&Act.sa_mask);
Act.sa_flags = 0;
sigaction(SIGCHLD,&Act,NULL);

}

GereProcessus::~GereProcessus()
{
    delete ui;
}
int idF1 = 0;
int idF2 = 0;
int idF3 = 0;

void GereProcessus::on_ButtonTerminer1_clicked()
{
Trace("Terminer 1");
}

void GereProcessus::on_ButtonTerminer2_clicked()
{
Trace("Terminer 2");
}

void GereProcessus::on_ButtonTerminer3_clicked()
{
Trace("Terminer 3");
     
}

void GereProcessus::on_ButtonGo_clicked()
{
Trace("Dans ButtonGo");
// ......

}

void GereProcessus::on_ButtonEffacer_clicked()
{
Trace("Dans ButtonEffacer");
setNomGroupe1("");
setNbEtud1(-1);
     
}

void GereProcessus::on_ButtonTerminer_clicked()
{
Trace("Dans ButtonTerminer");
}

void FinFils(int Sig)
{
Trace("Reception du signal %d",Sig);
// ....
return;
}

#include "fctUtilesGerProcessus.cpp"
