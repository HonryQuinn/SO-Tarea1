#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MESSAGE_BUFFER_SIZE 256

int main() {
    const char *log_pipe = "./my_log_pipe";
    int fd;
    char received_message[MESSAGE_BUFFER_SIZE];
    int len;


    mkfifo(log_pipe, 0666); 

    printf("Log iniciado. Esperando mensajes...\n");

    fd = open(log_pipe, O_RDONLY);

    while (1) {

        ssize_t bytes_read = read(fd, &len, sizeof(int));
        

        if (bytes_read == 0) {
            printf("El escritor cerró la conexión. Reiniciando...\n");
            close(fd);
            fd = open(log_pipe, O_RDONLY);
            continue;
        }

        read(fd, received_message, len);

        printf("Mensaje recibido: %s\n", received_message);
    }
    
    close(fd);
    unlink(log_pipe);

    return 0;
}