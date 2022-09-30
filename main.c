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
        searchOverhead->startTime = time(NULL);
        for(int i = 1; i < 50; i++) {
            initial = createInitialState( argv[1] );
            solution = depthFirstSearch( initial, i, &nodeCount, searchOverhead->startTime);
            if(solution != NULL){
                break;
            }
        }
        searchOverhead->endTime = time(NULL);
        
        searchOverhead->closedSize = nodeCount;
    }

    if(strcmp(argv[2], "h1") == 0) {
        printf(" h1 search\n");
        searchOverhead->startTime = time(NULL);
        solution = aStar( searchOverhead, &misplacedTile);
        searchOverhead->endTime = time(NULL);
    }

    if(strcmp(argv[2], "h2") == 0) {
        printf("h2 search\n");
        searchOverhead->startTime = time(NULL);
        solution = aStar( searchOverhead, &manhattanValue);
        searchOverhead->endTime = time(NULL);
    }

    if(strcmp(argv[2], "h3") == 0) {
        printf("h3 search\n");
        searchOverhead->startTime = time(NULL);
        solution = aStar( searchOverhead, &customHueristic);
        searchOverhead->endTime = time(NULL);
    }

    if(solution == NULL) {
        printf("Timeout\n");
        exit(1);
    }
    printf("time taken: %ld\n", searchOverhead->endTime - searchOverhead->startTime);
    printf("nodes explored %d\n", searchOverhead->closedSize + searchOverhead->fringeSize);
    printf("nodes in fringe %d\nNodes in closed %d\n", searchOverhead->fringeSize, searchOverhead->closedSize);
    printf("depth %d\n", solution->depth);
    printf("path: ");

    char * string = malloc(sizeof(solution->depth) + 1);
    string[solution->depth] = '\0';
    int index = solution->depth -1;
    while(solution->parent != NULL) {
        string[index] = solution->move;
        solution = solution->parent;
        index--;
    }
    printf("%s\n", string);
}