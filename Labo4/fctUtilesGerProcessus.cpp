void GereProcessus::setNomGroupe1(const char *Buffer)
{
if (Buffer == NULL || strlen(Buffer) == 0 ) 
   { 
   ui->lineNomGroupe1->clear();
   return;
   }
ui->lineNomGroupe1->setText(Buffer);
}

const char* GereProcessus::getNomGroupe1() const
{
static char	Buffer[8];

if (ui->lineNomGroupe1->text().size())
	{ 
	strcpy(Buffer,ui->lineNomGroupe1->text().toStdString().c_str());
	return Buffer;
	}
return NULL;
}

void GereProcessus::setNomGroupe2(const char *Buffer)
{
if (Buffer == NULL || strlen(Buffer) == 0 ) 
   { 
   ui->lineNomGroupe2->clear();
   return;
   }
ui->lineNomGroupe2->setText(Buffer);
}

const char* GereProcessus::getNomGroupe2() const
{
static char	Buffer[8];

if (ui->lineNomGroupe2->text().size())
	{ 
	strcpy(Buffer,ui->lineNomGroupe2->text().toStdString().c_str());
	return Buffer;
	}
return NULL;
}
void GereProcessus::setNomGroupe3(const char *Buffer)
{
if (Buffer == NULL || strlen(Buffer) == 0 ) 
   { 
   ui->lineNomGroupe3->clear();
   return;
   }
ui->lineNomGroupe3->setText(Buffer);
}

const char* GereProcessus::getNomGroupe3() const
{
static char	Buffer[8];

if (ui->lineNomGroupe3->text().size())
	{ 
	strcpy(Buffer,ui->lineNomGroupe3->text().toStdString().c_str());
	return Buffer;
	}
return NULL;
}

void GereProcessus::setNbEtud1(int Nb)
{
char	Buffer[20];
if (Nb >= 0)
	{ sprintf(Buffer,"%d",Nb);
     ui->lineNbEtud1->setText(Buffer);
     return;
	}
ui->lineNbEtud1->clear();
}

void GereProcessus::setNbEtud2(int Nb)
{
char	Buffer[20];
if (Nb >= 0)
	{ sprintf(Buffer,"%d",Nb);
     ui->lineNbEtud2->setText(Buffer);
     return;
	}
ui->lineNbEtud2->clear();
}

void GereProcessus::setNbEtud3(int Nb)
{
char	Buffer[20];
if (Nb >= 0)
	{ sprintf(Buffer,"%d",Nb);
     ui->lineNbEtud3->setText(Buffer);
     return;
	}
ui->lineNbEtud3->clear();
}


