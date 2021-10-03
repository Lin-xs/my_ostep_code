#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int
main()
{
    int x = 100;
    int pid = fork();
    if(pid == 0){
        printf("The origin value of x in child process is %d.\n", x);
        x = 500;
        printf("Now the value of x in child process is %d.\n", x);
    }else{
        wait(NULL);
        printf("Now the value in father is %d.\n", x);
        x = 600;
        printf("Now the value in father is %d.\n", x);
    }
    return 0;
}