void MainWindow::setNom(const char* Text)
{
printf("---%s---\n",Text);
if (strlen(Text) == 0 ) 
   { 
   ui->lineNom->clear();
   return;
   }
ui->lineNom->setText(Text);
return;
}

void MainWindow::setMail(const char* Text)
{
if (strlen(Text) == 0 ) 
   { 
   ui->lineMail->clear();
   return;
   }
ui->lineMail->setText(Text);
return;
}


