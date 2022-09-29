#include "overhead.h"
#include "bfs.h"
#include "dfs.h"
#include "aStar.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char ** argv) {
    if( argc < 2 ) {
        printf("please specify an input file \n");
        exit(1);
    }
    if( argc < 3) {
        printf("please specify an algorithm\n");
        exit(1);
    }

    searchNode * initial = createInitialState(argv[1]);

    int possible = isSolvable(initial->state);
    if( possible == 1 ) {
        printf("puzzle is not solvable \n");
        free(initial->state);
        free(initial);
        exit(1);
    }

    searchNode * solution;

    searchData * searchOverhead = malloc(sizeof(searchData));
    searchOverhead->fringe = initial;
    searchOverhead->closed = NULL;
    searchOverhead->closedSize = 0;
    searchOverhead->fringeSize = 0;

    if(strcmp(argv[2], "BFS") == 0) {
        printf("BFS\n");
        solution = breadthFirstSearch(searchOverhead);
    }

    if(strcmp(argv[2], "IDFS") == 0) {
        int nodeCount;
        for(int i = 1; i < 12; i++) {
            initial = createInitialState( argv[1] );
            solution = depthFirstSearch( initial, i, &nodeCount);
            if(solution != NULL){
                break;
            }
        }
    }

    if(strcmp(argv[2], "h1") == 0) {
        printf(" h1 search\n");
        searchNode * solution = aStar( searchOverhead, &misplacedTile);
    }

    if(solution == NULL) {
        printf("no solution was found\n");
        exit(1);
    }
    printf("final closed size %d\nfinal fringe size %d\nsolution depth %d\nend time %ld\nend time %ld\n", searchOverhead->closedSize, searchOverhead->fringeSize, solution->depth, solution->endTime, solution->startTime);

    printf("%s\n", solution->state);
}