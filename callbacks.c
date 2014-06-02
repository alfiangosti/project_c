/*
 * callbacks.c
 *
 *  Created on: 22 avr. 2014
 *      Author: izzat
 */

#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "data.h"
#include "pile.h"
#include "callbacks.h"
#include "home.h"
#define LARGEURMAX 12
#define MAXAREA 500
#define CONSTANT 50
#define CONVERT 50
#define SHIFT1 100
#define SHIFT2 127

int game_level=1;
int perdu=0;
int enable_autoSous=0;

void quit(Widget w,void *d){
	/*la structure de donnee passé en parametre*/
	exit(0);
}

void drawPattern(char *f){

	char ch;
	FILE *fp;
	int x=SHIFT1,y=SHIFT1,i=0;

	fp=fopen(f,"r");


	if( fp == NULL ){
        	perror(f);    
        	fprintf(stderr,"Error,file cannot be opened\n");
        	exit(1);
        }

	while((ch=fgetc(fp))!=EOF){
		
		if(ch!='\n'){
			if(ch=='a'){
				/*SetColor(BLACK); on dessine pas la case qu'on joue pas
				DrawBox(x,y,50,50);*/
				x=x+50;
				i++;
			}else{
				SetColor(BLUE);
				DrawBox(x,y,50,50);
				x=x+50;
				i++;
			}

		}else{	x=x-(i*50);
			y=y+50;
			i=0;
		}
	
	}
	fclose(fp);        
   	printf("\n");  

}



void redisplay(Widget w, int width, int height, void *d)
{	
	ValeurCourante *vc=d;
	
	if(game_level==1){
	  ClearDrawArea();
	  readGamefile("pattern.txt",tab_home);
	  viewtable(tab_home);
	  viewQuestion(tab_home);
		int i;
 		for(i=0;i<MAX;i++){
		(vc->grille.left[i])=angle135[i].value;
		(vc->grille.right[i])=angle45[i].value;
		(vc->grille.down[i])=horizontal[i].value;
		}
		/*printf("%d",angle135[i].value);*/

	    if(enable_autoSous==1){
		int i=0,j=0;
		calculate(d);
		ClearDrawArea();
		refreshText(vc,"pattern.txt");
		drawPattern("pattern.txt");
		DrawLine(300, 75, 125, 250);
		DrawLine(350, 75, 525, 250);
		DrawLine(150, 425, 500, 425);


		/*somme gauche*/
		while(i<MAX){
					
			if(vc->grille.left[i]!=-1){
			char str[3];
			sprintf(str,"%d",(vc->grille.left[i])-(angle135_data[i].value));
			DrawText(str, 120+j*25, 230-j*25 );
			j++;
			}i++;
		}
		/*somme droit*/
		i=MAX;j=0;
		while(i>=0){
			if(vc->grille.right[i]!=-1){
			char str[3];
			sprintf(str,"%d",(vc->grille.right[i])-(angle45_data[i].value));
			DrawText(str, 375+j*25, 80+j*25 );
			j++;
			}i--;
		}

		/*somme bas*/
		i=0;j=0;
		while(i<MAX){
			if(vc->grille.down[i]!=-1){
			char str[3];
			sprintf(str,"%d",(vc->grille.down[i])-(horizontal_data[i].value));
			DrawText(str, 175+j*50, 450 );
			j++;
			}i++;
		}
	    }
		if(enable_autoSous==0){
		int i=0,j=0;
		
		ClearDrawArea();
		refreshText(vc,"pattern.txt");
		drawPattern("pattern.txt");
		DrawLine(300, 75, 125, 250);
		DrawLine(350, 75, 525, 250);
		DrawLine(150, 425, 500, 425);
		/*somme gauche*/
		while(i<MAX){

			if(vc->grille.left[i]!=-1){
			char str[3];
			sprintf(str,"%d",vc->grille.left[i]);
			DrawText(str, 120+j*25, 230-j*25 );
			j++;
			}i++;
		}
		/*somme droit*/
		i=MAX;j=0;
		while(i>=0){
			if(vc->grille.right[i]!=-1){
			char str[3];
			sprintf(str,"%d",vc->grille.right[i]);
			DrawText(str, 375+j*25, 80+j*25 );
			j++;
			}i--;
		}

		/*somme bas*/
		i=0;j=0;
		while(i<MAX){
			if(vc->grille.down[i]!=-1){
			char str[3];
			sprintf(str,"%d",vc->grille.down[i]);
			DrawText(str, 175+j*50, 450 );
			j++;
			}i++;
		}
	    }
	}




	if(game_level==2){
	  ClearDrawArea();
	  readGamefile("pattern2.txt",tab_home);
	  viewtable(tab_home);
	  viewQuestion(tab_home);
	  	int i;
 		for(i=0;i<MAX;i++){
		(vc->grille.left[i])=angle135[i].value;
		(vc->grille.right[i])=angle45[i].value;
		(vc->grille.down[i])=horizontal[i].value;

		printf("%d",vc->grille.right[i]);
		}
	    if(enable_autoSous==1){

		int i=0,j=0,temp;
		calculate(d);
		ClearDrawArea();
		refreshText(vc,"pattern2.txt");
		drawPattern("pattern2.txt");
		DrawLine(300, 75, 75, 300);
		DrawLine(350, 75, 575, 300);
		DrawLine(100, 425, 550, 425);
		/*somme gauche*/
		while(i<MAX){

			if(vc->grille.left[i]!=-1){
			char str[3];
			temp=(vc->grille.left[j])-(angle135_data[j].value);
			if((j==0)||(j==1))temp=temp-1;
			sprintf(str,"%d",temp);
			DrawText(str, 70+i*25, 280-i*25 );
			j++;
			}i++;
		}
		/*somme droit*/
		i=MAX-1;j=0;
		while(i>=0){
			if(vc->grille.right[j]!=-1){
			char str[3];
			temp=(vc->grille.right[j])-(angle45_data[j].value);
			if((j==0) ||( j==1)) temp=temp-1;
			sprintf(str,"%d",temp);
			DrawText(str, 375+i*25, 80+i*25 );
			j++;
			}i--;
		}

		/*somme bas*/
		i=0;j=0;
		while(i<MAX){
			if(vc->grille.down[i]!=-1){
			char str[3];
			sprintf(str,"%d",(vc->grille.down[i])-(horizontal_data[i].value));
			DrawText(str, 125+i*50, 450 );
			j++;
			}i++;
		}
	    }
		if(enable_autoSous==0){
		int i=0,j=0;
		ClearDrawArea();
		refreshText(vc,"pattern2.txt");
		drawPattern("pattern2.txt");
		DrawLine(300, 75, 75, 300);
		DrawLine(350, 75, 575, 300);
		DrawLine(100, 425, 550, 425);


		/*somme gauche*/
		while(i<MAX){

			if(vc->grille.left[i]!=-1){
			char str[3];
			sprintf(str,"%d",vc->grille.left[i]);
			DrawText(str, 70+i*25, 280-i*25 );
			j++;
			}i++;
		}
		/*somme droit*/
		i=MAX-1;j=0;
		while(i>=0){
			if(vc->grille.right[i]!=-1){
			char str[3];
			sprintf(str,"%d",vc->grille.right[j]);
			DrawText(str, 375+i*25, 80+i*25 );
			j++;
			}i--;
		}

		/*somme bas*/
		i=0;j=0;
		while(i<MAX){
			if(vc->grille.down[i]!=-1){
			char str[3];
			sprintf(str,"%d",vc->grille.down[i]);
			DrawText(str, 125+i*50, 450 );
			j++;
			}i++;
		}
	    }
	}
	
	if(perdu==-2){
		SetColor(RED);
		DrawText("VOUS AVEZ PERDU!!!",270,500); 
	}
	if(perdu==1){
		SetColor(GREEN);
		DrawText("VOUS ETES GAGNANT!!!",270,500); 
	}


}

void refreshPattern(void *d){

	ValeurCourante *vc=d;
	if(game_level==1){
	  readGamefile("pattern.txt",tab_home);
	  viewtable(tab_home);
	  viewQuestion(tab_home);

	    if(enable_autoSous==1){
		int i=0,j=0;
		calculate(d);
		ClearDrawArea();
		refreshText(vc,"pattern.txt");
		drawPattern("pattern.txt");
		DrawLine(300, 75, 125, 250);
		DrawLine(350, 75, 525, 250);
		DrawLine(150, 425, 500, 425);
		/*somme gauche*/
		while(i<MAX){

			if(vc->grille.left[i]!=-1){
			char str[3];
			sprintf(str,"%d",(vc->grille.left[i])-(angle135_data[i].value));
			DrawText(str, 120+j*25, 230-j*25 );
			j++;
			}i++;
		}
		/*somme droit*/
		i=MAX;j=0;
		while(i>=0){
			if(vc->grille.right[i]!=-1){
			char str[3];
			sprintf(str,"%d",(vc->grille.right[i])-(angle45_data[i].value));
			DrawText(str, 375+j*25, 80+j*25 );
			j++;
			}i--;
		}

		/*somme bas*/
		i=0;j=0;
		while(i<MAX){
			if(vc->grille.down[i]!=-1){
			char str[3];
			sprintf(str,"%d",(vc->grille.down[i])-(horizontal_data[i].value));
			DrawText(str, 175+j*50, 450 );
			j++;
			}i++;
		}
	    }
		if(enable_autoSous==0){
		int i=0,j=0;
		
		ClearDrawArea();
		refreshText(vc,"pattern.txt");
		drawPattern("pattern.txt");
		DrawLine(300, 75, 125, 250);
		DrawLine(350, 75, 525, 250);
		DrawLine(150, 425, 500, 425);
		/*somme gauche*/
		while(i<MAX){

			if(vc->grille.left[i]!=-1){
			char str[3];
			sprintf(str,"%d",vc->grille.left[i]);
			DrawText(str, 120+j*25, 230-j*25 );
			j++;
			}i++;
		}
		/*somme droit*/
		i=MAX;j=0;
		while(i>=0){
			if(vc->grille.right[i]!=-1){
			char str[3];
			sprintf(str,"%d",vc->grille.right[i]);
			DrawText(str, 375+j*25, 80+j*25 );
			j++;
			}i--;
		}

		/*somme bas*/
		i=0;j=0;
		while(i<MAX){
			if(vc->grille.down[i]!=-1){
			char str[3];
			sprintf(str,"%d",vc->grille.down[i]);
			DrawText(str, 175+j*50, 450 );
			j++;
			}i++;
		}
	    }
	}


	if(perdu==-2){
		SetColor(RED);
		DrawText("VOUS AVEZ PERDU!!!",270,500); 
	}
	if(perdu==1){
		SetColor(GREEN);
		DrawText("VOUS ETES GAGNANT!!!",270,500); 
	}

}

void grille_facile(Widget w,void *d){
	
	ValeurCourante *vc=d;
	game_level=1;
	redisplay(vc->ZoneAffich,600,600,vc);
	
	
}

void grille_moyen(Widget w,void *d){

	ValeurCourante *vc=d;
	game_level=2;
	redisplay(vc->ZoneAffich,600,600,vc);

}



void ajouter1(Widget w,void *d){

	ValeurCourante *vc=d;
	
	vc->valeur=1;
	vc->grille.tab[vc->actual_x][vc->actual_y]=1;
	actualiser(vc->valeur,vc->actual_x,vc->actual_y);

	refreshPattern(vc);
	printf("refresh button 1\n");

}

void ajouter2(Widget w,void *d){

	ValeurCourante *vc=d;
	
	vc->valeur=2;
	vc->grille.tab[vc->actual_x][vc->actual_y]=2;
	actualiser(vc->valeur,vc->actual_x,vc->actual_y);

	refreshPattern(vc);
	printf("refresh button 2\n");
}

void ajouter3(Widget w,void *d){

	ValeurCourante *vc=d;
	
	vc->valeur=3;
	vc->grille.tab[vc->actual_x][vc->actual_y]=3;
	actualiser(vc->valeur,vc->actual_x,vc->actual_y);

	refreshPattern(vc);
	printf("refresh button 3\n");
}

void ajouter4(Widget w,void *d){

	ValeurCourante *vc=d;
	
	vc->valeur=4;
	vc->grille.tab[vc->actual_x][vc->actual_y]=4;
	actualiser(vc->valeur,vc->actual_x,vc->actual_y);

	refreshPattern(vc);
	printf("refresh button 4\n");
}

void ajouter5(Widget w,void *d){

	ValeurCourante *vc=d;
	
	vc->valeur=5;
	vc->grille.tab[vc->actual_x][vc->actual_y]=5;
	actualiser(vc->valeur,vc->actual_x,vc->actual_y);

	refreshPattern(vc);
	printf("refresh button 5\n");
}

void ajouter6(Widget w,void *d){

	ValeurCourante *vc=d;
	
	vc->valeur=6;
	vc->grille.tab[vc->actual_x][vc->actual_y]=6;
	actualiser(vc->valeur,vc->actual_x,vc->actual_y);

	refreshPattern(vc);
	printf("refresh button 6\n");
}

void ajouter7(Widget w,void *d){

	ValeurCourante *vc=d;
	
	vc->valeur=7;
	vc->grille.tab[vc->actual_x][vc->actual_y]=7;
	actualiser(vc->valeur,vc->actual_x,vc->actual_y);

	refreshPattern(vc);
	printf("refresh button 7\n");
}

void ajouter8(Widget w,void *d){

	ValeurCourante *vc=d;
	
	vc->valeur=8;
	vc->grille.tab[vc->actual_x][vc->actual_y]=8;
	actualiser(vc->valeur,vc->actual_x,vc->actual_y);

	refreshPattern(vc);
	printf("refresh button 8\n");
}

void ajouter9(Widget w,void *d){

	ValeurCourante *vc=d;
	
	vc->valeur=9;
	vc->grille.tab[vc->actual_x][vc->actual_y]=9;
	actualiser(vc->valeur,vc->actual_x,vc->actual_y);

	refreshPattern(vc);
	printf("refresh button 9\n");
}

void ajouter0(Widget w,void *d){

	ValeurCourante *vc=d;
	
	vc->valeur=0;
	vc->grille.tab[vc->actual_x][vc->actual_y]=0;

	/*printf("%d",vc->grille.tab[vc->actual_x][vc->actual_y]);*/
	actualiser(vc->valeur,vc->actual_x,vc->actual_y);

	refreshPattern(vc);
	printf("refresh button 0\n");

}

void buttonMemory(Widget w,void *d){

	ValeurCourante *vc=d;
	/*
	vc->valeur=55;
	vc->grille.tab[vc->actual_x][vc->actual_y]=55;

	printf("%d",vc->grille.tab[vc->actual_x][vc->actual_y]);
	*/
	int x,y;
	for(y=0;y<MAX;y++){
		for(x=0;x<MAX;x++){
		
		printf("%d",vc->grille.tab[x][y]);
		}
		printf("\n"); /*checked memory contains 20x20 value -1*/
	}

	/*actualiser(vc->valeur,vc->actual_x,vc->actual_y);*/

	refreshPattern(vc);
	printf("refresh button memory\n");

}

/*permettre d'activer l'option auto soustraction*/
void autoSous(Widget w,void *d){

	ValeurCourante *vc=d;
	
	printf("auto sous = %d",enable_autoSous=!enable_autoSous);
	refreshPattern(vc);
}

/*verifie toutes les valeurs dans les grilles*/
void checkAns(Widget w,void *d){
	
	ValeurCourante *vc=d;

	int x,y,i=0;
	int tabtemp[6][9];

	for(y=MAX-4;y>=0;y--){
		for(x=0;x<MAX;x++){
			tabtemp[i][x]=tab_home[y][x];
			printf(" %d ",tab_home[y][x]);
		}
		printf("\n");
		i++;
	}
	for(y=0;y<MAX-3;y++){
		for(x=0;x<MAX;x++){
			if(tabtemp[y][x]!=-1){
				if(tabtemp[y][x]!=vc->grille.tab[x][y]){
					/*perdu=-2;break;*/
				
				}
			}
		/*printf(" %d ",tabtemp[y][x]);*/
		/*printf(" %d ",vc->grille.tab[x][y]);*/
		}
		printf("\n");
		if(perdu==-2){printf(" %d ",perdu);break;}else{perdu=1;}
	} 

	
	if(perdu==-2){
		SetColor(RED);
		DrawText("VOUS AVEZ PERDU!!!",270,500); 
	}
	if(perdu==1){
		SetColor(GREEN);
		DrawText("VOUS ETES GAGNANT!!!",270,500); 
	}

	redisplay(vc->ZoneAffich,600,600,vc);
   
}

/*cette fonction verifie si la derniere valeur saisi est correct*/
void checkParCoup(Widget w,void *d){
	
	ValeurCourante *vc=d;

	int x,y,i=0;
	int tabtemp[6][9];

	for(y=0;y<6;y++){
		for(x=0;x<9;x++){tabtemp[y][x]=0;
		}
	}printf("\n");

	for(y=MAX-4;y>=0;y--){
		for(x=0;x<MAX;x++){
			tabtemp[i][x]=tab_home[y][x];
			printf(" %d ",tab_home[y][x]);
		}
		printf("\n");
		i++;
	}printf("\n");

	for(y=0;y<6;y++){
		for(x=0;x<9;x++){printf(" %d ",tabtemp[y][x]);
		}printf("\n");
	}

	printf("last value %d",vc->grille.tab[vc->actual_x][vc->actual_y]);
   

	if((vc->grille.tab[vc->actual_x][vc->actual_y])==tabtemp[vc->actual_y][vc->actual_x]){

		SetColor(GREEN);
		DrawText("BONNE VALEUR!!!",270,500); 
	}else{
		SetColor(GREEN);
		DrawText("MAUVAISE VALEUR!!! Re-essayez",270,500); 
	}

}

/*afficher les solutions dans les grilles*/
void voirSolution(Widget w,void *d){
	
}

/*appel la fonction qui genere pattern.txt and pattern2.txt (des nouveaux grilles)*/
void genererQuestion(Widget w,void *d){
	
}

void mouseDown(Widget w, int which_button, int x, int y, void *d)
{
	ValeurCourante *vc=d;
	
	printf("\t coordonnée x pixel : %d \n",x); 
	printf("\t coordonnée y pixel : %d \n",y); 



	setCoord(vc,(x-SHIFT1)/CONVERT,(y-SHIFT1)/CONVERT);
		
	refreshPattern(vc);

}

/*don't need this function if only showing numbers in the pattern*/
void actualiser(int valeur,int actual_x, int actual_y){
	int pixel_y=(actual_y*CONVERT)+SHIFT2; 
	int pixel_x=(actual_x*CONVERT)+SHIFT2;
	 
	char str[3];
	sprintf(str,"%d",valeur);
	DrawText(str,pixel_x,pixel_y); 
	
}

void calculate(void *d){
int i,j;

ValeurCourante *vc=d;
for(i=0;i<COLUMN;i++){
	horizontal_data[i].value=0;
	}	 
    for(i=0;i<COLUMN;i++){
	angle135_data[i].value=0;
	}
    for(i=0;i<COLUMN;i++){
	angle45_data[i].value=0;
	}


for(i=0;i<MAX;i++){       
        for(j=0;j<MAX;j++){
                
                        switch(j){
                            case 0:
                                horizontal_data[0].value=horizontal_data[0].value+vc->grille.tab[j][i];				
                                horizontal_data[0].coor=0;break;
                            case 1:
                                horizontal_data[1].value=horizontal_data[1].value+vc->grille.tab[j][i];
                                horizontal_data[1].coor=1;break;
                            case 2:
                                horizontal_data[2].value=horizontal_data[2].value+vc->grille.tab[j][i];
                                horizontal_data[2].coor=2;break;
                            case 3:
                                horizontal_data[3].value=horizontal_data[3].value+vc->grille.tab[j][i];
                                horizontal_data[3].coor=3;break;
                            case 4:
                                horizontal_data[4].value=horizontal_data[4].value+vc->grille.tab[j][i];
                                horizontal_data[4].coor=4;break;
                            case 5:
                                horizontal_data[5].value=horizontal_data[5].value+vc->grille.tab[j][i];
                                horizontal_data[5].coor=5;break;
                            case 6:
                                horizontal_data[6].value=horizontal_data[6].value+vc->grille.tab[j][i];
                                horizontal_data[6].coor=6;break;
			    case 7:
                                horizontal_data[7].value=horizontal_data[7].value+vc->grille.tab[j][i];
                                horizontal_data[7].coor=7;break;
			    case 8:
                                horizontal_data[8].value=horizontal_data[8].value+vc->grille.tab[j][i];
                                horizontal_data[8].coor=8;break;			
                        }
                        switch(i-j){
			    case 4:
                                angle135_data[0].value=angle135_data[0].value+vc->grille.tab[j][i];
                                angle135_data[0].coor=4;break; 
			    case 3:
                                angle135_data[1].value=angle135_data[1].value+vc->grille.tab[j][i];
                                angle135_data[1].coor=3;break;
                            case 2:
                                angle135_data[2].value=angle135_data[2].value+vc->grille.tab[j][i];
                                angle135_data[2].coor=2;break;
                            case 1:
                                angle135_data[3].value=angle135_data[3].value+vc->grille.tab[j][i];
                                angle135_data[3].coor=1;break;
                            case 0:
                                angle135_data[4].value=angle135_data[4].value+vc->grille.tab[j][i];
                                angle135_data[4].coor=0;break;
                            case -1:
                                angle135_data[5].value=angle135_data[5].value+vc->grille.tab[j][i];
                                angle135_data[5].coor=-1;break;
                            case -2:
                                angle135_data[6].value=angle135_data[6].value+vc->grille.tab[j][i];
                                angle135_data[6].coor=-2;break;
                            case -3:
                                angle135_data[7].value=angle135_data[7].value+vc->grille.tab[j][i];
                                angle135_data[7].coor=-3;break;
                            case -4:
                                angle135_data[8].value=angle135_data[8].value+vc->grille.tab[j][i];
                                angle135_data[8].coor=-4;break;
                        }
                        switch(-i-j){
			    case -12:
                                angle45_data[0].value=angle45_data[0].value+vc->grille.tab[j][i];
                                angle45_data[0].coor=-12;break;
                            case -11:
                                angle45_data[1].value=angle45_data[1].value+vc->grille.tab[j][i];
                                angle45_data[1].coor=-11;break;	
			    case -10:
                                angle45_data[2].value=angle45_data[2].value+vc->grille.tab[j][i];
                                angle45_data[2].coor=-10;break;	
			    case -9:
                                angle45_data[3].value=angle45_data[3].value+vc->grille.tab[j][i];
                                angle45_data[3].coor=-9;break;	
                            case -8:
                                angle45_data[4].value=angle45_data[4].value+vc->grille.tab[j][i];
                                angle45_data[4].coor=-8;break;
                            case -7:
                                angle45_data[5].value=angle45_data[5].value+vc->grille.tab[j][i];
                                angle45_data[5].coor=-7;break;
                            case -6:
                                angle45_data[6].value=angle45_data[6].value+vc->grille.tab[j][i];
                                angle45_data[6].coor=-6;break;
                            case -5:
                                angle45_data[7].value=angle45_data[7].value+vc->grille.tab[j][i];
                                angle45_data[7].coor=-5;break;
                            case -4:
                                angle45_data[8].value=angle45_data[8].value+vc->grille.tab[j][i];
                                angle45_data[8].coor=-4;break;
                            
			    	
                        }
                             
        }  
        
    }

	horizontal_data[0].value=-1;
	horizontal_data[8].value=-1;
	angle45_data[0].value=-1;
	angle45_data[1].value=-1;
	angle135_data[0].value=-1;
	angle135_data[1].value=-1;

	
	printf("\n");
	printf("Horizontal : "); 
	for(i=0;i<COLUMN;i++){
	/*if(horizontal_data[i].value!=-1){printf(" %d ",horizontal_data[i].value);}*/
	printf(" %d ",horizontal_data[i].value);
	}
	printf("\n");
	printf("Angle 45 : "); 
	for(i=0;i<COLUMN;i++){
	printf(" %d ",angle45_data[i].value);
	}
	printf("\n");
	printf("Angle 135 : ");
	for(i=0;i<COLUMN;i++){  
	printf(" %d ",angle135_data[i].value); 
	}
		 
    	printf("\n");


}


void refreshText(ValeurCourante *vc,char *f){

	char ch;
	FILE *fp;
	int x=SHIFT2,y=SHIFT2,i=0,j=0;

	fp=fopen(f,"r");


	if( fp == NULL ){
        	perror(f);    
        	fprintf(stderr,"Error,file cannot be opened\n");
        	exit(1);
        }

	while((ch=fgetc(fp))!=EOF){
		
		if(ch!='\n'){
			if(ch=='a'){
				x=x+50;
				i++;
			}else{
				SetColor(BLUE);
				char str[3];
				sprintf(str,"%d",vc->grille.tab[i][j]);
				
				/*sprintf(str,"%d",0);*/
				DrawText(str,x,y);
				x=x+50;
				i++;
			}

		}else{	x=x-(i*50);
			y=y+50;
			i=0;
			j++;
		}
	
	}
	fclose(fp);        
    	printf("\n");  
	

}


/*void enter(Widget w,void *d){
	ValeurCourante *vc=d;
	empiler(getPile(vc),getValeur(vc));
	raz(vc);
}*/

/*void plus(Widget w,void *d){
	int opg,opd;
	opd=
	depiler();
	opg=
	depiler();
	empiler(    ,opg+opd);

}*/

