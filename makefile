CC = gcc

CFLAGS = -g -Wall

main:  main.o bgp.o graph.o
	$(CC) $(CFLAGS) $^ -o $@ 

main.o: graph.h 
	$(CC) $(CFLAGS) -c main.c

bgp.o: bgp.c graph.h bgp.h 
	$(CC) $(CFLAGS) -c bgp.c

graph.o: graph.c graph.h 
	$(CC) $(CFLAGS) -c graph.c

clean:
	$(RM) -f *.o main a.out all *~
