/*
 * data.h
 *
 *  Created on: 22 avr. 2014
 *      Author: izzat
 */

#ifndef DATA_H_
#define DATA_H_
#include <libsx.h>
#include "pile.h"
#define MAX 9

typedef struct{
		int left[MAX];
		int right[MAX];
		int down[MAX];
		int tab[MAX][MAX];
	}Matrice;

typedef struct{
	Matrice grille;
	int actual_x;
	int actual_y;
	int valeur;
	Widget ZoneAffich;
	Pile p;

} ValeurCourante;




extern void initValeurCourante(Widget w, ValeurCourante *d);
/*extern void initValeurCourante(ValeurCourante *);*/
extern void setCoord(ValeurCourante* vc, int i, int j);
int getValeur(ValeurCourante *vc);



#endif /* DATA_H_ */
