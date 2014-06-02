#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "callbacks.h"
#include "data.h"
#include "pile.h"
#include "home.h"
#define MAXAREA_X 650
#define MAXAREA_Y 600


void mouseDown(Widget w, int which_button, int x, int y, void *data);

void init_Display(int argc, char **argv, void *d){/* *d pointeur generique */
	ValeurCourante *vc=d;	
	Widget ZoneAff;
	Widget button[10];
	Widget generer,undo,exit,space1,space2,space3,space4,space5;
	Widget facile,moyen;
	Widget draw_area;
	Widget view_memory;
	Widget auto_sous,verification,verif_par_coup,solution;

	draw_area   = MakeDrawArea(MAXAREA_X, MAXAREA_Y,redisplay,d);
	SetWidgetPos(draw_area, NO_CARE, NULL, NO_CARE, NULL);

	vc->ZoneAffich=draw_area;
	initValeurCourante(draw_area,d);

	ZoneAff=MakeLabel("JEUX MOJETTE          \xa9 Izzat et Gosti");
	SetWidgetPos(ZoneAff, PLACE_RIGHT, draw_area, NO_CARE, NULL);
	
	/*initData(ZoneAff,d);*/
	

	/*Les buttons*/
	button[0]=MakeButton("           0         ",ajouter0,d);
	button[1]=MakeButton("     1     ",ajouter1,d);
	button[2]=MakeButton("     2     ",ajouter2,d);
	button[3]=MakeButton("     3     ",ajouter3,d);
	button[4]=MakeButton("     4     ",ajouter4,d);
	button[5]=MakeButton("     5     ",ajouter5,d);
	button[6]=MakeButton("     6     ",ajouter6,d);
	button[7]=MakeButton("     7     ",ajouter7,d);
	button[8]=MakeButton("     8     ",ajouter8,d);
	button[9]=MakeButton("     9     ",ajouter9,d);

	generer=MakeButton("      Generer      ",genererQuestion,d);
	undo=MakeButton("      Undo    ",NO_CARE,NULL);
	exit=MakeButton("       Quit       ",quit,NULL);

	facile=MakeButton("      Facile     ",grille_facile,d);
	moyen=MakeButton("      Moyen      ",grille_moyen,d);
	

	view_memory=MakeButton("      DEBUG      ",buttonMemory,d);
	auto_sous=MakeToggle("      Auto Sous      ", FALSE, NULL, autoSous, d);
	verification=MakeButton("      Verification      ",checkAns,d);
	verif_par_coup=MakeButton("      Verif Coup par Coup      ",checkParCoup,d);
	solution=MakeButton("       Solution       ",voirSolution,d);

	space1 = MakeLabel("                         ");
	space2 = MakeLabel("                         ");
	space3 = MakeLabel("      Niveau:         ");
	space4 = MakeLabel("                         ");
	space5 = MakeLabel("                         ");

	/*Placement des buttons*/
	SetWidgetPos(button[1], PLACE_UNDER, ZoneAff, PLACE_RIGHT, draw_area);
	SetWidgetPos(button[2], PLACE_RIGHT, button[1], PLACE_UNDER, ZoneAff);
	SetWidgetPos(button[3], PLACE_RIGHT, button[2], PLACE_UNDER, ZoneAff);
	SetWidgetPos(button[4], PLACE_UNDER, button[1], PLACE_RIGHT, draw_area);
	SetWidgetPos(button[5], PLACE_UNDER, button[2], PLACE_RIGHT, button[4]);
	SetWidgetPos(button[6], PLACE_UNDER, button[3], PLACE_RIGHT, button[5]);
	SetWidgetPos(button[7], PLACE_UNDER, button[4], PLACE_RIGHT, draw_area);
	SetWidgetPos(button[8], PLACE_UNDER, button[5], PLACE_RIGHT, button[7]);
	SetWidgetPos(button[9], PLACE_UNDER, button[6], PLACE_RIGHT, button[8]);
	SetWidgetPos(button[0], PLACE_UNDER, button[7], PLACE_RIGHT, draw_area);

	
	SetWidgetPos(generer, PLACE_UNDER, space1, PLACE_RIGHT, draw_area);
	SetWidgetPos(undo, PLACE_UNDER, button[9], PLACE_RIGHT,button[0]);
	SetWidgetPos(exit, PLACE_UNDER, space1, PLACE_RIGHT, generer);

	SetWidgetPos(space1, PLACE_UNDER, button[0], PLACE_RIGHT, draw_area);
	SetWidgetPos(space2, PLACE_UNDER, generer, PLACE_RIGHT, draw_area);
	SetWidgetPos(space3, PLACE_UNDER, space2, PLACE_RIGHT, draw_area);

	SetWidgetPos(facile, PLACE_UNDER, space3, PLACE_RIGHT, draw_area);
	SetWidgetPos(moyen, PLACE_UNDER, facile, PLACE_RIGHT, draw_area);

	SetWidgetPos(space4, PLACE_UNDER, moyen, PLACE_RIGHT, draw_area);
	SetWidgetPos(view_memory, PLACE_UNDER, space4, PLACE_RIGHT, draw_area);
	SetWidgetPos(space5, PLACE_UNDER, view_memory, PLACE_RIGHT, draw_area);
	SetWidgetPos(auto_sous, PLACE_UNDER, space5, PLACE_RIGHT, draw_area);
	SetWidgetPos(verification, PLACE_UNDER, auto_sous, PLACE_RIGHT, draw_area);
	SetWidgetPos(verif_par_coup, PLACE_UNDER, verification, PLACE_RIGHT, draw_area);
	SetWidgetPos(solution, PLACE_UNDER, verif_par_coup, PLACE_RIGHT, draw_area);

	SetButtonDownCB(draw_area, mouseDown);

	/*pour gerer les couleurs*/
	GetStandardColors();
	
	/*pour afficher interface*/
	ShowDisplay();
}
int main(int argc, char **argv){
  ValeurCourante d;
 
  /*readGamefile("game2.txt",tab_home);
  viewtable(tab_home);
  viewQuestion(tab_home);*/
	
	
  if(OpenDisplay(argc, argv) == 0){
    fprintf(stderr, "Can't open display\n");
    return 1;
  }

  
  init_Display(argc, argv,&d);
  MainLoop();
  return 0;
}
