#include "overhead.h"
#include "dfs.h"
#include <stdlib.h>
#include <stdio.h>

searchNode * depthFirstSearch( searchNode * currentNode, int maxDepth, int * nodeCount) {
    // safety check :)
    if( currentNode == NULL) {
        return NULL;
    }
    (*nodeCount)++;
    printf("explored %d nodes\n", *nodeCount);
    if(goalTest(currentNode)) {
        return currentNode;
    }
    if( currentNode->depth == maxDepth) {
        free(currentNode->state);
        free(currentNode);
        return NULL;
    }

    searchNode * right = depthFirstSearch(moveRight(currentNode), maxDepth, nodeCount);
    searchNode * left = depthFirstSearch(moveLeft(currentNode), maxDepth, nodeCount);
    searchNode * up = depthFirstSearch(moveUp(currentNode),maxDepth,nodeCount);
    searchNode * down = depthFirstSearch(moveDown(currentNode),maxDepth, nodeCount);

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