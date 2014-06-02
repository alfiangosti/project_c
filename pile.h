/*
 * pile.h
 *
 *  Created on: 22 avr. 2014
 *      Author: user
 */

#ifndef PILE_H_
#define PILE_H_


#include "liste.h"
typedef Liste Pile;

#define PILEVIDE LISTEVIDE

extern int estVide(Pile);
extern E sommet(Pile p);
extern void empiler(Pile*,E);
extern void depiler(Pile*);




#endif /* PILE_H_ */
