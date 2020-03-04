echo Creation de Ecran.o
g++ -c -m64 -o Ecran.o $HOME/Ecran/Ecran.cpp -DSUN
 
echo Creation de gereprocessus.o
g++ -c -m64 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64  -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I/usr/X11/include -I $HOME/Ecran -o gereprocessus.o gereprocessus.cpp

echo Creation de mainGereProcessus.o
g++ -c -m64 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64  -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I/usr/X11/include -I $HOME/Ecran -o mainGereProcessus.o mainGereProcessus.cpp

echo Creation de moc_gereprocessus.o
g++ -c -m64 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64  -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I/usr/X11/include -I $HOME/Ecran -o moc_gereprocessus.o moc_gereprocessus.cpp

echo Creation de GereProcessus
g++ -m64 -Wl,-R,/opt/Qt4.8/lib -o GereProcessus Ecran.o  gereprocessus.o  mainGereProcessus.o  moc_gereprocessus.o    -L/usr/lib/64 -L/usr/X11/lib/64 -L/opt/Qt4.8/lib -lQtGui -L/opt/Qt4.8/lib -L/usr/lib/64 -L/usr/X11/lib/64 -lQtCore -lpthread -lrt

echo Creation de mainTraitement.o
g++ -c -m64 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64  -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I/usr/X11/include -I $HOME/Ecran -I /usr/mysql/5.6/include -o mainTraitement.o mainTraitement.cpp

echo Creation de traitementfichier.o
g++ -c -m64 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64  -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I/usr/X11/include -I $HOME/Ecran -I /usr/mysql/5.6/include -o traitementfichier.o traitementfichier.cpp

echo Creation de moc_traitementfichier.o
g++ -c -m64 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64  -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I/usr/X11/include -I $HOME/Ecran -I /usr/mysql/5.6/include -o moc_traitementfichier.o moc_traitementfichier.cpp

echo Creation de TraitementFichier
g++ -m64 -Wl,-R,/opt/Qt4.8/lib -o TraitementFichier Ecran.o mainTraitement.o  traitementfichier.o  moc_traitementfichier.o    -L/usr/lib/64 -L/usr/X11/lib/64 -L/opt/Qt4.8/lib -lQtGui -L/opt/Qt4.8/lib -L/usr/lib/64 -L/usr/X11/lib/64 -lQtCore -lpthread -lrt -L/usr/mysql/5.6/lib/amd64 -R/usr/mysql/5.6/lib/amd64 -lmysqlclient   -lthread -lsocket -lnsl -lm

