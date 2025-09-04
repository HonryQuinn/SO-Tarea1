#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    const char *fifo_path = "./my_fifo2";

    int fd;
    int num;

    mkfifo(fifo_path, 0666);

    fd = open(fifo_path, O_RDONLY);

    read(fd, &num, sizeof(num));

    printf("su numero multiplicado por 100 es %d\n", num * 100);

    close(fd);
    unlink(fifo_path);

    return 0;
}