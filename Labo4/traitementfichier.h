#ifndef TRAITEMENTFICHIER_H
#define TRAITEMENTFICHIER_H

#include <QMainWindow>

namespace Ui {
class TraitementFichier;
}

class TraitementFichier : public QMainWindow
{
    Q_OBJECT

public:
    explicit TraitementFichier(QWidget *parent = 0);
    ~TraitementFichier();
    void AffTraitementEnCours(const char*);
    void AffNumeroTraitement(int );

private:
    Ui::TraitementFichier *ui;
};

#endif // TRAITEMENTFICHIER_H
