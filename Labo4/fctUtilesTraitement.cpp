void TraitementFichier::AffTraitementEnCours(const char* C)
{
ui->lineTraitement->setText(C);
}

void TraitementFichier::AffNumeroTraitement(int Nb)
{
char	B[10];
sprintf(B,"%d",Nb);

this->ui->lineNbTraitement->setText(B);
}


