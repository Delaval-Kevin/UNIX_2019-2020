#ifndef DEUXIEMEDOSSIERUNIX2019_H
#define DEUXIEMEDOSSIERUNIX2019_H

#include <QMainWindow>

namespace Ui {
class MainDeuxiemeDossierUnix2019;
}

class MainDeuxiemeDossierUnix2019 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainDeuxiemeDossierUnix2019(QWidget *parent = 0);
    ~MainDeuxiemeDossierUnix2019();

private slots:
	void on_ButtonPrecedent_clicked();
	void on_ButtonSuivant_clicked();
	void on_ButtonModifier_clicked();
	void on_ButtonTerminer_clicked();
	void setNom(const char* Text);
	const char* getNom() const;
	void setAdresseMail(const char* Text);
	const char* getAdresseMail() const;
	void setAnneeNaissance(int);
	void setFichierImage(const char* Text);
	const char* getFichierImage() const;
	void setImage(const char*);
	void setTextModifier(const char*);
	bool MessageConfirmation(const char*,const char*);

private:
    Ui::MainDeuxiemeDossierUnix2019 *ui;
};

#endif // DEUXIEMEDOSSIERUNIX2019_H
