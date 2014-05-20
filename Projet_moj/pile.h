#ifndef _PILEH
#define _PILEH

#include <stdlib.h>

typedef struct noeud {
  int elt; /* un élément */
  struct noeud *suivant; /* pointeur sur le noeud suivant */
} * Pile;

#define PileVide NULL

extern int estvide(Pile);

extern int sommet(Pile);

extern void empiler(Pile *, int);

extern void depiler(Pile *);

#endif /* _PILEH*/
