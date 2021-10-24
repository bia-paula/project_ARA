CC = clang 

CFLAGS = -g -Wall

main:  main.o algorithm.o graph.o heap.o
	$(CC) $(CFLAGS) $^ -o $@ 

main.o: graph.h algorithm.h
	$(CC) $(CFLAGS) -c main.c

algorithm.o: algorithm.c graph.h heap.h  algorithm.h 
	$(CC) $(CFLAGS) -c algorithm.c

graph.o: graph.c graph.h 
	$(CC) $(CFLAGS) -c graph.c

heap.o: heap.c heap.h 
	$(CC) $(CFLAGS) -c heap.c

clean:
	$(RM) -f *.o main a.out all *~
