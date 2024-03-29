COMPILER = gcc

OFLAG = -C

ONAMEFLAG = -C -O

search.exe:	overhead.o bfs.o dfs.o	aStar.o	main.c
	$(COMPILER) overhead.o bfs.o dfs.o aStar.o main.c -o search.exe
bfs:	bfs.c	overhead.o	bfs.h
	$(COMPILER) overhead.o bfs.c bfs.h $(OFLAG)
overhead:	overhead.c	overhead.h
	$(COMPILER) overhead.c overhead.h $(OFLAG)
dfs:	dfs.c	dfs.h	overhead.o 
	$(COMPILER) dfs.c dfs.h overhead.o $(OFLAG)
aStar:	aStar.h	aStar.c	overhead.o
	$(COMPILER) aStar.h aStar.c overhead.o $(OFLAG)

clean: 
	rm *.o