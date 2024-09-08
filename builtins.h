#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int builtin_cd(char **args);
int builtin_help(char **args);
int builtin_exit(char **args);

//builtin commands
char *builtin_str[] = {
    "cd",
    "help",
    "exit"
};

//Corresponding Funtion
int (*builtin_func[]) (char**) = {
    &builtin_cd,
    &builtin_help,
    &builtin_exit
};

int num_builtins(){
    return sizeof(builtin_str)/sizeof(char *);
}

//Implementation for builtin functions

int builtin_cd(char **args) {
    if (args[1] == NULL){
        fprintf(stderr, "Lynx: expected argument to \"cd\" \n");
    
    }
    else {
        if(chdir(args[1]) != 0) {
            perror("Lynx");
        }
    }
    return 1;
}

int builtin_help(char **args) {
    printf("Ryzertron's Lynx Shell\n");
    printf("The following are the builtins implemented here :- \n");

    for(int i = 0; i < num_builtins(); i++){
        printf(" %s\n",builtin_str[i]);
    }

    printf("Use man command for info on other programs\n");
    return 1;
}

int builtin_exit(char **args) {
    return 0;
}
