/*
 * callbacks.h
 *
 *  Created on: 22 avr. 2014
 *      Author: Izzat
 */

#ifndef CALLBACKS_H_
#define CALLBACKS_H_
#include <stdlib.h>
#include <libsx.h>
#include "data.h"

void quit(Widget w,void *d);
void drawPattern(char *f);
void grille_facile(Widget w,void *d);
void grille_moyen(Widget w,void *d);
void grille_difficile(Widget w,void *d);

void refreshText(ValeurCourante *vc,char *f);
void redisplay(Widget w, int width, int height, void *data);

void actualiser(int valeur,int actual_x, int actual_y);

void ajouter1(Widget w,void *d);
void ajouter2(Widget w,void *d);
void ajouter3(Widget w,void *d);
void ajouter4(Widget w,void *d);
void ajouter5(Widget w,void *d);
void ajouter6(Widget w,void *d);
void ajouter7(Widget w,void *d);
void ajouter8(Widget w,void *d);
void ajouter9(Widget w,void *d);
void ajouter0(Widget w,void *d);
void buttonMemory(Widget w,void *d);
void autoSous(Widget w,void *d);
void checkAns(Widget w,void *d);
void checkParCoup(Widget w,void *d);
void voirSolution(Widget w,void *d);
void genererQuestion(Widget w,void *d);

void mouseDown(Widget w, int which_button, int x, int y, void *data);
void calculate(void *d);
extern int game_level;

#endif /* CALLBACKS_H_ */
