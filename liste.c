/*
 * liste.c
 *
 *  Created on: 22 avr. 2014
 *      Author: user
 */



#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int Longueur (Liste l){
	int longueur=0;
	while(l != NULL){		/*on parcourt la liste*/
		longueur++;
		l = l -> suivant;
	}
	return longueur;
}

/* role : retourne la forme de rang r de la liste l
 * Antécédant : 1 <= r <= longueur(l)
 */

E ieme (Liste l, int r){
	if(r>=1 && r<=Longueur(l)){
		int i;
		for(i=0;i<r-1;i++){		/*on parcourt la liste jusqu'a r*/
			l = l -> suivant;
		}
		return (l -> t);
	}
	else{ /*if(r<1 || r>Longueur(l))*/
		fprintf(stderr,"ERREUR SUR LE RANG\n");
		exit(EXIT_FAILURE);
	}
}

void inserer (Liste *l, int r, E f){
	if(r<1 || r>Longueur(*l)+1){
		fprintf(stderr,"ERREUR SUR LE RANG\n");
		exit(EXIT_FAILURE);
	}else{
		struct noeud *p = malloc(sizeof(struct noeud));
		p -> t = f;
		if(r!=1){
			struct noeud *q ;
			q=*l;
			int i;
			for(i=2;i<r;i++){
				q = q -> suivant;
			}
			/*q désigne l'élément de rang r-1*/
			p -> suivant = q -> suivant;
			q -> suivant = p;
		}else{					/*si on insère en tete de liste*/
			p -> suivant = *l;
			*l=p;
		}
	}
}


void supprimer (Liste *l,int r){
	if(r<1 || r>Longueur(*l)){
		fprintf(stderr,"ERREUR SUR LE RANG\n");
		exit(EXIT_FAILURE);
	}
	/* le rang r est valide */
	else{
		struct noeud *p;
		if(r != 1){
			struct noeud *q=*l;
			int i;
			for(i=2;i<r;i++){
				q = q->suivant;
			}
			/* q désigne l'élément de rang r-1 */
			p = q -> suivant;
			q -> suivant = q -> suivant -> suivant;
		}else{		/*si on insère en tete de liste*/
			p= *l;
			*l=p->suivant;
		}
		free(p);
	}
}
