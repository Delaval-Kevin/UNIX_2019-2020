.SILENT:

PROGRAMS = Central CreationBd ServiceFacturation ServiceLivraison VehiculeLivraison Magasin Mail

OBJSC = Ecran.o

OBJSMA = Ecran.o mainFenetreMagasin.o MainMagasin.o moc_MainMagasin.o

OBJSMI = mainFenetreMail.o MainMail.o moc_MainMail.o

ECRAN = $(HOME)/Ecran

GPPCEN = g++ -m64 -D SUN -Wall -I $(ECRAN) -D CPP -I /usr/mysql/5.6/include -L/usr/mysql/5.6/lib/amd64 -R/usr/mysql/5.6/lib/amd64 -lmysqlclient -lthread -lsocket -lnsl -lm

GPPMO = g++ -c -m64 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64 -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I. -I /export/home/student/Ecran -I /export/home/colletlo/Ecran -I/usr/include -I/usr/X11/include

GPPMA = g++ -m64 -Wl,-R,/opt/Qt4.8/lib -L/usr/lib/64 -L/usr/X11/lib/64 -L/opt/Qt4.8/lib -lQtGui -L/opt/Qt4.8/lib -L/usr/lib/64 -L/usr/X11/lib/64 -lQtCore -lpthread -lrt

GPPMIO = g++ -c -m64 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64 -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I. -I. -I. -I/usr/include -I/usr/X11/include


all: $(PROGRAMS)


Central: Central.cpp $(OBJSC)
	echo Creation de Central
	$(GPPCEN) -o Central $(OBJSC) Central.cpp

CreationBd: CreationBd.cpp $(OBJSC)
	echo Creation de CreationBd
	$(GPPCEN) -o CreationBd $(OBJSC) CreationBd.cpp
	
ServiceFacturation: ServiceFacturation.cpp $(OBJSC)
	echo Creation de ServiceFacturation
	$(GPPCEN) -o ServiceFacturation $(OBJSC) ServiceFacturation.cpp
	
ServiceLivraison: ServiceLivraison.cpp $(OBJSC)
	echo Creation de ServiceLivraison
	$(GPPCEN) -o ServiceLivraison $(OBJSC) ServiceLivraison.cpp

VehiculeLivraison: VehiculeLivraison.cpp $(OBJSC)
	echo Creation de VehiculeLivraison
	$(GPPCEN) -o VehiculeLivraison $(OBJSC) VehiculeLivraison.cpp

Magasin: $(OBJSMA)
	echo Creation de Magasin
	$(GPPMA) -o Magasin $(OBJSMA)
	
Mail: $(OBJSMI)
	echo Creation de Mail
	$(GPPMA) -o Mail $(OBJSMI)

Ecran.o: $(ECRAN)/Ecran.cpp
	echo Creation de Ecran.o
	g++ -m64 -D SUN -Wall -I $(ECRAN) -D CPP -c $(ECRAN)/Ecran.cpp
	
mainFenetreMagasin.o: mainFenetreMagasin.cpp
	echo Creation de mainFenetreMagasin.o
	$(GPPMO) -o mainFenetreMagasin.o mainFenetreMagasin.cpp
	
MainMagasin.o: MainMagasin.cpp
	echo Creation de MainMagasin.o
	$(GPPMO) -o MainMagasin.o MainMagasin.cpp
	
moc_MainMagasin.o: moc_MainMagasin.cpp
	echo Creation de moc_MainMagasin.o
	$(GPPMO) -o moc_MainMagasin.o moc_MainMagasin.cpp
	
mainFenetreMail.o: mainFenetreMail.cpp
	echo Creation de mainFenetreMail.o
	$(GPPMIO) -o mainFenetreMail.o mainFenetreMail.cpp
	
MainMail.o: MainMail.cpp
	echo Creation de MainMail.o
	$(GPPMIO) -o MainMail.o MainMail.cpp
	
moc_MainMail.o: moc_MainMail.cpp
	echo Creation de moc_MainMail.o
	$(GPPMIO) -o moc_MainMail.o moc_MainMail.cpp
	
		
	
	
	
	
