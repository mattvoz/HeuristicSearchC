#include "overhead.h"
#include "bfs.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char ** argv) {
    if( argc < 2 ) {
        printf("please specify an input file \n");
        exit(1);
    }
    searchNode * initial = createInitialState(argv[1]);

    searchData * searchOverhead = malloc(sizeof(searchData));

    searchOverhead->fringe = initial;

    printf("%s\n", initial->state);

    searchNode * hi = breadthFirstSearch(searchOverhead);

    printf("%s", hi->state);
}