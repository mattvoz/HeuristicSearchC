#ifndef __ASTAR__
#define __ASTAR__
#include "overhead.h"

searchNode * aStar(searchData *, int (hueristic)( searchNode *));

char addToAStarFringe(searchNode *, searchData *);

#endif