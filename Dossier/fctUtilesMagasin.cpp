/***********************************************************/
/*Auteur : COLLETTE Loic et DELAVAL Kevin                  */
/*Groupe : 2203                                            */
/*Application : Dossier Unix                               */
/*Date de la dernière mise à jour : 06/12/2019             */
/***********************************************************/

void MainMagasin::setClient(const char* Text)
{
	if (Text == NULL || strlen(Text) == 0 ) 
    { 
   		ui->lineClient->clear();
   		return;
   	}
	ui->lineClient->setText(Text);
	return;
}

void MainMagasin::setNumCompte(const char* Text)
{
	if (Text == NULL || strlen(Text) == 0 ) 
 	{ 
   		ui->lineNumCompte->clear();
   		return;
   	}
	ui->lineNumCompte->setText(Text);
	return;
}
void MainMagasin::setArticle1(const char* Text)
{
	if (Text == NULL || strlen(Text) == 0 ) 
   	{ 
	   ui->lineArticle1->clear();
	   return;
   	}
	ui->lineArticle1->setText(Text);
	return;
}

void MainMagasin::setArticle2(const char* Text)
{
	if (Text == NULL || strlen(Text) == 0 ) 
   	{ 
	   ui->lineArticle2->clear();
	   return;
   	}
	ui->lineArticle2->setText(Text);
	return;
}
void MainMagasin::setArticle3(const char* Text)
{
	if (Text == NULL || strlen(Text) == 0 ) 
  	{ 
	   ui->lineArticle3->clear();
	   return;
   	}
	ui->lineArticle3->setText(Text);
	return;
}
void MainMagasin::setArticle4(const char* Text)
{
	if (Text == NULL || strlen(Text) == 0 ) 
   	{ 
	   ui->lineArticle4->clear();
	   return;
   	}
	ui->lineArticle4->setText(Text);
	return;
}

const char* MainMagasin::getClient() const
{
	static char	Nom[255];

	if (ui->lineClient->text().size())
	{ 
		strcpy(Nom,ui->lineClient->text().toStdString().c_str());
		return Nom;
	}
	return NULL;
}

const char* MainMagasin::getNumCompte() const
{
	static char	Nom[255];

	if (ui->lineNumCompte->text().size())
	{ 
		strcpy(Nom,ui->lineNumCompte->text().toStdString().c_str());
		return Nom;
	}
	return NULL;
}

void MainMagasin::setTextBoutonValider(const char* Texte)
{
	ui->ButtonValider->setText(Texte);
	return;
}

void MainMagasin::setTextBoutonQuitter(const char* Texte)
{
	ui->ButtonQuitter->setText(Texte);
	return;
}

void MainMagasin::setInfo(const char* Text)
{
	if (Text == NULL || strlen(Text) == 0 ) 
   	{ 
	   ui->lineInfo->clear();
	   return;
   	}
	ui->lineInfo->setText(Text);
	return;
}

void MainMagasin::setImage(const char* Image)
{
	char Buff[256];
	sprintf(Buff,"./Images/%s",Image);
	Trace("./Images/%s",Image);
    QPixmap Pix(Buff);
    ui->labelImage ->setPixmap(Pix);
    ui->labelImage->setScaledContents(true);
}
// ligneInfo
// labelImage
//radioButton1
//checkBox1
