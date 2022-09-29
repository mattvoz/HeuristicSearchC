#ifndef SEARCH_OVERHEAD

#define SEARCH_OVERHEAD

#include <time.h>

typedef struct searchNode {
    time_t startTime;
    time_t endTime;
    char * state;
    char move;
    int cost;
    int hcost;
    int open;
    int depth;
    char * moves;
    struct searchNode * nextNode;
    struct searchnode * parent;
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

char goalTest( searchNode *);

char inFringe( searchNode* , searchData *);
char inFringeReplace(searchNode *, searchData *);

char compareNodesNoCost(searchNode * one, searchNode* two);

char compareNodesCost(searchNode * one, searchNode * two);

searchNode * createNode(char *, int, int, searchNode *, char);

searchNode * createInitialState( char * );

searchNode * fringePop( searchData * );

searchNode* moveUp(searchNode *);
searchNode* moveDown(searchNode * );
searchNode* moveRight(searchNode * );
searchNode* moveLeft(searchNode * );

int isSolvable( char * );

#endif