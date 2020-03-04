void FenetreClient::setMessageRecu(const char* Text)
{
if (strlen(Text) == 0 ) 
   { 
   ui->lineMessageRecu->clear();
   return;
   }
ui->lineMessageRecu->setText(Text);
return;
}

void FenetreClient::setMessageEmettre(const char* Text)
{
if (strlen(Text) == 0 ) 
   { 
   ui->lineMessageEmettre->clear();
   return;
   }
ui->lineMessageEmettre->setText(Text);
return;
}

const char* FenetreClient::getMessageRecu() const
{
static		char	Nom[255];

if (ui->lineMessageRecu->text().size())
	{ 
	strcpy(Nom,ui->lineMessageRecu->text().toStdString().c_str());
	return Nom;
	}
return NULL;
}

const char* FenetreClient::getMessageEmettre() const
{
static		char	Nom[255];

if (ui->lineMessageEmettre->text().size())
	{ 
	strcpy(Nom,ui->lineMessageEmettre->text().toStdString().c_str());
	return Nom;
	}
return NULL;
}
