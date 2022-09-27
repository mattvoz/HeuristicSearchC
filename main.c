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
    printf("this puzzle is solvable if 0 %d \n", possible);

    if( possible == 1 ) {
        printf("puzzle is not solvable \n");
        exit(1);
    }

    searchData * searchOverhead = malloc(sizeof(searchData));

    searchOverhead->fringe = initial;

    printf("%s\n", initial->state);

    searchNode * hi = breadthFirstSearch(searchOverhead);

    printf("%s", hi->state);
}