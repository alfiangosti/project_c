#include <stdio.h>
#include <stdlib.h>
#include "pile.h"


/* Rôle : teste si la pile est vide */
int estvide(Pile p) {
  return p == PileVide;
}


/* Rôle : dépile le sommet de pile */
void depiler(Pile *p) {
  struct noeud *q;
  if (estvide(*p)) {
    fprintf(stderr, "depiler: erreur pile vide\n");
    exit(1);
  }
  q = *p;
  *p=(*p)->suivant;
  free(q);
}


/* Rôle : empile x en sommet de pile */
void empiler(Pile *p, int x) {
  struct noeud *q = malloc(sizeof(struct noeud));
  q->elt = x;
  q->suivant = *p;
  *p = q;
}


/* Rôle : retourne le sommet de pile */
int sommet(Pile p) {
  if (estvide(p)) {
    fprintf(stderr, "sommet: erreur pile vide\n");
    exit(2);
  }
  return p->elt;
}
