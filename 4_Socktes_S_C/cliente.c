// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000

int main(int argc, char const *argv[]) {
	if (argc < 3){
		printf("Debes especificar la IP y el puerto: ./programa <IP> <puerto>\n");
		return -1;
	}

	int puerto = atoi(argv[2]);

	int sock = 0, valread;
    	struct sockaddr_in serv_addr;
    	char *hello = "1. Hello from client";
	char *hola = "2. Hola desde el cliente";
    	char buffer[1024] = {0};
    	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        	printf("\n Socket creation error \n");
        	return -1;
    	}
   
    	serv_addr.sin_family = AF_INET;
    	serv_addr.sin_port = puerto;
    	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	// Convert IPv4 and IPv6 addresses from text to binary form
    	/*if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  {
        	printf("\nInvalid address/ Address not supported \n");
        	return -1;
    	}*/
   
    	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
       		printf("\nFalló la conexión\n");
        	return -1;
	} 
    	
	char num1[MAX] = {0};
	char num2[MAX] = {0};
	printf("Ingresa el primer número: ");
	scanf("%s", num1);
	printf("Ingresa el segundo número: ");
	scanf("%s", num2);
	send(sock , num1 , strlen(num1) , 0 );
	send(sock , num2 , strlen(num2) , 0 );
	printf("Números enviados al servidor...\n");

	valread = read( sock , buffer, MAX);
    	printf("El servidor ha enviado la suma de los números: %s\n",buffer );

	close(sock);
    	return 0;
}
