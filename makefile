COMPILER = gcc

OFLAG = -C

ONAMEFLAG = -C -O

search.exe:	overhead.o breadthFirst.o
	$(COMPILER) overhead.o main.c -o test.exe

breadthFirst: breadthFirst.c overhead.o breadthFirst.h
	$(COMPILER) overhead.o breadthFirst.c breadthFirst.h $(OFLAG)

overhead:	overhead.c	overhead.h
	$(COMPILER) overhead.c overhead.h $(OFLAG)

clean: 
	rm *.o