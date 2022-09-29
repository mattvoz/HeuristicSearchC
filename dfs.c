#include "overhead.h"
#include "dfs.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

searchNode * depthFirstSearch( searchNode * currentNode, int maxDepth, int * nodeCount, time_t startTime) {
    // safety check :)
    if( currentNode == NULL) {
        return NULL;
    }
    if(time(NULL)-startTime > 900){
        free(currentNode->state);
        free(currentNode);
        return NULL;
    }
    (*nodeCount)++;
    if(goalTest(currentNode)) {
        return currentNode;
    }
    if( currentNode->depth == maxDepth) {
        free(currentNode->state);
        free(currentNode);
        return NULL;
    }

    searchNode * right = depthFirstSearch(moveRight(currentNode), maxDepth, nodeCount, startTime);
    searchNode * left = depthFirstSearch(moveLeft(currentNode), maxDepth, nodeCount, startTime);
    searchNode * up = depthFirstSearch(moveUp(currentNode),maxDepth,nodeCount, startTime);
    searchNode * down = depthFirstSearch(moveDown(currentNode),maxDepth, nodeCount, startTime);

    if(right != NULL) {
        return right;
    } else if(left != NULL) {
        return left;
    } else if(up != NULL) {
        return up;
    }else if(down != NULL) {
        return down;
    } else {
        free(currentNode->state);
        free(currentNode);
        return NULL;
    }
    

}