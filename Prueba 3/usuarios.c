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
    char user_name[50];
    char user_message[200];
    char final_message[MESSAGE_BUFFER_SIZE];

    mkfifo(log_pipe, 0666); 

    fd = open(log_pipe, O_WRONLY);

    printf("Introduce tu nombre: ");
    fgets(user_name, sizeof(user_name), stdin);
    user_name[strcspn(user_name, "\n")] = 0; 

    printf("Escribe tu mensaje: ");
    fgets(user_message, sizeof(user_message), stdin);
    user_message[strcspn(user_message, "\n")] = 0; 

    snprintf(final_message, sizeof(final_message), "%s: %s", user_name, user_message);

    int len = strlen(final_message) + 1;
    write(fd, &len, sizeof(int));
    write(fd, final_message, len);

    close(fd);

    return 0;
}