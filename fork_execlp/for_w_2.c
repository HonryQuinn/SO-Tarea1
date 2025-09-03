#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

    if (argc < 2) {
        printf("Error: Debes proporcionar un número como argumento.\n");
        return 1;
    }

    int iteracion = atoi(argv[1]);

    printf("Hola, soy el hijo %d\n", iteracion);
    return 0;
}