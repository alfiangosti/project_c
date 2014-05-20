#include <stdio.h>
#include <stdlib.h>
#include "data.h"

extern void quitter(Widget , void *);
void redisplay(Widget w, int width, int height, void *data);
void dessineGrille(int width, int height);
void click(Widget w,int which_button,int x ,int y, void *data);
void dessineNombre(int i, int j,int nombre);
void dessineNombreDansGrille(ValeurCourante *vc);
void afficher1(Widget w, void *d);
void afficher2(Widget w, void *d);
void afficher3(Widget w, void *d);
void afficher4(Widget w, void *d);
void afficher5(Widget w, void *d);
void afficher6(Widget w, void *d);
void afficher7(Widget w, void *d);
void afficher8(Widget w, void *d);
void afficher9(Widget w, void *d);
void afficher0(Widget w, void *d);

