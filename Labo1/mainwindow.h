#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	void setNom(const char* Text);
	void setMail(const char* Text);
	private slots:
	void on_ButtonPrecedent_clicked();
	void on_ButtonSuivant_clicked();
	void on_ButtonTerminer_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
