#include "overhead.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

searchNode * createNode( char * state, int cost, int openIndex, searchNode * parent, char move) {
    searchNode * newNode = malloc(sizeof(searchNode));
    if( newNode == NULL ) {
        printf("failed to create node \n");
        free(state);
        return NULL;
    }
    newNode->state = state;
    newNode->cost = cost;
    newNode->hcost = NULL;
    newNode->nextNode = NULL;
    newNode->open = openIndex;
    newNode->parent = parent;
    newNode->move = move;
    newNode->depth = parent->depth + 1;

    return newNode;
}

searchNode * createInitialState( char * filename ) {
    searchNode * node = malloc(sizeof(searchNode));
    if(!node) {
        return NULL;
    }
    FILE * f = fopen(filename, "r");
    if( !f ) {
        printf("Failed to find file with that name or path\n");
        exit(1);
    }

    char *stateString = malloc(sizeof(char) * 10);
    int index = 0;
    char character = fgetc(f);
    while( character != EOF && index < 9) {
        if( character != ' ' && character != '\n') {
            stateString[index] = character;
            if(character == '_') {
                node->open = index;
            }
            index++;
        }
        character = fgetc(f);
    }

    stateString[9] = '\0';

    node->state = stateString;
    node->nextNode = NULL;
    node->cost = 0;
    node->parent = NULL;
    node->depth = 0;

    return node;
}

/**
 * @brief 
 * 
 * @param prev 
 * @param hueristicCost 
 * @return * Shift* 
 */
searchNode * moveRight( searchNode * prev ) {
    char * newState = malloc(sizeof(char) * 10);
    newState = strcpy( newState, prev->state);

    if( prev->open == 0 || prev->open == 3 || prev->open == 6) {
        free(newState);
        return NULL;
    }

    newState[prev->open] = newState[prev->open-1];
    newState[prev->open -1] = '_';

    int cost = prev->cost + 1;

    return createNode(newState, cost, prev->open-1, prev, 'R');

}

searchNode * moveLeft( searchNode * prev) {
    char * newState = malloc(sizeof(char) * 10);
    newState = strcpy( newState, prev->state);

    if( prev->open == 2 || prev->open == 5 || prev->open == 8) {
        free(newState);
        return NULL;
    }

    newState[prev->open] = newState[prev->open+1];
    newState[prev->open + 1] = '_';

    int cost = prev->cost + 1;

    return createNode(newState, cost, prev->open+1, prev, 'L');
}

searchNode * moveUp( searchNode * prev) {
    char * newState = malloc(sizeof(char) * 10);
    newState = strcpy( newState, prev->state);

    if( prev->open == 6 || prev->open == 7 || prev->open == 8) {
        free(newState);
        return NULL;
    }

    newState[prev->open] = newState[prev->open+3];
    newState[prev->open + 3] = '_';

    int cost = prev->cost + 1;

    return createNode(newState, cost, prev->open+3, prev, 'U');
}

searchNode * moveDown( searchNode * prev) {
    char * newState = malloc(sizeof(char) * 10);
    newState = strcpy( newState, prev->state);

    if( prev->open == 0 || prev->open == 1 || prev->open == 2) {
        free(newState);
        return NULL;
    }

    newState[prev->open] = newState[prev->open-3];
    newState[prev->open - 3] = '_';

    int cost = prev->cost + 1;

    return createNode(newState, cost, prev->open-3, prev, 'D');
}

int isSolvable( char * string) {
    int inversions = 0;
    for(int i = 0; i < 9 ; i++) {
        for(int j=i; j < 9; j++ ) {
            if( string[i] > string[j] && string[i] != '_') {
                inversions += 1;
            }
        }
    }

    return inversions % 2;

}

char inClosed( searchNode * node, searchData * data ) {
    if( data->closed == NULL) {
        return 0;
    }
    closedNode * currentNode = data->closed;
    while(currentNode != NULL) {
        int value = strcmp(node->state, currentNode->state);
        if(value == 0) {
            return 1;
        } else if(value < 0) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }
    return 0;
}

char addToClosed( searchNode * node,  searchData * data) {
    closedNode* newNode = malloc(sizeof(closedNode));
       if(!newNode) {
            return 0;
       }
       newNode->state = node->state;
       newNode->left = NULL;
       newNode->right = NULL;

    if( data->closed == NULL) {
        data->closedSize += 1;
       data->closed = newNode;
       return 1;
    }

    closedNode * currentNode = data->closed;
    while(currentNode != NULL) {
        int value = strcmp(node->state, currentNode->state);
        if( value < 0) {
            if(currentNode->left == NULL){
                currentNode->left = newNode;
                data->closedSize += 1;
                return 1;
            }
            currentNode = currentNode->left;
        } else if( value > 0) {
            if (currentNode->right == NULL) {
                currentNode->right = newNode;
                data->closedSize += 1;
                return 1;
            }
            currentNode = currentNode->right;
        } else {
            return 0;
        }
    }
}

char goalTest(searchNode * node) {
    if( strcmp(node->state, "12345678_") == 0) {
        return 1;
    }
    return 0;
}

char inFringe(searchNode * node, searchData * data) {
    if( data->fringe == NULL) {
        return 0;
    }
    searchNode * current = data->fringe;

    while(current != NULL) {
        if(strcmp(node->state,current->state) == 0) {
            return 1;
        } 
        current = current->nextNode;
    }
}

char inFringeReplace(searchNode * node, searchData * data) {
    searchNode * currentNode = data->fringe;
    if( currentNode == NULL){
        return 0;
    }
    if( strcmp(node->state, currentNode->state) == 0 && (node->cost + node->hcost) < (currentNode->cost + currentNode->hcost)) {
        data->fringe = currentNode->nextNode;
    }
    searchNode * prevNode = currentNode;
    currentNode = prevNode->nextNode;
    while( currentNode != NULL) {
        if( strcmp(node->state, currentNode->state) == 0) {
            if((node->cost + node->hcost) < (currentNode->cost + currentNode->hcost)) {
                prevNode->nextNode = currentNode->nextNode;
                free(currentNode->state);
                free(currentNode);
                return 0;
            }else{
                return 1;
            }
        }
        prevNode = currentNode;
        currentNode = prevNode->nextNode;
    }
    return 0;
}

searchNode * fringePop( searchData * data ) {
    searchNode * pop = data->fringe;
    if( pop == NULL) {
        return NULL;
    }

    data->fringe = pop->nextNode;

    data->fringeSize -=1;

    return pop;
}