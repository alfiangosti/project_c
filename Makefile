#compilateur à utiliser
CC = gcc

#Spécifier les options du compilateur
CFLAGS = -ansi -Wall -g

#nom de l'executable
PROG = home

#liste de fichiers objects nécessaires pour le programme final
OBJS= home.o





all: $(OBJS)
	$(CC) -o $(PROG) $(OBJS) -lsx


	
	
.PHONY : clean
	
#pour faire propre

clean:
	rm -f *.o *~ core home
