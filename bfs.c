#include "bfs.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


char addToBreadthFringe(searchData * data, searchNode * node) {
    //TODO check if it's in closed
    searchNode * currentNode = data->fringe;
    if( currentNode == NULL){
        data->fringe = node;
        data->fringeSize += 1;
        return 1;
    }
    while(currentNode->nextNode != NULL ) {
        currentNode = currentNode->nextNode;
    }
    data->fringeSize += 1;
    currentNode->nextNode = node;
    return 1;
}

searchNode * breadthPop( searchData * data ) {
    searchNode * pop = data->fringe;
    if( pop == NULL) {
        return NULL;
    }

    data->fringe = pop->nextNode;

    pop->nextNode = NULL;

    data->fringeSize -=1;

    return pop;
}

searchNode * breadthFirstSearch( searchData * initial ) {
    while( initial->fringe != NULL) {
        searchNode * current = breadthPop(initial);
        if(breadthPop == NULL) {
            return NULL;
        }

        addToClosed( current, initial);

        searchNode * right = moveRight(current,0);
        searchNode * left = moveLeft(current,0);
        searchNode * up = moveUp(current,0);
        searchNode * down = moveDown(current,0);

        if(right != NULL && inClosed( right, initial) != 1 && inFringe(right, initial) != 1) {
            if(goalTest(right)) {
                return right;
            }
            addToBreadthFringe(initial,right);
        }
        if(left != NULL && inClosed( left, initial) != 1 && inFringe(left, initial) != 1) {
            if(goalTest(left)) {
                return left;
            }
            addToBreadthFringe(initial,left);
        }
        if(up != NULL && inClosed( up, initial) != 1 && inFringe(up, initial) != 1) {
            if(goalTest(up)) {
                return up;
            }
            addToBreadthFringe(initial,up);
        }
        if(down != NULL && inClosed(down, initial) != 1 && inFringe(down, initial) != 1) {
            if(goalTest(down)) {
                return down;
            }
            addToBreadthFringe(initial, down);
        }
    }

    return NULL;
}