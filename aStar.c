#include "aStar.h"
#include "overhead.h"
#include "stdlib.h"
#include <stdio.h>

searchNode * aStar( searchData * initial, int (hueristic)( searchNode *)) {
     while( initial->fringe != NULL) {
        searchNode * current = fringePop(initial);
        if(current == NULL) {
            return NULL;
        }

        if(goalTest(current) == 1) {
            return current;
        }

        addToClosed( current, initial);

        searchNode * right = moveRight(current);
        if( right != NULL) {
            right->hcost = hueristic(right);
        }

        searchNode * left = moveLeft(current);
        if( left != NULL) {
            left->hcost = hueristic(left);
        }

        searchNode * up = moveUp(current);
        if( up != NULL) {
            up->hcost = hueristic(up);
        }

        searchNode * down = moveDown(current);
        if(down != NULL) {
            down->hcost = hueristic(down);
        }

        if(right != NULL && inClosed( right, initial) != 1 && inFringeReplace(right, initial) != 1) {
            addToAStarFringe(right,initial);
        }
        if(left != NULL && inClosed( left, initial) != 1 && inFringeReplace(left, initial) != 1) {
            addToAStarFringe(left,initial);
        }
        if(up != NULL && inClosed( up, initial) != 1 && inFringeReplace(up, initial) != 1) {
            addToAStarFringe(up,initial);
        }
        if(down != NULL && inClosed(down, initial) != 1 && inFringeReplace(down, initial) != 1) {
            addToAStarFringe(down, initial);
        }
    }
}

char addToAStarFringe(searchNode * node, searchData * data) {
    searchNode * currentNode = data->fringe;
    if( currentNode == NULL){
        data->fringe = node;
        data->fringeSize += 1;
        return 1;
    }

    if((node->cost + node->hcost) < (currentNode->cost + currentNode->hcost)) {
        data->fringe = node;
        node->nextNode = currentNode;
        data->fringeSize += 1;
        return 1;
    }

    searchNode * prevNode = currentNode;
    currentNode = prevNode->nextNode;

    while(currentNode != NULL) {
        if( (node->cost + node->hcost) < (currentNode->cost + currentNode->hcost)) {
            prevNode->nextNode = node;
            node->nextNode = currentNode;
            data->fringeSize += 1;
            return 1;
        }
        prevNode = currentNode;
        currentNode = currentNode->nextNode;
    }
    prevNode->nextNode = node;
    data->fringeSize += 1;
    return 1;
}

int manhattanValue( searchNode * node) {
    int cost = 0;
    for(char i = 0; i < 9; i ++) {
        char current = node->state[i];
            switch(current) {
                case '_':
                    switch(i) {
                        case 0: 
                            cost += 4;
                            break;
                        case 1:
                            cost+=3;
                            break;
                        case 2:
                            cost+=2;
                            break;
                        case 3:
                            cost+=3;
                            break;
                        case 4:
                            cost+=2;
                            break;
                        case 5:
                            cost+=1;
                            break;
                        case 6:
                            cost+=2;
                            break;
                        case 7:
                            cost+=1;
                            break;
                        case 8:
                            cost +=0;
                            break;
                        default:
                            break;
                    }
                    break;
                case '1':
                    switch(i) {
                        case 0: 
                            cost += 0;
                            break;
                        case 1:
                            cost+=1;
                            break;
                        case 2:
                            cost+=2;
                            break;
                        case 3:
                            cost+=1;
                            break;
                        case 4:
                            cost+=2;
                            break;
                        case 5:
                            cost+=3;
                            break;
                        case 6:
                            cost+=2;
                            break;
                        case 7:
                            cost+=3;
                            break;
                        case 8:
                            cost +=4;
                            break;
                        default:
                            break;
                    }
                    break;
                case '2': 
                    switch(i) {
                        case 0: 
                            cost += 1;
                            break;
                        case 1:
                            cost+=0;
                            break;
                        case 2:
                            cost+=1;
                            break;
                        case 3:
                            cost+=2;
                            break;
                        case 4:
                            cost+=1;
                            break;
                        case 5:
                            cost+=2;
                            break;
                        case 6:
                            cost+=3;
                            break;
                        case 7:
                            cost+=2;
                            break;
                        case 8:
                            cost +=3;
                            break;
                        default:
                            break;
                    }
                    break;
                case '3':
                    switch(i) {
                        case 0: 
                            cost += 2;
                            break;
                        case 1:
                            cost+=1;
                            break;
                        case 2:
                            cost+=0;
                            break;
                        case 3:
                            cost+=3;
                            break;
                        case 4:
                            cost+=2;
                            break;
                        case 5:
                            cost+=1;
                            break;
                        case 6:
                            cost+=4;
                            break;
                        case 7:
                            cost+=3;
                            break;
                        case 8:
                            cost +=2;
                            break;
                        default:
                            break;
                    }
                    break;
                case '4':
                    switch(i) {
                        case 0: 
                            cost += 1;
                            break;
                        case 1:
                            cost+=2;
                            break;
                        case 2:
                            cost+=3;
                            break;
                        case 3:
                            cost+=0;
                            break;
                        case 4:
                            cost+=1;
                            break;
                        case 5:
                            cost+=2;
                            break;
                        case 6:
                            cost+=1;
                            break;
                        case 7:
                            cost+=2;
                            break;
                        case 8:
                            cost +=3;
                            break;
                        default:
                            break;
                    }
                    break;
                case '5':
                    switch(i) {
                        case 0: 
                            cost += 2;
                            break;
                        case 1:
                            cost+=1;
                            break;
                        case 2:
                            cost+=2;
                            break;
                        case 3:
                            cost+=1;
                            break;
                        case 4:
                            cost+=0;
                            break;
                        case 5:
                            cost+=1;
                            break;
                        case 6:
                            cost+=2;
                            break;
                        case 7:
                            cost+=1;
                            break;
                        case 8:
                            cost +=2;
                            break;
                        default:
                            break;
                    }
                    break;
                case '6':
                    switch(i) {
                        case 0: 
                            cost += 3;
                            break;
                        case 1:
                            cost+=2;
                            break;
                        case 2:
                            cost+=1;
                            break;
                        case 3:
                            cost+=2;
                            break;
                        case 4:
                            cost+=1;
                            break;
                        case 5:
                            cost+=0;
                            break;
                        case 6:
                            cost+=3;
                            break;
                        case 7:
                            cost+=2;
                            break;
                        case 8:
                            cost +=1;
                            break;
                        default:
                            break;
                    }
                    break;
                case '7':
                    switch(i) {
                        case 0: 
                            cost += 2;
                            break;
                        case 1:
                            cost+=3;
                            break;
                        case 2:
                            cost+=4;
                            break;
                        case 3:
                            cost+=1;
                            break;
                        case 4:
                            cost+=2;
                            break;
                        case 5:
                            cost+=3;
                            break;
                        case 6:
                            cost+=0;
                            break;
                        case 7:
                            cost+=1;
                            break;
                        case 8:
                            cost +=2;
                            break;
                        default:
                            break;
                    }
                    break;
                case '8':
                    switch(i) {
                        case 0: 
                            cost += 3;
                            break;
                        case 1:
                            cost+=2;
                            break;
                        case 2:
                            cost+=3;
                            break;
                        case 3:
                            cost+=2;
                            break;
                        case 4:
                            cost+=1;
                            break;
                        case 5:
                            cost+=2;
                            break;
                        case 6:
                            cost+=1;
                            break;
                        case 7:
                            cost+=0;
                            break;
                        case 8:
                            cost +=1;
                            break;
                        default:
                            break;
                    }
                    break;
                
            }
    }
    return cost;
}

int misplacedTile( searchNode * node) {
    int cost = 0;
        for(char i = 0; i < 9; i++) {
            char current = node->state[i];
            if( current == '_') {
                if( i != 8) {
                    cost += 1;
                }
              continue;
            }
            int intVal = atoi( &current);
            if( intVal != i+1) {
                cost+=1;
            }
    }
    return cost;
}

int customHueristic(searchNode * node) {
    int cost = 0;
    for(char i = 0; i < 9; i ++) {
        char current = node->state[i];
            switch(current) {
                case '_':
                    switch(i) {
                        case 0: 
                            cost += 2;
                            break;
                        case 1:
                            cost+=2;
                            break;
                        case 2:
                            cost+=2;
                            break;
                        case 3:
                            cost+=2;
                            break;
                        case 4:
                            cost+=1;
                            break;
                        case 5:
                            cost+=1;
                            break;
                        case 6:
                            cost+=2;
                            break;
                        case 7:
                            cost+=1;
                            break;
                        case 8:
                            cost +=0;
                            break;
                        default:
                            break;
                    }
                    break;
                case '1':
                    switch(i) {
                        case 0: 
                            cost += 0;
                            break;
                        case 1:
                            cost+=1;
                            break;
                        case 2:
                            cost+=2;
                            break;
                        case 3:
                            cost+=1;
                            break;
                        case 4:
                            cost+=1;
                            break;
                        case 5:
                            cost+=2;
                            break;
                        case 6:
                            cost+=2;
                            break;
                        case 7:
                            cost+=2;
                            break;
                        case 8:
                            cost +=2;
                            break;
                        default:
                            break;
                    }
                    break;
                case '2': 
                    switch(i) {
                        case 0: 
                            cost += 1;
                            break;
                        case 1:
                            cost+=0;
                            break;
                        case 2:
                            cost+=1;
                            break;
                        case 3:
                            cost+=1;
                            break;
                        case 4:
                            cost+=1;
                            break;
                        case 5:
                            cost+=1;
                            break;
                        case 6:
                            cost+=2;
                            break;
                        case 7:
                            cost+=2;
                            break;
                        case 8:
                            cost +=2;
                            break;
                        default:
                            break;
                    }
                    break;
                case '3':
                    switch(i) {
                        case 0: 
                            cost += 2;
                            break;
                        case 1:
                            cost+=1;
                            break;
                        case 2:
                            cost+=0;
                            break;
                        case 3:
                            cost+=2;
                            break;
                        case 4:
                            cost+=1;
                            break;
                        case 5:
                            cost+=1;
                            break;
                        case 6:
                            cost+=2;
                            break;
                        case 7:
                            cost+=2;
                            break;
                        case 8:
                            cost +=2;
                            break;
                        default:
                            break;
                    }
                    break;
                case '4':
                    switch(i) {
                        case 0: 
                            cost += 1;
                            break;
                        case 1:
                            cost+=1;
                            break;
                        case 2:
                            cost+=2;
                            break;
                        case 3:
                            cost+=0;
                            break;
                        case 4:
                            cost+=1;
                            break;
                        case 5:
                            cost+=2;
                            break;
                        case 6:
                            cost+=1;
                            break;
                        case 7:
                            cost+=1;
                            break;
                        case 8:
                            cost +=2;
                            break;
                        default:
                            break;
                    }
                    break;
                case '5':
                    switch(i) {
                        case 0: 
                            cost += 1;
                            break;
                        case 1:
                            cost+=1;
                            break;
                        case 2:
                            cost+=1;
                            break;
                        case 3:
                            cost+=1;
                            break;
                        case 4:
                            cost+=0;
                            break;
                        case 5:
                            cost+=1;
                            break;
                        case 6:
                            cost+=1;
                            break;
                        case 7:
                            cost+=1;
                            break;
                        case 8:
                            cost +=1;
                            break;
                        default:
                            break;
                    }
                    break;
                case '6':
                    switch(i) {
                        case 0: 
                            cost += 2;
                            break;
                        case 1:
                            cost+=1;
                            break;
                        case 2:
                            cost+=1;
                            break;
                        case 3:
                            cost+=2;
                            break;
                        case 4:
                            cost+=1;
                            break;
                        case 5:
                            cost+=0;
                            break;
                        case 6:
                            cost+=2;
                            break;
                        case 7:
                            cost+=1;
                            break;
                        case 8:
                            cost +=1;
                            break;
                        default:
                            break;
                    }
                    break;
                case '7':
                    switch(i) {
                        case 0: 
                            cost += 2;
                            break;
                        case 1:
                            cost+=2;
                            break;
                        case 2:
                            cost+=2;
                            break;
                        case 3:
                            cost+=1;
                            break;
                        case 4:
                            cost+=1;
                            break;
                        case 5:
                            cost+=2;
                            break;
                        case 6:
                            cost+=0;
                            break;
                        case 7:
                            cost+=1;
                            break;
                        case 8:
                            cost +=2;
                            break;
                        default:
                            break;
                    }
                    break;
                case '8':
                    switch(i) {
                        case 0: 
                            cost += 2;
                            break;
                        case 1:
                            cost+=2;
                            break;
                        case 2:
                            cost+=2;
                            break;
                        case 3:
                            cost+=1;
                            break;
                        case 4:
                            cost+=1;
                            break;
                        case 5:
                            cost+=1;
                            break;
                        case 6:
                            cost+=1;
                            break;
                        case 7:
                            cost+=0;
                            break;
                        case 8:
                            cost +=1;
                            break;
                        default:
                            break;
                    }
                    break;
                
            }
    }
    return cost;
}