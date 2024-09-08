#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "builtins.h"

int launch(char **args){
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0){
        //Child Process using execvp for execute
        if(execvp(args[0],args) == -1){
            perror("Lynx");
        }
        exit(EXIT_FAILURE);
    }
    else if(pid < 0){
        //Fork Error
        perror("Lynx");
    }
    else {
        //Parent
        do{
            wpid = waitpid(pid, &status, WUNTRACED);
        }while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int execute(char **args){
    if (args[0] == NULL){
        //Empty command
        return 1;
    }

    for(int i = 0; i < num_builtins(); i++) {
        if (strcmp(args[0], builtin_str[i]) == 0) {
            return (*builtin_func[i])(args);
        }
    }
    
    //Application Launch
    return launch(args);
}



