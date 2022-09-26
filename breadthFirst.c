#include "bfs.h"
#include <stdlib.h>


char addToBreadthFringe(searchData * data, searchNode * node ) {
    searchNode * currentNode = data->fringe;
    if( currentNode == NULL){
        data->fringe = node;
    }
    while(currentNode->nextNode != NULL ) {
        currentNode = currentNode->nextNode;
    }

    currentNode->nextNode = node;
}

searchNode * breadthPop( searchData * data ) {
    searchNode * pop = data->fringe;
    if( pop == NULL) {
        return NULL;
    }

    data->fringe = pop->nextNode;

    pop->nextNode = NULL;

    return pop;
}

searchNode * breadthFirstSearch( searchData * initial ) {
    searchNode * current = breadthPop(initial);
    while( current != NULL) {
        
    }

    return NULL;
}