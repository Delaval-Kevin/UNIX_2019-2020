.SILENT:

PROGRAM = FenetreClient Serveur

OBJS = Ecran.o fenetreclient.o main.o moc_fenetreclient.o

ECRAN = $(HOME)/Ecran

GPP = g++ -m64 -Wall -Wl,-R,/opt/Qt4.8/lib -L/usr/lib/64 -L/usr/X11/lib/64 -L/opt/Qt4.8/lib -lQtGui -L/opt/Qt4.8/lib -L/usr/lib/64 -L/usr/X11/lib/64 -lQtCore -lpthread -lrt -I $(ECRAN) 

GPP0 = g++ -m64 -Wall -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I/usr/include -I/usr/X11/include -I $(ECRAN) 

all: $(PROGRAM)



FenetreClient: $(OBJS)
	echo Creation de FenetreClient
	$(GPP) -o FenetreClient $(OBJS)
	
Serveur: Serveur.cpp Ecran.o
	echo Creation de Serveur
	g++ -o Serveur Serveur.cpp Ecran.o -m64 -I $(ECRAN)

Ecran.o: $(ECRAN)/Ecran.cpp
	echo Creation de Ecran.o
	g++ -m64 -c $(ECRAN)/Ecran.cpp -DSUN
	
fenetreclient.o:	fenetreclient.cpp
	echo Creation de fenetreclient.o
	$(GPP0) -c fenetreclient.cpp
	
main.o:	main.cpp
	echo Creation de main.o
	$(GPP0) -c main.cpp
	
moc_fenetreclient.o:	moc_fenetreclient.cpp
	echo Creation de moc_fenetreclient.o
	$(GPP0) -c moc_fenetreclient.cpp
