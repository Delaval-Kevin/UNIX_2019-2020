#ifndef MAINMAIL_H
#define MAINMAIL_H

#include <QMainWindow>

namespace Ui {
class MainMail;
}

class MainMail : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMail(QWidget *parent = 0);
    ~MainMail();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainMail *ui;
};

#endif // MAINMAIL_H
