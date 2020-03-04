echo Creation de Ecran.o
g++ -m64 -D SUN -Wall -I /export/home/student/Ecran -D CPP -c /export/home/student/Ecran/Ecran.cpp

echo creation de Central
g++ -m64 -D SUN -Wall -I /export/home/student/Ecran -D CPP -o Central Central.cpp Ecran.o -I /usr/mysql/5.6/include -L/usr/mysql/5.6/lib/amd64 -R/usr/mysql/5.6/lib/amd64 -lmysqlclient   -lthread -lsocket -lnsl -lm

echo creation de CreationBd
g++ -m64 -D SUN -Wall -I /export/home/student/Ecran -D CPP -o CreationBd CreationBd.cpp Ecran.o -I /usr/mysql/5.6/include -L/usr/mysql/5.6/lib/amd64 -R/usr/mysql/5.6/lib/amd64 -lmysqlclient   -lthread -lsocket -lnsl -lm

echo creation de ServiceFacturation
g++ -m64 -D SUN -Wall -I /export/home/student/Ecran -D CPP -o ServiceFacturation ServiceFacturation.cpp Ecran.o -I /usr/mysql/5.6/include -L/usr/mysql/5.6/lib/amd64 -R/usr/mysql/5.6/lib/amd64 -lmysqlclient   -lthread -lsocket -lnsl -lm

echo creation de ServiceLivraison
g++ -m64 -D SUN -Wall -I /export/home/student/Ecran -D CPP -o ServiceLivraison ServiceLivraison.cpp Ecran.o -I /usr/mysql/5.6/include -L/usr/mysql/5.6/lib/amd64 -R/usr/mysql/5.6/lib/amd64 -lmysqlclient   -lthread -lsocket -lnsl -lm

echo creation de VehiculeLivraison
g++ -m64 -D SUN -Wall -I /export/home/student/Ecran -D CPP -o VehiculeLivraison VehiculeLivraison.cpp Ecran.o -I /usr/mysql/5.6/include -L/usr/mysql/5.6/lib/amd64 -R/usr/mysql/5.6/lib/amd64 -lmysqlclient   -lthread -lsocket -lnsl -lm

