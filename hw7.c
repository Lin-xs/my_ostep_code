#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int
main()
{
    int pid = fork();
    if(pid == 0){
        close(STDOUT_FILENO);
        printf("What will happen?\n");
        exit(0);
    }
    wait(NULL);
    printf("return.\n");
    return 0;
}