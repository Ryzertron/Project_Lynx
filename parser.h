#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOKEN_BUFSIZE 64
#define TOKEN_DELIM " \t\r\n\a"

char **parse_line(char *line){

    int bsize = TOKEN_BUFSIZE;
    int pos = 0;

    char **tokens = (char**)malloc(bsize * sizeof(char));
    char *token;

    if(!tokens){
        fprintf(stderr, "Lynx: mem_allocation_error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOKEN_DELIM);
    while(token != NULL){
        tokens[pos] = token;
        pos++;

        if(pos >= bsize){
            bsize += TOKEN_BUFSIZE;
            tokens = (char**)realloc(tokens, bsize * sizeof(char));
            if (!tokens){
                fprintf(stderr, "Lynx: mem_allocation_error");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOKEN_DELIM);
    }

    tokens[pos] = NULL;
    return tokens;

}