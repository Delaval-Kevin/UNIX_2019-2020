.SILENT:

GPP1 = g++ -m64 -Wl,-R,/usr/local/Trolltech/Qt-4.8.6/lib -L/usr/lib/64 -L/usr/X11/lib/64 -L/usr/local/Trolltech/Qt-4.8.6/lib -lQtGui -L/usr/local/Trolltech/Qt-4.8.6/lib -L/usr/lib/64 -L/usr/X11/lib/64 -lQtCore -lpthread -lrt

GPP2 = g++ -c -m64 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/usr/local/Trolltech/Qt-4.8.6/mkspecs/solaris-g++-64 -I. -I/usr/local/Trolltech/Qt-4.8.6/include/QtCore -I/usr/local/Trolltech/Qt-4.8.6/include/QtGui -I/usr/local/Trolltech/Qt-4.8.6/include -I. -I. -I/usr/include -I/usr/X11/include

PROGRAM = DeuxiemeDossierUnix2019

OBJS = DeuxiemeDossierUnix2019.o  main.o  moc_DeuxiemeDossierUnix2019.o  Ecran.o

all: $(PROGRAM)

DeuxiemeDossierUnix2019: $(OBJS)
	echo Creation de DeuxiemeDossierUnix2019
	$(GPP1) -o DeuxiemeDossierUnix2019 $(OBJS)

Ecran.o: $(HOME)/Ecran/Ecran.cpp $(HOME)/Ecran/Ecran.h
	echo Creation de Ecran.o
	g++ -c $(HOME)/Ecran/Ecran.cpp -D SUN

DeuxiemeDossierUnix2019.o:DeuxiemeDossierUnix2019.cpp
	echo Creation de DeuxiemeDossierUnix2019.o
	$(GPP2) -I$(HOME)/Ecran DeuxiemeDossierUnix2019.cpp
	
main.o:main.cpp
	echo Creation de main.o
	$(GPP2) -I. main.cpp
	
moc_DeuxiemeDossierUnix2019.o:moc_DeuxiemeDossierUnix2019.cpp
	echo Creation de moc_DeuxiemeDossierUnix2019.o
	$(GPP2) -I. moc_DeuxiemeDossierUnix2019.cpp
