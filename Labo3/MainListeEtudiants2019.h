#ifndef MAINLISTEETUDIANTS2019_H
#define MAINLISTEETUDIANTS2019_H

#include <QMainWindow>

namespace Ui {
class MainListeEtudiants2019;
}

class MainListeEtudiants2019 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainListeEtudiants2019(QWidget *parent = 0);
    ~MainListeEtudiants2019();

private slots:
    void on_ButtonOk_clicked();
    void on_ButtonEffacer_clicked();
    void on_ButtonTerminer_clicked();
    
    void setGroupe1(const char *);
	 const char* getGroupe1() const;
	 void setGroupe2(const char *);
	 const char* getGroupe2() const;
	 void setGroupe3(const char *);
	 const char* getGroupe3() const;
	 void setNbEtud1(int);
	 void setNbEtud2(int);
	 void setNbEtud3(int);
private:
    Ui::MainListeEtudiants2019 *ui;
};

#endif // MAINLISTEETUDIANTS2019_H
