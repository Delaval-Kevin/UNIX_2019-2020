echo Creation de main.o
g++ -c -m64 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64 -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I $HOME/Ecran -I/usr/include -I/usr/X11/include -o main.o main.cpp

echo Creation de MainListeEtudiants2019.o
g++ -c -m64 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64 -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I $HOME/Ecran -I/usr/include -I/usr/X11/include -o MainListeEtudiants2019.o MainListeEtudiants2019.cpp

echo Creation de moc_MainListeEtudiants2019.o
g++ -c -m64 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64 -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I $HOME/Ecran -I/usr/include -I/usr/X11/include -o moc_MainListeEtudiants2019.o moc_MainListeEtudiants2019.cpp

echo Creation de ListeEtudiants2019
g++ -m64 -Wl,-R,/opt/Qt4.8/lib -o ListeEtudiants2019 main.o  MainListeEtudiants2019.o  moc_MainListeEtudiants2019.o $HOME/Ecran/Ecran.o   -L/usr/lib/64 -L/usr/X11/lib/64 -L/opt/Qt4.8/lib -lQtGui -L/opt/Qt4.8/lib -L/usr/lib/64 -L/usr/X11/lib/64 -lQtCore -lpthread -lrt

#echo creation de Ecran.o
#g++ Ecran.cpp -m64 -c -DSUN

echo creation de Lect
g++ -o Lect Lect.cpp $HOME/Ecran/Ecran.o -m64 -I /usr/mysql/5.6/include -L/usr/mysql/5.6/lib/amd64 -R/usr/mysql/5.6/lib/amd64 -lmysqlclient   -lthread -lsocket -lnsl -lm -I $HOME/Ecran

echo creation de CreationSessionMysql
g++ -o CreationSessionMysql CreationSessionMysql.cpp $HOME/Ecran/Ecran.o -m64 -I /usr/mysql/5.6/include -L/usr/mysql/5.6/lib/amd64 -R/usr/mysql/5.6/lib/amd64 -lmysqlclient   -lthread -lsocket -lnsl -lm -I $HOME/Ecran
