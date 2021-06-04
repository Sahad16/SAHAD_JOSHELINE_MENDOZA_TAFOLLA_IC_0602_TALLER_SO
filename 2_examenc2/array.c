#include<stdio.h>

int main(){
	
	char arrayChar[5];
	int i=0;

	for (int letra = 97; letra <102; letra++){	
		arrayChar[i] = letra;
		i++;
	}
	

	char *punteroChar = arrayChar;

	char *punteroCharDos;
       	punteroCharDos = &arrayChar[0];


    printf("\nContenido  elemento 1 de arrayChar = %c", arrayChar[0]);

    printf("\nContenido  elemento 1 de punteroChar = %c", *punteroChar);

    printf("\nContenido  elemento 1 de punteroCharDos = %c", *punteroCharDos);

    printf("\nContenido  elemento 1 de arrayChar = %c", arrayChar[4]);
	
	//aritmetica de punteros

    printf("\n 5to elemento punteroChar con aritmetica de punteros = %c", *(punteroChar + 4)); 

    printf("\n 5to elemento punteroCharDos con arimetica de punteros = %c", *(punteroCharDos + 4));

      for (i = 0; i < 5; i++){
        printf("\nContenido [%i] de punteroCharDos = %c", i, *(punteroCharDos + i));
      }
      printf("\n");
      for (int i = 0; i < 5; i++){
        printf("\nContenido [%i] de punteroCharDos = %c", i, *(punteroCharDos + i));
      }
      return 0;
    }
