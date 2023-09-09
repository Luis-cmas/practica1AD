/*Aguilar Ceja Luis Angel 
	socket cliente en c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdbool.h>


int main(){

int puerto = 12345;
char ip[] = "127.0.0.1";
int cliente;
char mensaje[100]="";

struct sockaddr_in server_addr;

cliente = socket(AF_INET, SOCK_STREAM,0);
server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(puerto);
server_addr.sin_addr.s_addr = inet_addr(ip);

connect(cliente, (struct sockaddr *)&server_addr, sizeof(server_addr));
printf("se ha conectado al servidor\n");

while(true){
	scanf("%s",&mensaje);
	send(cliente,mensaje, strlen(mensaje),0);
}
close(cliente);

 

return 0;
}
