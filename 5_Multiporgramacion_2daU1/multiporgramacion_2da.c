//Programa multiprogramacion en c 2da oportunidad

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tarea1(){
  printf("Tarea 1\n");
}

void tarea2(){
  printf("Tarea 2\n");
}

void tarea3(){
  printf("Tarea 3\n");
}

void main () {

  time_t t1;
  double tiempo_inicial = time(&t1);

  printf("Presiona Enter para iniciar");
  printf("Presiona Ctrl+C para finalizar el bucle");
  getchar();

  while(1){

       time_t t2;

    double tiempo_final = time(&t1);
    int tiempo_transcurrido = tiempo_final - tiempo_inicial;

    if ((tiempo_transcurrido % 2)==0)
      tarea1();
    if ((tiempo_transcurrido % 3)==0)
      tarea2();
    if ((tiempo_transcurrido % 4)==0)
      tarea3();

  }
}