void MainListeEtudiants2019::setGroupe1(const char *Buffer)
{
if (Buffer == NULL || strlen(Buffer) == 0 ) 
   { 
   ui->lineGroupe1->clear();
   return;
   }
ui->lineGroupe1->setText(Buffer);
}

const char* MainListeEtudiants2019::getGroupe1() const
{
static char		Buffer[255];

if (ui->lineGroupe1->text().size())
	{ 
	strcpy(Buffer,ui->lineGroupe1->text().toStdString().c_str());
	return Buffer;
	}
return NULL;
}

void MainListeEtudiants2019::setGroupe2(const char *Buffer)
{
if (Buffer == NULL || strlen(Buffer) == 0 ) 
   { 
   ui->lineGroupe2->clear();
   return;
   }
ui->lineGroupe2->setText(Buffer);
}

const char* MainListeEtudiants2019::getGroupe2() const
{
static char		Buffer[255];

if (ui->lineGroupe2->text().size())
	{ 
	strcpy(Buffer,ui->lineGroupe2->text().toStdString().c_str());
	return Buffer;
	}
return NULL;
}

void MainListeEtudiants2019::setGroupe3(const char *Buffer)
{
if (Buffer == NULL || strlen(Buffer) == 0 ) 
   { 
   ui->lineGroupe3->clear();
   return;
   }
ui->lineGroupe3->setText(Buffer);
}

const char* MainListeEtudiants2019::getGroupe3() const
{
static char		Buffer[255];

if (ui->lineGroupe3->text().size())
	{ 
	strcpy(Buffer,ui->lineGroupe3->text().toStdString().c_str());
	return Buffer;
	}
return NULL;
}

void MainListeEtudiants2019::setNbEtud1(int Nb)
{
Trace("Nb = %d",Nb);
char	Buffer[8];
if (Nb <0)
   { 
   ui->lineNbEtud1->clear();
   return;
   }
sprintf(Buffer,"%d",Nb);
ui->lineNbEtud1->setText(Buffer);
}

void MainListeEtudiants2019::setNbEtud2(int Nb)
{
char	Buffer[8];
if (Nb <0)
   { 
   ui->lineNbEtud2->clear();
   return;
   }
sprintf(Buffer,"%d",Nb);
ui->lineNbEtud2->setText(Buffer);
}

void MainListeEtudiants2019::setNbEtud3(int Nb)
{
char	Buffer[8];
if  (Nb <0)
	{ 
	ui->lineNbEtud3->clear();
	return;
	}
sprintf(Buffer,"%d",Nb);
ui->lineNbEtud3->setText(Buffer);
}
