COMPILER = gcc

OFLAG = -C

ONAMEFLAG = -C -O

search.exe:	overhead.o bfs.o
	$(COMPILER) overhead.o bfs.o main.c -o test.exe

bfs: bfs.c overhead.o bfs.h
	$(COMPILER) overhead.o bfs.c bfs.h $(OFLAG)

overhead:	overhead.c	overhead.h
	$(COMPILER) overhead.c overhead.h $(OFLAG)

clean: 
	rm *.o