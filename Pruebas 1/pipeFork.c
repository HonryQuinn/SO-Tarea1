#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (void){

    int p1[2];
    int p2[2];
    pipe(p1);
    pipe(p2);
    pid_t t = fork();
    

    if(t==0){
        close(p1[0]); //ciera canal READ
        write (p1[1], "Hola, soy tu hijo", 18);
        close(p1[1]); //ciera canal WRITE

        sleep(5);

        char buf2[20];
        close(p2[1]); //cierra canal WRITE
        read(p2[0], buf2, sizeof(buf2));
        close(p2[0]); // cierra canal READ
        printf("El hijo recibio recibio: %s\n", buf2);
        exit(0);
    }else{
        char buf[20];
        close(p1[1]); //ciera canal WRITE
        read(p1[0],buf,sizeof(buf));
        close(p1[0]); //cierra canal READ
        printf("El padre recibio: %s\n", buf);

        sleep (5);

        close(p2[0]); //cierra canal READ
        write (p2[1], "Hola hijo, como estas?", 20);
        close(p2[1]); //cierra canal WRITE

        wait(NULL);
    }


    return 0;
}