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

        if(right != NULL && inClosed( right, initial) != 1 && inFringe(right, initial) != 1) {
            if(goalTest(right)) {
                return right;
            }
            addToAStarFringe(initial,right);
        }
        if(left != NULL && inClosed( left, initial) != 1 && inFringe(left, initial) != 1) {
            if(goalTest(left)) {
                return left;
            }
            addToAStarFringe(initial,left);
        }
        if(up != NULL && inClosed( up, initial) != 1 && inFringe(up, initial) != 1) {
            if(goalTest(up)) {
                return up;
            }
            addToAStarFringe(initial,up);
        }
        if(down != NULL && inClosed(down, initial) != 1 && inFringe(down, initial) != 1) {
            if(goalTest(down)) {
                return down;
            }
            addToAStarFringe(initial, down);
        }

}

char addToAStarFringe(searchNode * node, searchData * data) {
    searchNode * currentNode = data->fringe;
    if( currentNode == NULL){
        data->fringe = node;
        data->fringeSize += 1;
        return 1;
    }

    if( node->cost < currentNode->cost) {
        data->fringe = node;
        node->nextNode = currentNode;
        return 1;
    }

    searchNode * prevNode = currentNode;
    currentNode = prevNode->next;

    while(currentNode != NULL) {
        if( node->cost < currentNode->cost) {
            prevNode->nextNode = node;
            node->nextNode = currentNode;
            return 1;
        }
        currentNode = currentNode->nextNode;
    }
    prevNode->nextnode = node;
    return 1;

}
