#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int 
main(){
    int pid = fork();
    if(pid == 0){
        int ret = wait(NULL);
        printf("The return value of wait in child is: %d.\n", ret);
        exit(0);
    }
    int ret = wait(NULL);
    printf("child's pid = %d, In father, ret = %d.\n", pid, ret);
    return 0;
}