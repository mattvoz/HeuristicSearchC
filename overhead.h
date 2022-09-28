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

typedef struct closedNode{
    char * state;
    int cost;
    struct closedNode * left;
    struct closedNode * right;
} closedNode;

typedef struct searchData {
    closedNode * closed;
    searchNode * fringe;
    long startTime;
    long endTime;
    int fringeSize;
    int closedSize;
} searchData;

char inClosed( searchNode *, searchData * );

char addToClosed( searchNode *, searchData *);

searchNode * popFringe();

char goalTest( searchNode *);

char inFringe( searchNode* , searchData *);

char compareNodesNoCost(searchNode * one, searchNode* two);

char compareNodesCost(searchNode * one, searchNode * two);

searchNode * createNode(char *, int, int);

searchNode * createInitialState( char * );

searchNode* moveUp(searchNode *, int);
searchNode* moveDown(searchNode *, int );
searchNode* moveRight(searchNode *, int );
searchNode* moveLeft(searchNode *, int );

int isSolvable( char * );

#endif