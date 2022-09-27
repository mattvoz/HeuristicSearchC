#include "bfs.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


char addToBreadthFringe(searchData * data, searchNode * node ) {
    //TODO check if it's in closed
    printf("adding to fringe :D\n");
    searchNode * currentNode = data->fringe;
    if( currentNode == NULL){
        printf("fringe is empty adding first node");
        data->fringe = node;
        return 1;
    }
    while(currentNode->nextNode != NULL ) {
        currentNode = currentNode->nextNode;
    }

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

    return pop;
}

searchNode * breadthFirstSearch( searchData * initial ) {
    int index = 0;
    while( initial->fringe != NULL) {
        printf("round %d", index);
        searchNode * current = breadthPop(initial);

        printf("current state is %s", current->state);

        if(breadthPop == NULL) {
            return NULL;
        }

        if( strcmp( current->state, "12345678_") == 0) {
            printf("equal :D \n");
            return current;
        }

        searchNode * right = moveRight(current,0);
        searchNode * left = moveLeft(current,0);
        searchNode * up = moveUp(current,0);
        searchNode * down = moveDown(current,0);

        printf("%d \n", down);

        if(right != NULL) {
            printf("right state %s\n", right->state);
            //addToBreadthFringe(initial,right);
        }
        if(left != NULL) {
            printf("left state %s\n", left->state);
            addToBreadthFringe(initial,left);
        }
        if(up != NULL) {
            printf("up state %s\n", up->state);
            addToBreadthFringe(initial,up);
        }
        if(down != NULL) {
            printf("down state %s\n", down->state);
            addToBreadthFringe(initial, down);
        }
        index ++;
    }

    return NULL;
}