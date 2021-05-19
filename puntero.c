#include <stdio.h>
#include <stdlib.h>

char x,y  ;
char *p;/*puntero*/
char *puntero;


 p = $x;
 puntero= $y;

x='x';


printf("la direccion de memoria de 'x' es: %p \n", &x);
	printf("y su contenido es : %c \n", *p);

*p=(*p)+1;

printf("y su contenido es : %c \n", *p);

*p=(*p)+2;
printf("y su contenido es : %c \n", *p);
	
	
y='y';
printf("la direccion de memoria de 'y' es: %p \n", &y);
	printf("y su contenido es : %c \n", *puntero);
	
