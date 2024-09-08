#include <stdio.h>
#include "loop.h"
int main(int argc, char **argv) {
    // Load config files here, if any. I am not doing any config files.

    shell_loop();

    //Perform Shutdown or cleanup. Leaving it for future.

    return(EXIT_SUCCESS);
}