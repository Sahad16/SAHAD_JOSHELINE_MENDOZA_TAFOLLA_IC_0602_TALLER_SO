#include<stdio.h>

int main(){
	
	char arrayChar[5];
	int i = 0;

	for(int car = 97; car < 102; car++){
		arrayChar[i] = car;
		i++;
	}

	char *punteroChar;
       	punteroChar = &arrayChar[0];

	char *punteroCharDos;
       	punteroCharDos = &arrayChar[0];


    printf("\nContenido [0] de arrayChar = %c", arrayChar[0]);

    printf("\nContenido del primer elemento de punteroChar = %c", *punteroChar);

    printf("\nContenido del primer elemento de punteroCharDos = %c", *punteroCharDos);

    printf("\nContenido del quinto elemento de arrayChar = %c", arrayChar[4]);

    printf("\nContenido del quinto elemento de punteroChar con aritmetica de punteros = %c", *(punteroChar + 4));

    printf("\nContenido del quinto elemento de punteroCharDos con arimética de punteros = %c", *(punteroCharDos + 4));

      for (i = 0; i < 5; i++){
        printf("\nContenido [%i] de punteroCharDos = %c", i, *(punteroCharDos + i));
      }
      printf("\n");
      for (int i = 0; i < 5; i++){
        printf("\nContenido [%i] de punteroCharDos = %c", i, *(punteroCharDos + i));
      }
      return 0;
    }
