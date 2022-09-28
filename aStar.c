#include "aStar.h"
#include "overhead.h"

searchNode * aStar( searchData *, int (hueristic)( searchNode *)) {
     while( initial->fringe != NULL) {
        searchNode * current = breadthPop(initial);
        printf("Current state %s\n", current->state);
        if(breadthPop == NULL) {
            return NULL;
        }

        addToClosed( current, initial);

        searchNode * right = moveRight(current,0);
        searchNode * left = moveLeft(current,0);
        searchNode * up = moveUp(current,0);
        searchNode * down = moveDown(current,0);

}

char addToAStarFringe(searchNode * node, searchData * data) {
    searchNode * currentNode = data->fringe;
    if( currentNode == NULL){
        data->fringe = node;
        data->fringeSize += 1;
        return 1;
    }
    while(currentNode->nextNode != NULL && currentNode->nextNode->cost < node->cost ) {
        currentNode = currentNode->nextNode;
    }
    data->fringeSize += 1;
    currentNode->nextNode = node;
    return 1;
}