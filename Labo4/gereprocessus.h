#ifndef GEREPROCESSUS_H
#define GEREPROCESSUS_H

#include <QMainWindow>

namespace Ui {
class GereProcessus;
}

class GereProcessus : public QMainWindow
{
    Q_OBJECT

public:
    explicit GereProcessus(QWidget *parent = 0);
    ~GereProcessus();
    void setNomGroupe1(const char*);
    const char* getNomGroupe1() const;
    void setNomGroupe2(const char*);
    const char* getNomGroupe2() const;
    void setNomGroupe3(const char*);
    const char* getNomGroupe3() const;
    void 	setNbEtud1(int);
    void 	setNbEtud2(int);
    void 	setNbEtud3(int);

private slots:
    void on_ButtonTerminer1_clicked();
    void on_ButtonTerminer2_clicked();
    void on_ButtonTerminer3_clicked();
    void on_ButtonGo_clicked();
    void on_ButtonEffacer_clicked();
    void on_ButtonTerminer_clicked();

private:
    Ui::GereProcessus *ui;
};

#endif // GEREPROCESSUS_H
