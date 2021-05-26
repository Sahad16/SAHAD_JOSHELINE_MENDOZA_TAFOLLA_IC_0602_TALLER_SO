#include<stdio.h>

int main(){
	
	char arrayChar[5];
	char i = 0;

	for(char i= 'a'; i< 'f'; i++){
		arrayChar[i - a] = i;
		i++;
	}

	char *punteroChar = arrayChar;

	char *punteroCharDos;
       	punteroCharDos = &arrayChar[0];


    printf("\nContenido primer elemento de arrayChar = %c", arrayChar[0]);

    printf("\nContenido primer elemento de punteroChar = %c", *punteroChar);

    printf("\nContenido primer elemento de punteroCharDos = %c", *punteroCharDos);

    printf("\nContenido quinto elemento de arrayChar = %c", arrayChar[4]);
	
	//aritmetica de punteros

    printf("\nContenido quinto elemento de punteroChar con aritmetica de punteros = %c", *(punteroChar + 4)); 

    printf("\nContenido quinto elemento de punteroCharDos con arimética de punteros = %c", *(punteroCharDos + 4));

      for (i = 0; i < 5; i++){
        printf("\nContenido [%i] de punteroCharDos = %c", i, *(punteroCharDos + i));
      }
      printf("\n");
      for (int i = 0; i < 5; i++){
        printf("\nContenido [%i] de punteroCharDos = %c", i, *(punteroCharDos + i));
      }
      return 0;
    }
