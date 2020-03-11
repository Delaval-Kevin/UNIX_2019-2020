#ifndef FENETRECLIENT_H
#define FENETRECLIENT_H

#include <QMainWindow>

namespace Ui {
class FenetreClient;
}

class FenetreClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit FenetreClient(QWidget *parent = 0);
    ~FenetreClient();
    
    void setMessageRecu(const char*);
    void setMessageEmettre(const char*);
    const char* getMessageEmettre() const;
    const char* getMessageRecu() const;

private slots:
    void on_ButtonEmettre_clicked();
    void on_ButtonTerminer_clicked();

private:
    Ui::FenetreClient *ui;
};

#endif // FENETRECLIENT_H
