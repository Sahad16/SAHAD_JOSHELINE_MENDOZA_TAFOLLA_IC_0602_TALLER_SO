#include <stdio.h>

int main (){
char x,y  ;
char *p;/*puntero*/
char *puntero;


 p = &x;
 puntero= &y;

	x='x';


printf("la direccion de memoria de 'x' es: %p \n", &x);
	printf("el contenido del puntero p es : %c \n", *p);

*p=(*p)+1;

printf("el  contenido del puntero p es : %c \n", *p);

*p=(*p)+2;
printf("el  contenido del puntero p es  : %c \n", *p);
	
	
y='y';
printf("la direccion de memoria de 'y' es: %p \n", &y);
	printf("y su contenido del puntero puntero : %c \n", *puntero);
	
	return 0;
}
