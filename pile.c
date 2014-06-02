/*
 * pile.c
 *
 *  Created on: 22 avr. 2014
 *      Author: user
 */



#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

int estVide(Pile p){
	return (Longueur(p)==0);
}

E sommet(Pile p){
	if(estVide(p)){
		fprintf(stderr,"sommet d'une pile : erreur pile vide\n");
		exit(EXIT_FAILURE);
	}
	else{
		return ieme(p,1);
	}
}

void empiler(Pile *p,E e){
	inserer(p,1,e);
}

void depiler(Pile *p){
	if(estVide(*p)){
		fprintf(stderr,"depiler une pile : erreur pile vide\n");
		exit(EXIT_FAILURE);
	}
	else{
		supprimer(p,1);
	}
}
