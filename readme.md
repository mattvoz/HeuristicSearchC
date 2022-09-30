Lab 1 coms472 by matthew vozenilek

all implementations are in their respective files

bfs.c = breadth first search

dfs = IDFS

aStar.c = A* and all huersitcs


My custom hueristic is a sort of straight line/ radius search if it's within 1 tile add 1 if it's straight line value is 2 add 2 to cost.

DFS is only recursive with no checks for infiniite branches since it didn't seem to specify it was required.


to run type make to regenerate search.exe 

the command line format is 

./search.exe "filename/filepath" algo

algo can take values BFS IDFS h1 h2 h3