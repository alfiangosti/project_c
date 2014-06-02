#include <stdio.h>
#include <stdlib.h>

#include <libsx.h>
#include "home.h"
#include "callbacks.h"


/*
 * compile et execute
 * make && ./home
 */



/*
 * Role: lire a partir un fichier le mask pour jouer le jeu 
 * (Ex: 'a' pas joueable, autre de 'a' joueable)
 */

void readGamefile(char *f,int tab_home[][COLUMN]){
    
    
   char ch;
   FILE *fp;
   int i=ROW-1;
   int j=0;
   
   
   fp = fopen(f,"r"); 
 
   if( fp == NULL ){
        perror(f);    
        fprintf(stderr,"Error,file cannot be opened\n");
        exit(1);
        
   }
 
   
   
   while( ( ch = fgetc(fp) ) != EOF ){
              if(ch == 'a'){
               tab_home[i][j]=-1;
               j++;
              }
              else{
                   if(ch == '\n'){
                   i--;
                   j=0;
                   }
                   else{
                   tab_home[i][j]=ch-'0';
                   j++;
                   }   
              }
               
               
        
    
    }   
       
       
   
   
    fclose(fp);        
    printf("\n");  
   
    
}



/*
void calculateSomme(int tab_home[][COLUMN],int rowChercher,int columnChercher,int *result){
    int i,j;
    int angle45=rowChercher-columnChercher;
    int angle135=-rowChercher-columnChercher;
    
    for(i=ROW-1;i>=0;i--){
        
        for(j=0;j<COLUMN;j++){
            if(j==columnChercher){
                if(tab_home[i][j] != -1){
                result[0]=result[0]+tab_home[i][j];
                }
            }
             if((i-j)==angle45){
                if(tab_home[i][j] != -1){
                result[1]=result[1]+tab_home[i][j];
                }
            }
             if((-i-j)==angle135){
                if(tab_home[i][j] != -1){
                result[2]=result[2]+tab_home[i][j];
                }
            }
        
        }       
    
    }
	

}

*/

void viewQuestion(int tab_home[][COLUMN]){
    int i,j;
    for(i=0;i<COLUMN;i++){
	horizontal[i].value=0;
	}	 
    for(i=0;i<COLUMN;i++){
	angle135[i].value=0;
	}
    for(i=0;i<COLUMN;i++){
	angle45[i].value=0;
	}	
    
   
    for(i=ROW-1;i>=0;i--){       
        for(j=0;j<COLUMN;j++){
                if(tab_home[i][j] != -1){
                        switch(j){
                            case 0:
                                horizontal[0].value=horizontal[0].value+tab_home[i][j];				
                                horizontal[0].coor=0;break;
                            case 1:
                                horizontal[1].value=horizontal[1].value+tab_home[i][j];
                                horizontal[1].coor=1;break;
                            case 2:
                                horizontal[2].value=horizontal[2].value+tab_home[i][j];
                                horizontal[2].coor=2;break;
                            case 3:
                                horizontal[3].value=horizontal[3].value+tab_home[i][j];
                                horizontal[3].coor=3;break;
                            case 4:
                                horizontal[4].value=horizontal[4].value+tab_home[i][j];
                                horizontal[4].coor=4;break;
                            case 5:
                                horizontal[5].value=horizontal[5].value+tab_home[i][j];
                                horizontal[5].coor=5;break;
                            case 6:
                                horizontal[6].value=horizontal[6].value+tab_home[i][j];
                                horizontal[6].coor=6;break;
			    case 7:
                                horizontal[7].value=horizontal[7].value+tab_home[i][j];
                                horizontal[7].coor=7;break;
			    case 8:
                                horizontal[8].value=horizontal[8].value+tab_home[i][j];
                                horizontal[8].coor=8;break;			
                        }
                        switch(i-j){
                            case -7:
                                angle45[0].value=angle45[0].value+tab_home[i][j];
                                angle45[0].coor=-7;break;
			    case -6:
                                angle45[1].value=angle45[0].value+tab_home[i][j];
                                angle45[1].coor=-6;break;
			    case -5:
                                angle45[2].value=angle45[2].value+tab_home[i][j];
                                angle45[2].coor=-5;break;
                            case -4:
                                angle45[3].value=angle45[3].value+tab_home[i][j];
                                angle45[3].coor=-4;break;
                            case -3:
                                angle45[4].value=angle45[4].value+tab_home[i][j];
                                angle45[4].coor=-3;break;
                            case -2:
                                angle45[5].value=angle45[5].value+tab_home[i][j];
                                angle45[5].coor=-2;break;
                            case -1:
                                angle45[6].value=angle45[6].value+tab_home[i][j];
                                angle45[6].coor=-1;break;
                            case 0:
                                angle45[7].value=angle45[7].value+tab_home[i][j];
                                angle45[7].coor=0;break;
                            case 1:
                                angle45[8].value=angle45[8].value+tab_home[i][j];
                                angle45[8].coor=1;break;

                        }
                        switch(-i-j){

			    case -9:
                                angle135[8].value=angle135[8].value+tab_home[i][j];
                                angle135[8].coor=-9;break;	
                            case -8:
                                angle135[7].value=angle135[7].value+tab_home[i][j];
                                angle135[7].coor=-8;break;
                            case -7:
                                angle135[6].value=angle135[6].value+tab_home[i][j];
                                angle135[6].coor=-7;break;
                            case -6:
                                angle135[5].value=angle135[5].value+tab_home[i][j];
                                angle135[5].coor=-6;break;
                            case -5:
                                angle135[4].value=angle135[4].value+tab_home[i][j];
                                angle135[4].coor=-5;break;
                            case -4:
                                angle135[3].value=angle135[3].value+tab_home[i][j];
                                angle135[3].coor=-4;break;
                            case -3:
                                angle135[2].value=angle135[2].value+tab_home[i][j];
                                angle135[2].coor=-3;break;
                            case -2:
                                angle135[1].value=angle135[1].value+tab_home[i][j];
                                angle135[1].coor=-2;break;
			    case -1:
                                angle135[0].value=angle135[0].value+tab_home[i][j];
                                angle135[0].coor=-1;break;

			    	
                        }
                    }         
        }  
        
    }  

	if( game_level==1){
	horizontal[0].value=-1;
	horizontal[8].value=-1;
	angle45[0].value=-1;
	angle45[1].value=-1;
	angle135[0].value=-1;
	angle135[1].value=-1;
	}

	printf("\n");
	printf("Horizontal : "); 
	for(i=0;i<COLUMN;i++){
	printf(" %d ",horizontal[i].value);
	}
	printf("\n");
	printf("Angle 45 : "); 
	for(i=0;i<COLUMN;i++){
	printf(" %d ",angle45[i].value);
	}
	printf("\n");
	printf("Angle 135 : ");
	for(i=0;i<COLUMN;i++){  
	printf(" %d ",angle135[i].value); 
	}
		 
    	printf("\n");
	 
   

}



void viewtable(int tab_home[][COLUMN]){
        
    int i,j;
    for(i=ROW-1;i>=0;i--){
        printf(" | ");
        for(j=0;j<COLUMN;j++){
            if(tab_home[i][j]==-1){
                printf("    ");
            }
            else{
            printf(" %d  ",tab_home[i][j]);
            }
        
        }
        printf(" | ");
        printf("\n");
    
    }
    printf("\n");


}

void calculateSomme(int tab[][COLUMN],int rowChercher,int columnChercher,int *result){
    int i,j;
    int angle45=rowChercher-columnChercher;
    int angle135=-rowChercher-columnChercher;
    
    for(i=ROW-1;i>=0;i--){
        
        for(j=0;j<COLUMN;j++){
            if(j==columnChercher){
                if(tab[i][j] != -1){
                result[0]=result[0]+tab[i][j];
                }
            }
             if((i-j)==angle45){
                if(tab[i][j] != -1){
                result[1]=result[1]+tab[i][j];
                }
            }
             if((-i-j)==angle135){
                if(tab[i][j] != -1){
                result[2]=result[2]+tab[i][j];
                }
            }
        
        }       
    
    }

}

