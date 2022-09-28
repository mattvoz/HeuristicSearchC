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

    int possible = isSolvable(initial->state);

    if( possible == 1 ) {
        printf("puzzle is not solvable \n");
        exit(1);
    }

    searchData * searchOverhead = malloc(sizeof(searchData));

    searchOverhead->fringe = initial;
    searchOverhead->closed = NULL;
    searchOverhead->closedSize = 0;
    searchOverhead->fringeSize = 0;

    searchNode * hi = breadthFirstSearch(searchOverhead);

    printf("final closed size %d\n final fringe size %d\n", searchOverhead->closedSize, searchOverhead->fringeSize);

    printf("%s\n", hi->state);
}