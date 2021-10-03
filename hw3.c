#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int pipefd[2];
    pipe(pipefd);
    int pid = fork();
    if(pid == 0){
        close(pipefd[0]);//关闭管道读口
        printf("hello\n");
        char *buf = "a";
        write(pipefd[1], buf, 1);
        close(pipefd[1]);
        exit(0);
    }
    close(pipefd[1]);
    char *buf = (char *)malloc(1);
    read(pipefd[0], buf, 1);
    close(pipefd[0]);
    printf("goodbye.\n");
    return 0;
}