CC = gcc
OBJS = ig.o callbacks.o data.o pile.o
CFLAGS = -ansi -Wall -g

all : 	$(OBJS)
	$(CC) -o ig $(OBJS) -lsx
	
.PHONY : clean
clean :
	rm -f *.o *- core ig
