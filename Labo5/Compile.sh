echo Creation de FenetreClient

g++ -m64 -c $HOME/Ecran/Ecran.cpp -DSUN

g++ -c -m64 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I/usr/include -I/usr/X11/include -I $HOME/Ecran -o fenetreclient.o fenetreclient.cpp

g++ -c -m64 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I/usr/include -I/usr/X11/include -I $HOME/Ecran -o main.o main.cpp

g++ -c -m64 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I/usr/include -I/usr/X11/include -I $HOME/Ecran -o moc_fenetreclient.o moc_fenetreclient.cpp

g++ -m64 -Wl,-R,/opt/Qt4.8/lib -o FenetreClient fenetreclient.o  main.o  moc_fenetreclient.o Ecran.o   -L/usr/lib/64 -L/usr/X11/lib/64 -L/opt/Qt4.8/lib -lQtGui -L/opt/Qt4.8/lib -L/usr/lib/64 -L/usr/X11/lib/64 -lQtCore -lpthread -lrt

echo Creation de Serveur

g++ -o Serveur Serveur.cpp Ecran.o -m64 -I $HOME/Ecran

