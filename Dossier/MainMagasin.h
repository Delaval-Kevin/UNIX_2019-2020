#ifndef MAINMAGASIN_H
#define MAINMAGASIN_H

#include <QMainWindow>

namespace Ui {
class MainMagasin;
}

class MainMagasin : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMagasin(QWidget *parent = 0);
    ~MainMagasin();

	void setArticle1(const char*);
	void setArticle2(const char*);
	void setArticle3(const char*);
	void setArticle4(const char*);
	const char* getClient() const;
	const char* getNumCompte() const;
	void setNumCompte(const char*);
	void setClient(const char*);
	void setTextBoutonValider(const char*);
	void setTextBoutonQuitter(const char*);
	void setInfo(const char*);
	void setImage(const char*);
private slots:
    void on_ButtonPrecedent_clicked();
    void on_ButtonSuivant_clicked();
    void on_ButtonValider_clicked();
    void on_ButtonQuitter_clicked();
    void on_radioButton1_clicked();
    void on_radioButton2_clicked();
    void on_radioButton3_clicked();
    void on_radioButton4_clicked();

private:
    Ui::MainMagasin *ui;
};

#endif // MAINMAGASIN_H
