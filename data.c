/*
 * data.c
 *
 *  Created on: 22 avr. 2014
 *      Author: izzat
 */

#include <libsx.h>
#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "home.h"
#include "pile.h"
#include "callbacks.h"
#define INIT 0

void initValeurCourante(Widget w, ValeurCourante *d){

	int i,j;
	
	printf("left\n");
	for(i=0;i<MAX;i++){
		d->grille.left[i]=angle135[i].value;
		printf("%d",d->grille.left[i]);
		
	}
	printf("\n");

	printf("right\n");
	for(i=0;i<MAX;i++){
		
		d->grille.right[i]=angle45[i].value;
		printf("%d",d->grille.right[i]);
		
	}
	printf("\n");

	printf("down\n");
	for(i=0;i<MAX;i++){
		
		d->grille.down[i]=horizontal[i].value;
		printf("%d",d->grille.down[i]);
		
	}
	printf("\n");
	printf("grille\n");
	for(i=0;i<MAX;i++){

		for(j=0;j<MAX;j++){
		d->grille.tab[i][j]=INIT;
		printf("%d",d->grille.tab[i][j]);
		}
		printf("\n"); /*checked memory contains 20x20 value -1*/
	}
	d->valeur=0;
	d->ZoneAffich=w;
  	d->actual_x=-1;
	d->actual_y=-1;
	d->p=PILEVIDE;
}


/*Pile *getPile(){
	return (d->pile);
}*/

void setCoord(ValeurCourante* vc, int i, int j){
	vc->actual_x=i;
	vc->actual_y=j;

}
/*void getCoord(ValeurCourante* vc){
	//vc->actual_x;
	//vc->actual_y=j;
	vc->grille.tab[vc->actual_x][vc->actual_y]
}*/


int getValeur(ValeurCourante *vc){
	return(vc->valeur);
}

