//BASE DE DATOS .H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct struct_lector{
  short codigo;
  char nombre[50];
}lector_t;
lector_t lectores[300];




typedef struct struct_comments{
  short lector;
  char opinion[80];
}comment_t;
typedef struct struct_referencia{
  int signatura;
  char tipo;
  char autor[50];
  char titulo[80];
  short anho;
  short votantes;
  int votos;
  short criticos;
  comment_t comment[10];
}referencia_t;
referencia_t referencias[300];



void lector(lector_t *lector, int *n);

void referencia(referencia_t *referencia, int *n);

void opinion(referencia_t *referencia, int nl, int nr);

void obtinf(referencia_t *referencia, lector_t *lector, int nr, int nl);

void voto(referencia_t *referencia, int nr);

void nota(referencia_t *referencia, int nr);







int cargar_lect(lector_t *referencia);

int cargar_ref(referencia_t *referencia);

void guardar_lectores(lector_t *lector, int n);

void guardar_referencias(referencia_t *referencia, int n);

int cogf(int n);





