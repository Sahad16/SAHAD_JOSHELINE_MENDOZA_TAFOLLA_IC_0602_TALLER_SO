  /*PROGRAMA DE GESTION DE ARCHIVOS*/

#include<stdio.h>
#include<string.h>
#define T_NOMBRE 100
#define T_NUM 100000

int existe_archivo(char *nombre_arch);

int crear_archivo(char *nombre_arch);

void cerrar_archivo(FILE *ptrArchivo, char *nombre_arch);

FILE *abrir_lectura_escritura(char *nombre_arch);

int tiene_datos_arch(char *nombre_arch);

FILE *abrir_solo_Lectura(char *nombre_arch);

void imprimir(int vector[], int tam);

void ordBurbuja(int a[], int n);

int total_arch(char *nombre_arch);


int main(int argc, char *argv[]){
	FILE *inputFile = NULL;
	FILE *outputFile = NULL;
	
	char enombre[T_NOMBRE];
	char snombre[T_NOMBRE];
	int contador = 0;
	char str_archivo[20];
	int existe_arch = 0;	

	if (argc > 2 && argc <= 3){
	strcpy(enombre, argv[1]);
	strcpy(snombre, argv[2]);
	printf("Leyendo argumentos\n");
	printf("Cantidad de argumentos: %i\n", argc);
	printf("bin = %s\n", argv[0]);
	printf("Argumento 1: %s\n", enombre);
	printf("Argumento 2: %s\n", snombre);


	} else{
	printf("sin argumentos, agrega 2 argumentos antes de la ejecucion del programa (leer/escribir)\n");
	return -1;
	}
	
	
	printf("\nVerificacion de archivo de entrada...");
	existe_arch = existe_archivo(enombre);
	if (existe_arch){
	printf("\n%s existe..", enombre);
	} else{
	printf("\n%s no existe..\n", enombre);
	printf("\nSe creará el archivo...\n");

		if(crear_archivo(enombre)){		
		printf("\nEl archivo %s ha sido creado..", enombre);
		printf("\n  Escribe un parrafo en el archivo  para continuar...");
		printf("\n pasa el archivo como parámetro..");
		return -1;
		} 
        else {
		printf("\n Archivo %s no creado", enombre);
		
		}

		return -1;
	}

	if(tiene_datos_arch(enombre)){
	printf("\t\nEl archivo %s contiene datos", enombre);
	printf("\n\nLectura del Archivo\n");

	inputFile = abrir_solo_Lectura(enombre);

		if (inputFile == NULL){
		printf("\nEl archivo %s no pudo abrirse", enombre);
		} 

        else {
		printf("\nEl archivo %s ha sido abierto", enombre);
		fscanf(inputFile, "%s", &str_archivo);
        
		while(!feof(inputFile)){
			printf("%s\n", str_archivo);
			fscanf(inputFile, "%s", &str_archivo);
			contador++;
			}
			printf("\nTotal de palabras leídas: %d", contador);
		}

	} else {
	printf("\t\nEl archivo %s no contiene datos", enombre);
	return -1;
	}
		

	return 0;
}

void imprimir(int vector[], int tam){
        int i;
        for(i = 0; i < tam; i++){
                printf("%5d", vector[i]);
                if((i+1)%5 == 0)
                        printf("\n");
        }
        printf("\n");
}

int total_arch(char *nombre_arch){
        int lee_linea = 0, contador = 0;
        FILE *ptrArchivo;
        ptrArchivo = abrir_solo_Lectura(nombre_arch);
        if(ptrArchivo == NULL){
        printf("El archivo  %s No se pudo abrir.\n", nombre_arch);
        }

        else{
        printf("Archivo  %s  abierto .\n", nombre_arch);
        fscanf(ptrArchivo, "%d", &lee_linea);
                
                while(!feof(ptrArchivo)){
                        contador++;
                       
                fscanf(ptrArchivo, "%d", &lee_linea);
                }

                cerrar_archivo(ptrArchivo, nombre_arch);
        }
        return contador;
}

int tiene_datos_arch(char *nombre_arch){
        int existen_datos = 0;
        FILE *ptrArchivo;
        int lee_linea = 0, contador = 0;
        ptrArchivo = abrir_solo_Lectura(nombre_arch);
        if(ptrArchivo == NULL){
        printf("El archivo %s  No se pudo abrir\n", nombre_arch);
        existen_datos = 0;
        }
        else{
                printf("Archivo %s abierto  ", nombre_arch);
                fscanf(ptrArchivo, "%d", &lee_linea);
                while(!feof(ptrArchivo)){
                        contador++;
                        fscanf(ptrArchivo, "%d", &lee_linea);
                        if(contador > 0){
                                existen_datos = 1;
                                break;
                        }
                }
                cerrar_archivo(ptrArchivo, nombre_arch);
        }
        return existen_datos;
}

FILE *abrir_solo_Lectura(char *nombre_arch){
        FILE *ptrArchivo;
        ptrArchivo = fopen(nombre_arch, "r");
        if( ptrArchivo == NULL ){
        printf("El archivo  %s No pudo abrirse\n", nombre_arch);
        }
        else{
        printf(" Archivo  %s Abierto \n", nombre_arch);
        }

        return ptrArchivo;
}

FILE *abrir_lectura_escritura(char *nombre_arch){
        FILE *ptrArchivo;
        ptrArchivo = fopen(nombre_arch, "r+");
        if( ptrArchivo == NULL ){
         printf(" El archivo  %s  No pudo abrirse \n", nombre_arch);
        }
        else{
        printf(" Archivo %s Abierto \n", nombre_arch);
        }
        return ptrArchivo;
}

int existe_archivo(char *nombre_arch){
        FILE *ptrArchivo;
        int existe = 0;
        ptrArchivo = fopen(nombre_arch, "r");
        if( ptrArchivo != NULL ){
        existe = 1;
        cerrar_archivo(ptrArchivo, nombre_arch);
        }

        return existe;
}

int crear_archivo(char *nombre_arch){
        int creado = 0;
        FILE *ptrArchivo;
        ptrArchivo = fopen(nombre_arch, "w");
        if( ptrArchivo == NULL ){
        printf(" El archivo  %s no pudo crearse\n", nombre_arch);
        }

        else{
        creado = 1;
        printf("Archivo %s  Creado \n", nombre_arch);
        cerrar_archivo(ptrArchivo, nombre_arch);
        }

        return creado;
}

void cerrar_archivo(FILE *ptrArchivo, char *nombre_arch){
        fclose(ptrArchivo);
        printf(" Archivo %s Cerrado \n", nombre_arch);
}
