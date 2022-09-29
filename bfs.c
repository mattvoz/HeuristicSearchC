#include "bfs.h"
#include "overhead.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>


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

searchNode * breadthFirstSearch( searchData * initial ) {
    initial->startTime = time(NULL);
    while( initial->fringe != NULL) {
        searchNode * current = fringePop(initial);
        if(current == NULL) {
            return NULL;
        }

        addToClosed( current, initial);

        searchNode * right = moveRight(current,0);
        searchNode * left = moveLeft(current,0);
        searchNode * up = moveUp(current,0);
        searchNode * down = moveDown(current,0);

        if(right != NULL && inClosed( right, initial) != 1 && inFringe(right, initial) != 1) {
            if(goalTest(right)) {
                initial->endTime = time(NULL);
                return right;
            }
            addToBreadthFringe(initial,right);
        }
        if(left != NULL && inClosed( left, initial) != 1 && inFringe(left, initial) != 1) {
            if(goalTest(left)) {
                initial->endTime = time(NULL);
                return left;
            }
            addToBreadthFringe(initial,left);
        }
        if(up != NULL && inClosed( up, initial) != 1 && inFringe(up, initial) != 1) {
            if(goalTest(up)) {
                initial->endTime = time(NULL);
                return up;
            }
            addToBreadthFringe(initial,up);
        }
        if(down != NULL && inClosed(down, initial) != 1 && inFringe(down, initial) != 1) {
            if(goalTest(down)) {
                initial->endTime = time(NULL);
                return down;
            }
            addToBreadthFringe(initial, down);
        }
    }

    return NULL;
}