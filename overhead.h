#ifndef SEARCH_OVERHEAD

#define SEARCH_OVERHEAD

#include <time.h>

typedef struct searchNode {
    char * state;
    int cost;
    int open;
    char * moves;
    struct searchNode * nextNode;
} searchNode;

typedef struct searchData {
    searchNode * closed;
    searchNode * fringe;
    long startTime;
    long endTime;
    int fringeSize;
    int closedSize;
} searchData;

searchNode * popFringe();

char compareNodesNoCost(searchNode * one, searchNode* two);

char compareNodesCost(searchNode * one, searchNode * two);

searchNode * createNode(char *, int, int);

searchNode * createInitialState( char * );

searchNode* moveUp(searchNode *, int);
searchNode* moveDown(searchNode *, int );
searchNode* moveRight(searchNode *, int );
searchNode* moveLeft(searchNode *, int );

#endif