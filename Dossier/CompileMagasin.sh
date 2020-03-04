echo Creation de mainFenetreMagasin.o
g++ -c -m64 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64 -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I. -I /export/home/student/Ecran -I/usr/include -I/usr/X11/include -o mainFenetreMagasin.o mainFenetreMagasin.cpp

echo Creation de MainMagasin.o
g++ -c -m64 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64 -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I. -I /export/home/student/Ecran -I/usr/include -I/usr/X11/include -o MainMagasin.o MainMagasin.cpp

echo Creation de moc_MainMagasin.o
g++ -c -m64 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64 -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I. -I /export/home/student/Ecran -I/usr/include -I/usr/X11/include -o moc_MainMagasin.o moc_MainMagasin.cpp

echo Creation de Magasin
g++ -m64 -Wl,-R,/opt/Qt4.8/lib -o Magasin mainFenetreMagasin.o  MainMagasin.o  moc_MainMagasin.o    -L/usr/lib/64 -L/usr/X11/lib/64 -L/opt/Qt4.8/lib -lQtGui -L/opt/Qt4.8/lib -L/usr/lib/64 -L/usr/X11/lib/64 -lQtCore -lpthread -lrt Ecran.o

