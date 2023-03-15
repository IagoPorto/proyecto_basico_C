CC = gcc -Wall

all:biblioteca

pantalla.o: pantalla.c pantalla.h
	$(CC) -c pantalla.c

base_datos.o: base_datos.c base_datos.h
	$(CC) -c base_datos.c

biblioteca: biblioteca.c biblioteca.h pantalla.o base_datos.o
	$(CC) biblioteca.c pantalla.o base_datos.o -o biblioteca

clean:
	rm -f biblioteca *.o *~ *.bak
