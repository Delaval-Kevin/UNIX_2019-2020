.SILENT:

GPP1 = g++ -m64 -Wl,-R,/opt/Qt4.8/lib -L/usr/lib/64 -L/usr/X11/lib/64 -L/opt/Qt4.8/lib -lQtGui -L/opt/Qt4.8/lib -L/usr/lib/64 -L/usr/X11/lib/64 -lQtCore -lpthread -lrt

GPP2 = g++ -c -m64 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64 -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I. -I. -I. -I/usr/include -I/usr/X11/include

OBJS = main.o  mainwindow.o  moc_mainwindow.o Ecran.o

PremierDossierUnix2019:$(OBJS)
	echo Creation de PremierDossierUnix2019
	$(GPP1) -o PremierDossierUnix2019 $(OBJS)
	
Ecran.o:Ecran.cpp
	echo Creation de Ecran.o
	g++ -D SUN -m64 -Wall Ecran.cpp -c

main.o:main.cpp
	echo Creation de main.o
	$(GPP2) -o main.o main.cpp

mainwindow.o:mainwindow.cpp
	echo Creation de mainwindow.o
	$(GPP2) -o mainwindow.o mainwindow.cpp

moc_mainwindow.o:moc_mainwindow.cpp
	echo Creation de moc_mainwindow.o
	$(GPP2) -o moc_mainwindow.o moc_mainwindow.cpp
