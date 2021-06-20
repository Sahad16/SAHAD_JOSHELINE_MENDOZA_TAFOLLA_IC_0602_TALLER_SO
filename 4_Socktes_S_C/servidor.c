
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include "debug.h"
#define MAX 1000

int main(int argc, char const *argv[]) {
	if (argc < 2){
		printf("Debes especificar el puerto: ./programa <puerto>\n");
		return 1;
	}
	
	// Se guarda el parámetro del puerto en una variable
	int puerto = atoi(argv[1]);
	int server_fd, new_socket, valread;
    	struct sockaddr_in address;
    	int opt = 1;
    	int addrlen = sizeof(address);
    	char buffer[MAX] = {0};
    	char *hello = "1. Hello from server";
       
    	// Creating socket file descriptor
    	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        	perror("socket failed");
        	exit(EXIT_FAILURE);
    	}
       
    	// Forcefully attaching socket to the port 8080
    	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt))) {
        	perror("setsockopt");
        	exit(EXIT_FAILURE);
    	}
    	address.sin_family = AF_INET;
    	address.sin_addr.s_addr = INADDR_ANY;
    	address.sin_port = puerto;
       
    	// Forcefully attaching socket to the port 8080
    	if (bind(server_fd, (struct sockaddr *)&address,sizeof(address))<0) {
        	perror("bind failed");
        	exit(EXIT_FAILURE);
    	}
    	if (listen(server_fd, 3) < 0) {
        	perror("listen");
        	exit(EXIT_FAILURE);
    	}
    	printf("Esperando la conexión...\n");
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        	perror("accept");
        	exit(EXIT_FAILURE);
    	}
    	
	char str1[MAX];
	char str2[MAX];
	
	// Limpiando el bffer
	bzero(buffer, MAX);
	valread = read( new_socket , buffer, MAX);
    	printf("%s\n",buffer );
	strcpy(str1, buffer);
	
	// Limpiando el buffer
	bzero(buffer, MAX);
	valread = read( new_socket , buffer, MAX);
    	printf("%s\n",buffer );
	strcpy(str2, buffer);
    	
	// Longitud de los strings
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int num1[MAX];
	int num2[MAX];	
	int nSuma[MAX];	
	
	// Extrayendo los números de los caracteres
	int i = 0;
	while (i <= len1){
		num1[i] = str1[i] - '0';
		i++;
	}

	i = 0;
	while(i <= len2){
		num2[i] = str2[i] - '0';
		i++;
	}
	
	// Realizando la suma, el ciclo de la suma cambia dependiendo cual es el numero mayor
        int temp = 0;
	if (len1 < len2) {
        	int acarreo = 0;
        	int j = len1 - 1;
        	for (int i = len2 - 1; i >= 0; i--){
                	temp = num2[i] + num1[j] + acarreo;
                	if (temp >= 10){
                        	acarreo = temp/10;
                        	temp = temp%10;
                	} else {
                        	acarreo = 0;
                	}
                	j--;
                	nSuma[i] = temp;
        	}
        	if (acarreo != 0){
                	nSuma[0] = nSuma[0]+(acarreo*10);
        	}

	} else {
        	temp = 0;
        	int acarreo = 0;
        	int j = len2 - 1;
        	for (int i = len1 - 1; i >= 0; i--){
                	temp = num1[i] + num2[j] + acarreo ;
                	if (temp >= 10){
                        	acarreo = temp/10;
                        	temp = temp%10;
                	} else {
                        	acarreo = 0;
                	}
                	j--;
                	nSuma[i] = temp;
        	}
        	if (acarreo != 0){
                	nSuma[0] = nSuma[0]+(acarreo*10);
        	}

	}

	// Limpiando el buffer
	bzero(buffer, MAX);
	// aqui se hace el proceso inverso, los números (int) se convierten a char
	// y se almacenan en el arreglo char nSuma
	if (len1 < len2) {
        	int i = 0;
	        int j = 0;
        	if ((nSuma[i]) >= 10){
	                temp = nSuma[i];
	                buffer[0] = (temp/10) + '0';
	                buffer[1] = (temp%10) + '0';
	                len2++;
	                i = i + 2;
	                j++;
        	}
	        while(i != len2){
	                buffer[i] = nSuma[j] + '0';
        	        i++;
	                j++;
        	}
	} else {
	        int i = 0;
        	int j = 0;
	        if ((nSuma[i]) >= 10){
        	        temp = nSuma[i];
                	buffer[0] = (temp/10) + '0';
	                buffer[1] = (temp%10) + '0';
        	        len1++;
                	i = i + 2;
	                j++;
        	}
	        while(i != len1){
        	        buffer[i] = nSuma[j] + '0';
	                i++;
        	        j++;
	        }	
	}

	send(new_socket, buffer, strlen(buffer), 0);
	//send(new_socket , hello , strlen(hello) , 0 );
    	printf("\nLa suma es = %s\n", buffer);
    	printf("\nCliente Desconectado\n");
	close(new_socket);
    	return 0;
}

