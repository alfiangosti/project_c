/*
 * liste.h
 *
 *  Created on: 22 avr. 2014
 *      Author: user
 */

#ifndef LISTE_H_
#define LISTE_H_



typedef int E;
typedef struct noeud{
	int t;
	struct noeud *suivant;
} * Liste;

#define LISTEVIDE NULL

extern int Longueur (Liste);
extern E ieme (Liste,int);
extern void inserer(Liste*,int,E);
extern void supprimer(Liste*,int);




#endif /* LISTE_H_ */
