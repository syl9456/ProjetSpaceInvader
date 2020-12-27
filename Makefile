# _*_ Makefile _*_

#target: dependencies
#	actions

CC = gcc
CFLAGS= -Wall -W -std=c89 -pedantic -O3 `pkg-config --cflags MLV`
LDFLAGS= `pkg-config --libs-only-other --libs-only-L MLV`
LDLIBS= `pkg-config --libs-only-l MLV`
OBJ= $(SRC:.c=.o)

#lien 
main: main.o player.o util.o enemy.o bullet.o
	$(CC) $(CFLAGS) -o main main.o player.o util.o enemy.o bullet.o $(LDFLAGS) $(LDLIBS)

#compilation
main.o: main.c functions.h
	$(CC) $(CFLAGS) -c main.c

bullet.o: bullet.c global.h
	$(CC) $(CFLAGS) -c bullet.c

player.o: player.c global.h
	$(CC) $(CFLAGS) -c player.c

enemy.o: enemy.c global.h
	$(CC) $(CFLAGS) -c enemy.c

util.o: util.c global.h
	$(CC) $(CFLAGS) -c util.c

#make clean pour utiliser
clean:
	rm -f *.o main

#schema dependance :

#			main.c
#			|
#			|
#	---------------	function.h----------------------------	
#	|		|		| 		     |
#	|		|		|		     |
#	bullet.c	player.c	enemy.c		util.c
#	|		|		|		     |
#	|		|		|		     |
#	----------------global.h------------------------------
