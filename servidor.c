/*Aguilar Ceja Luis Angel 
	socket servidor en c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    char mensaje[100]="";
    int server_fd, new_socket;
    int puerto = 12345;
    int conexiones=5;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
     

    // Configurarmos el servidor
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(puerto);
    bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    
    // Escuchar conexiones 
    listen(server_fd, conexiones);
    
    printf("Servidor escuchando en el puerto: %d\n", puerto);

    while (1) {
        // Aceptamos la conexión
        new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
        
	read(new_socket,mensaje,100);
	printf("mensaje recibido: %s\n",mensaje);
       
        close(new_socket);
    }

    return 0;
}



