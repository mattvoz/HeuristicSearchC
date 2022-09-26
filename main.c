#include "overhead.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char ** argv) {
    if( argc < 2 ) {
        printf("please specify an input file \n");
        exit(1);
    }
    searchNode * initial = createInitialState(argv[1]);

    printf("%s", initial->state);
}