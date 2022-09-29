#include "aStar.h"
#include "overhead.h"
#include "stdlib.h"
#include <stdio.h>

searchNode * aStar( searchData * initial, int (hueristic)( searchNode *)) {
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

        if(right != NULL && inClosed( right, initial) != 1 && inFringeReplace(right, initial) != 1) {
            addToAStarFringe(right,initial);
        }
        if(left != NULL && inClosed( left, initial) != 1 && inFringeReplace(left, initial) != 1) {
            addToAStarFringe(left,initial);
        }
        if(up != NULL && inClosed( up, initial) != 1 && inFringeReplace(up, initial) != 1) {
            addToAStarFringe(up,initial);
        }
        if(down != NULL && inClosed(down, initial) != 1 && inFringeReplace(down, initial) != 1) {
            addToAStarFringe(down, initial);
        }
    }
}

char addToAStarFringe(searchNode * node, searchData * data) {
    searchNode * currentNode = data->fringe;
    if( currentNode == NULL){
        data->fringe = node;
        data->fringeSize += 1;
        return 1;
    }

    if(node->cost < currentNode->cost) {
        data->fringe = node;
        node->nextNode = currentNode;
        return 1;
    }

    searchNode * prevNode = currentNode;
    currentNode = prevNode->nextNode;

    while(currentNode != NULL) {
        if( node->cost < currentNode->cost) {
            prevNode->nextNode = node;
            node->nextNode = currentNode;
            return 1;
        }
        currentNode = currentNode->nextNode;
    }
    prevNode->nextNode = node;
    return 1;
}

int manhattanValue( searchNode * node) {
    int cost = 0;
    for(char i = 0; i < 9; i ++) {
        char current = node->state[i];
        if( current == '_') {
            continue;
        }
        int intVal = atoi( & current);

    }
    return cost;
}

int misplacedTile( searchNode * node) {
    int cost = 0;
        for(char i = 0; i < 9; i++) {
            char current = node->state[i];
            if( current == '_') {
              continue;
            }
            int intVal = atoi( &current);
            if( intVal != i+1) {
                cost+=1;
            }
    }
    return cost;
}