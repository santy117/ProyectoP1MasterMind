CC = gcc -Wall
LIBS = -lm

all: main

nivel_dificultad.o:nivelDificultad.c nivelDificultad.h
	$(CC) -c nivelDificultad.c 
jugar_partida.o: jugar_partida.c jugar_partida.h
	$(CC) -c jugar_partida.c
lista_partidas.o:lista_partidas.c lista_partidas.h
	$(CC) -c lista_partidas.c 

main:main.c nivelDificultad.o jugar_partida.o lista_partidas.o
	$(CC) nivelDificultad.o lista_partidas.o jugar_partida.o main.c -o main $(LIBS)

clean:
	rm -f main *.o *~ *.bak partidas.txt
