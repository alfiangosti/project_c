#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "data.h"
#include "pile.h"
#include "callbacks.h"
#define WIDTH 500
#define HEIGHT 500

#define COTECASE 50

/*Rôle : terminer l'application*/
/*Callback Bouton Quit*/
void quitter(Widget w, void *d){
  exit(0);
}




void redisplay(Widget w, int width, int height, void *data){
	ValeurCourante *vc=data;
	Grille gr;
	gr.largeur=7;   
	gr.hauteur=6;
	ClearDrawArea();         
 	dessineGrille(gr.largeur,gr.hauteur);
	dessineNombreDansGrille(vc);
	
}




/*dessine grille de dimensions l*h 
par@: l nb de cases en largeur
      h nb de cases en hauteur 
*/
void dessineGrille(int l, int h){ /* marche avec tailles 5x4 ,  7x6  , 9x8.Bug avec autres dimensions  */
	int i,j;
/*	int largeurEnPixels=l*COTECASE; 
	int hauteurEnPixels=h*COTECASE; */
	SetColor(BLACK); 
        /* LIGNES */            
	for(i=0; i<(l/2)+1; i++){  /* dessine les lignes croissantes*/
		DrawLine( ((l/2)-i)*COTECASE,i*COTECASE,((l/2)+i+1)*COTECASE ,i*COTECASE); /* y constant */
		if(i==l/2){ /* la ligne du milieu est repetée */
			DrawLine( ((l/2)-i)*COTECASE,(i+1)*COTECASE,((l/2)+i+1)*COTECASE ,(i+1)*COTECASE);
		}
			
	}
	for(i=0; i<(l/2)-1; i++){  /* dessine les lignes decroissantes */
		DrawLine( (i+1)*COTECASE, ( (l/2)+i+2)*COTECASE , (l-i-1)*COTECASE ,( (l/2)+i+2)*COTECASE); /* y constant */
	}

	
	/*COLONNES */
	/*SetColor(BLUE);*/
	for(j=0;j<(h/2)+1;j++){ /* dessine les colonnes de gauche */
		
		if(j==h/2){ /* dessine la colonnedu milieu qui est repetée */
			DrawLine(j*COTECASE,((l/2)-j)*COTECASE,j*COTECASE,((l/2)+j)*COTECASE);
			DrawLine((j+1)*COTECASE,((l/2)-j)*COTECASE,(j+1)*COTECASE,((l/2)+j)*COTECASE);
		}
		else
			DrawLine(j*COTECASE,((l/2)-j)*COTECASE,j*COTECASE,((l/2)+j+1)*COTECASE); 
	}
	for(j=0; j<=(h/2)-1; j++){/* dessine les colonnes de droite */
		DrawLine( ((h/2)+j+2)*COTECASE,(j+1)*COTECASE,((h/2)+j+2)*COTECASE,(h-j)*COTECASE); 
	}
}





void afficher1(Widget w, void *d){
	ValeurCourante *vc=d;
	int i=vc->iCase, j=vc->jCase;
	vc->grille.tabGrille[i][j]=1; /* on met a jour le tableau de grille,il sera utilse qnd il faudra faire des fonctions de verification etc..*/ 
	vc->valeur=1; /* on recupere la valeur pour ensuite la mettre dans la grille */
	dessineNombre(i,j,1);
}

void afficher2(Widget w, void *d){
	ValeurCourante *vc=d;
	int i=vc->iCase, j=vc->jCase;
	vc->grille.tabGrille[i][j]=2;
	vc->valeur=2; 
	dessineNombre(i,j,2);
}

void afficher3(Widget w, void *d){
	ValeurCourante *vc=d;
	int i=vc->iCase, j=vc->jCase;
	vc->grille.tabGrille[i][j]=3;
	vc->valeur=3; 
	dessineNombre(i,j,3);
}

void afficher4(Widget w, void *d){
	ValeurCourante *vc=d;
	int i=vc->iCase, j=vc->jCase;
	vc->grille.tabGrille[i][j]=4;
	vc->valeur=4; 
	dessineNombre(i,j,4);
}

void afficher5(Widget w, void *d){
	ValeurCourante *vc=d;
	int i=vc->iCase, j=vc->jCase;
	vc->grille.tabGrille[i][j]=5;
	vc->valeur=5; 
	dessineNombre(i,j,5);
}

void afficher6(Widget w, void *d){
	ValeurCourante *vc=d;
	int i=vc->iCase, j=vc->jCase;
	vc->grille.tabGrille[i][j]=6;
	vc->valeur=6; 
	dessineNombre(i,j,6);
}

void afficher7(Widget w, void *d){
	ValeurCourante *vc=d;
	int i=vc->iCase, j=vc->jCase;
	vc->grille.tabGrille[i][j]=7;
	vc->valeur=7; 
	dessineNombre(i,j,7);
}

void afficher8(Widget w, void *d){
	ValeurCourante *vc=d;
	int i=vc->iCase, j=vc->jCase;
	vc->grille.tabGrille[i][j]=8;
	vc->valeur=8; 
	dessineNombre(i,j,8);
}

void afficher9(Widget w, void *d){
	ValeurCourante *vc=d;
	int i=vc->iCase, j=vc->jCase;
	vc->grille.tabGrille[i][j]=9;
	vc->valeur=9; 
	dessineNombre(i,j,9);
}

void afficher0(Widget w, void *d){
	ValeurCourante *vc=d;
	int i=vc->iCase, j=vc->jCase;
	vc->grille.tabGrille[i][j]=0;
	vc->valeur=0; 
	dessineNombre(i,j,0);
}




/* void  func(Widget w, int which_button, int x, int y, void *data)
    {
    }

Then, whenever the user presses a mouse button in the drawing area, your callback is called. The first argument is the drawing area widget where the event happened. The next argument is an integer specifying which button was pressed. It is a small positive integer. A value of one is the left mouse button, two is the middle mouse button and three is the right mouse button. 
*/
void click(Widget w,int which_button,int x ,int y, void *data){/* recuper x et y du click de la souris sur le drawArea */
	ValeurCourante *vc=data;
	int i,j;
	i=y/COTECASE; /* on divise par COTECASE pour se debarasser des coordonnées en pixels */
	j=x/COTECASE;
	printf("\t coordonnée x de la souris en pixel : %d \n",j); 
	printf("\n\t Numero de la ligne de case cliquée :%d \n \t Numero de la colonne de case cliquée :%d \n ",i,j);
	setVal(vc,i,j);/*affecte les coordonnées i et j a vcourante , donc vc->iCase vaut i et vc->jCase vaut j*/
	redisplay(vc->ZoneAffich,WIDTH,HEIGHT,vc);
}







/* fonction appart pour plus de lisibilité */
void dessineNombre(int i, int j,int nombre){
	int y=(i+0.55)*COTECASE; /* y est la coordonnée en pixels  */
	int x=(j+0.55)*COTECASE;
	char str[40];
	sprintf(str,"%d",nombre);
	DrawText(str,x,y); /* dessiner le nombre passé en par@ dans la case cliquée */
}
	




	
void dessineNombreDansGrille(ValeurCourante *vc){
	/* on recupere la valeur du bouton cliqué puis on la dessine dans la grille
	vaudrait d'abord verifier si la case est vide */
	printf("%d \n" ,vc->valeur);
	dessineNombre(vc->iCase,vc->jCase,vc->valeur);
}
	



