#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (){
    pid_t r[3];

    for(int i=0 ; i<3 ; i++){
        r[i] = fork();
        if (r[i] == 0){
            char iteracion[10];
            int n=i+1;
            sprintf(iteracion, "%d", n); // convierte el i a string
            execlp("./for_w_2", "for_w_2", iteracion , (char*)NULL);
        }
    }

    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }

    return 0;
 }