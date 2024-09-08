#include <stdio.h>
#include <stdlib.h>

#define BUFFERSIZE 1024

//We start with a predefined buffer size. If exeeded we will reallocate.
char *read_line(void){
    int bsize = BUFFERSIZE;
    int pos = 0;
    char *buffer = (char*)malloc(sizeof(char) * bsize);
    int c;

    //Mem Alloc Exception
    if (!buffer){
        fprintf(stderr, "Lynx: mem_allocation_error\n");
        exit(EXIT_FAILURE);
    }

    while(1){
        //storing character as INT because detection of EOF is int
        c = getchar();

        //EOF(Enf of File) or Enter Key or read complete
        if (c == EOF || c == '\n'){
            buffer[pos] = '\0';
            return buffer;
        }

        buffer[pos] = c;
        pos++;
    

        //Buffer size Exeeded
        if(pos >= bsize){
            //Exponential reallocation is avoided as it is not an average case senario.
            bsize += BUFFERSIZE;
            buffer = (char*)realloc(buffer,bsize);

            //Mem Alloc Exception
            if(!buffer){
                fprintf(stderr, "Lynx: mem_allocation_error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}


/*
getline() in stdlib can be used for a much shorter code.
I prefer more manual way for learning purposes. 
Anyway the getline() implementation is given below for reference.
*/

// char *read_line(void)
// {
//   char *line = NULL;
//   size_t bufsize = 0; // have getline allocate a buffer for us

//   if (getline(&line, &bufsize, stdin) == -1){
//     if (feof(stdin)) {
//       exit(EXIT_SUCCESS);  // We recieved an EOF
//     } else  {
//       perror("readline");
//       exit(EXIT_FAILURE);
//     }
//   }

//   return line;
// }