CC = gcc
OBJS = game.o callbacks.o data.o pile.o liste.o home.o
CFLAGS = -ansi -Wall -g

all : 	$(OBJS)
	$(CC) -o game $(OBJS) -lsx
	
.PHONY : clean
clean :
	rm -f *.o *- core game
