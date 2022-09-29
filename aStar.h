#ifndef __ASTAR__
#define __ASTAR__
#include "overhead.h"

searchNode * aStar(searchData *, int (hueristic)( searchNode *));

char addToAStarFringe(searchNode *, searchData *);

int manhattanValue( searchNode * );
int misplacedTile( searchNode * );
int customHueristic( searchNode *);

#endif