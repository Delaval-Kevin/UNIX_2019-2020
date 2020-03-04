.SILENT:

PROGRAM = ListeEtudiants2019 Lect CreationSessionMysql

OBJS = main.o MainListeEtudiants2019.o moc_MainListeEtudiants2019.o

GPP2 = g++ -m64 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64 -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I $(HOME)/Ecran -I/usr/include -I/usr/X11/include

GPP1 = g++ -m64 -Wall -Wl,-R,/opt/Qt4.8/lib $(HOME)/Ecran/Ecran.o -m64 -I /usr/mysql/5.6/include -L/usr/mysql/5.6/lib/amd64 -R/usr/mysql/5.6/lib/amd64 -lmysqlclient   -lthread -lsocket -lnsl -lm -I $(HOME)/Ecran

GPP0 = g++ $(HOME)/Ecran/Ecran.o -Wall -L/usr/lib/64 -L/usr/X11/lib/64 -L/opt/Qt4.8/lib -lQtGui -L/opt/Qt4.8/lib -L/usr/lib/64 -L/usr/X11/lib/64 -lQtCore -lpthread -lrt -m64 -Wl,-R,/opt/Qt4.8/lib

all: $(PROGRAM)


ListeEtudiants2019: $(OBJS)
	echo Creation de ListeEtudiants2019
	$(GPP0) -o ListeEtudiants2019 $(OBJS)

Lect: Lect.cpp
	echo Creation de Lect
	$(GPP1) -o Lect Lect.cpp
	
CreationSessionMysql: CreationSessionMysql.cpp
	echo Creation de CreationSessionMysql
	$(GPP1) -o CreationSessionMysql CreationSessionMysql.cpp

main.o: main.cpp
	echo Creation de main.o
	$(GPP2) -c main.cpp

MainListeEtudiants2019.o: MainListeEtudiants2019.cpp
	echo Creation de MainListeEtudiants2019.o
	$(GPP2) -c MainListeEtudiants2019.cpp

moc_MainListeEtudiants2019.o: moc_MainListeEtudiants2019.cpp
	echo Creation de moc_MainListeEtudiants2019.o
	$(GPP2) -c moc_MainListeEtudiants2019.cpp

