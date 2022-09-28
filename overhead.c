#include "overhead.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

searchNode * createNode( char * state, int cost, int openIndex) {
    searchNode * newNode = malloc(sizeof(searchNode));
    if( newNode == NULL ) {
        printf("failed to create node \n");
        return NULL;
    }
    newNode->state = state;
    newNode->cost = cost;
    newNode->nextNode = NULL;
    newNode->open = openIndex;

    return newNode;
}

searchNode * createInitialState( char * filename ) {
    searchNode * node = malloc(sizeof(searchNode));
    if(!node) {
        return NULL;
    }

    printf("%s \n", filename);
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
}

/**
 * @brief 
 * 
 * @param prev 
 * @param hueristicCost 
 * @return * Shift* 
 */
searchNode * moveRight( searchNode * prev, int hueristicCost ) {
    char * newState = malloc(sizeof(char) * 10);
    newState = strcpy( newState, prev->state);

    if( prev->open == 0 || prev->open == 3 || prev->open == 6) {
        return NULL;
    }

    newState[prev->open] = newState[prev->open-1];
    newState[prev->open -1] = '_';

    int cost = prev->cost + 1 + hueristicCost;

    return createNode(newState, cost, prev->open-1);

}

searchNode * moveLeft( searchNode * prev, int hueristicCost) {
    char * newState = malloc(sizeof(char) * 10);
    newState = strcpy( newState, prev->state);

    if( prev->open == 2 || prev->open == 5 || prev->open == 8) {
        return NULL;
    }

    newState[prev->open] = newState[prev->open+1];
    newState[prev->open + 1] = '_';

    int cost = prev->cost + 1 + hueristicCost;

    return createNode(newState, cost, prev->open+1);
}

searchNode * moveUp( searchNode * prev, int hueristicCost) {
    char * newState = malloc(sizeof(char) * 10);
    newState = strcpy( newState, prev->state);

    if( prev->open == 6 || prev->open == 7 || prev->open == 8) {
        return NULL;
    }

    newState[prev->open] = newState[prev->open+3];
    newState[prev->open + 3] = '_';

    int cost = prev->cost + 1 + hueristicCost;

    return createNode(newState, cost, prev->open+3);
}

searchNode * moveDown( searchNode * prev, int hueristicCost) {
    char * newState = malloc(sizeof(char) * 10);
    newState = strcpy( newState, prev->state);

    if( prev->open == 0 || prev->open == 1 || prev->open == 2) {
        return NULL;
    }

    newState[prev->open] = newState[prev->open-3];
    newState[prev->open - 3] = '_';

    int cost = prev->cost + 1 + hueristicCost;

    return createNode(newState, cost, prev->open-3);
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
        int value = strcmp(node->state, currentNode->node->state);
        if(value == 0) {
            return 1;
        }
        if(value < 0) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }
    return 0;
}

char addToClosed( searchNode * node,  searchData * data) {
    printf("adding to closed\n");
    closedNode* newNode = malloc(sizeof(closedNode));
       if(!newNode) {
            printf("failed to allocate closed node\n");
            return 0;
       }
       newNode->node = node;
       newNode->left = NULL;
       newNode->right = NULL;

    if( data->closed == NULL) {
       data->closed = newNode;
       return 1;
    }

    closedNode * currentNode = data->closed;
    while(currentNode != NULL) {
        int value = strcmp(node->state, currentNode->node->state);
        if( value < 0) {
            if(currentNode->left == NULL){
                currentNode->left = newNode;
                return 1;
            }
            currentNode = currentNode->left;
        } else {
            if (currentNode->right == NULL) {
                currentNode->right = newNode;
                return 1;
            }
            currentNode = currentNode->right;
        }
    }
}