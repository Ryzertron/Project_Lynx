#include <stdio.h>
#include <stdlib.h>
#include "readline.h"
#include "parser.h"
#include "executer.h"

void shell_loop(){
    char *line;
    char **args;
    int status;

    //Run once before status
    do{
        printf("»»» ");
        line = read_line();
        args = parse_line(line);
        status = execute(args);

        free(line);
        free(args);

    }while(status);
}