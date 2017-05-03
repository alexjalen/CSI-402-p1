p1: main.o insert.o stats.o
	gcc main.o insert.o stats.o -o p1
main.o: main.c headers.h treenode.h prototypes.h
	gcc -c main.c
insert.o: insert.c headers.h treenode.h
	gcc -c insert.c
stats.o: stats.c headers.h treenode.h
	gcc -c stats.c
clean:
	rm -f *.o core p1
