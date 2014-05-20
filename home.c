#include <stdio.h>
#include <stdlib.h>

#include <libsx.h>

/*
 * compile et execute
 * make && ./home
 */

/*
 * role : file to replicate mojette game
 */

void readGamefile(char *f){
    
    
   char ch;
   FILE *fp;
 
   fp = fopen(f,"r"); 
 
   if( fp == NULL )
   {
        perror(f);    
        fprintf(stderr,"Error,file cannot be opened\n");
        exit(1);
        
   }
 
   printf("The contents of %s file are :\n ", f);
   
   while( ( ch = fgetc(fp) ) != EOF ){
       
       if(ch == '1'){
       printf("  ");    
       }
       if(ch == 'a'){
       printf("%c ",ch);    
       }
       if(ch == '\n'){
       printf("%c ",ch);    
       }
       
   }
   
    fclose(fp);        
    printf("\n");  
   
    
}

/*
 * Role: lire a partir un fichier le mask pour jouer le jeu 
 * (Ex: 'a' pas joueable, autre de 'a' joueable)
 */

void readGamefile2(char *f,int column,int row,int tab[][column]){
    
    
   char ch;
   FILE *fp;
   int i=row-1;
   int j=0;
   
   
   fp = fopen(f,"r"); 
 
   if( fp == NULL ){
        perror(f);    
        fprintf(stderr,"Error,file cannot be opened\n");
        exit(1);
        
   }
 
   
   
   while( ( ch = fgetc(fp) ) != EOF ){
              if(ch == 'a'){
               tab[i][j]=-1;
               j++;
              }
              else{
                   if(ch == '\n'){
                   i--;
                   j=0;
                   }
                   else{
                   tab[i][j]=ch-'0';
                   j++;
                   }   
              }
               
               
        
    
    }   
       
       
   
   
    fclose(fp);        
    printf("\n");  
   
    
}

/*
void calculerVertical(int column,int row,int tab[][column]){
for(i=0;i<row;i++){
        printf(" | ");
        for(j=0;j<column;j++){
            if(tab[i][j]==-1){
                printf("   ");
            }
            else{
            printf(" %d ",tab[][j]);
            }
        
        }
        printf(" | ");
        printf("\n");
    
    }
}
*/



void calculateSomme(int row,int column,int tab[][column],int rowChercher,int columnChercher,int *result){
    int i,j;
    int angle45=rowChercher-columnChercher;
    int angle135=-rowChercher-columnChercher;
    
    for(i=row-1;i>=0;i--){
        
        for(j=0;j<column;j++){
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



void calculateResult(int row,int column,int tab[][column],int *result,int rowChercher,int columnChercher){
 
    if(tab[rowChercher][columnChercher]== -1){
    printf("Le matrice n'existe pas \n");
    printf("Désolé \n");
    }
    
    /**try2 untuk git,tgk jadi x*/
    
    else{
    calculateSomme(row,column,tab,rowChercher,columnChercher,result);
    printf("Vertical = %d\n",result[0]);
    printf("Angle 45 = %d\n",result[1]);
    printf("Angle 135 = %d\n",result[2]);
    printf("\n");
    }
    



}

void viewTable(int row,int column,int tab[][column]){
        
        int i,j;
        
        readGamefile2("game.txt",column,row,tab);
    
    for(i=row-1;i>=0;i--){
        printf(" | ");
        for(j=0;j<column;j++){
            printf(" %d%d ",i,j);

        }
        printf(" | ");
        printf("\n");
    
    }
    
    for(i=row-1;i>=0;i--){
        printf(" | ");
        for(j=0;j<column;j++){
            if(tab[i][j]==-1){
                printf("    ");
            }
            else{
            printf(" %d  ",tab[i][j]);
            }
        
        }
        printf(" | ");
        printf("\n");
    
    }
    printf("\n");


}


void viewSelection(int row,int column,int tab[][column],int rowChercher,int columnChercher){
    int i,j;
    
    int angle45=rowChercher-columnChercher;
    int angle135=-rowChercher-columnChercher;
    
    printf(" **************************** \n");
    printf(" Vous avez sélectionné la case : %d%d \n",rowChercher,columnChercher);
    
    for(i=row-1;i>=0;i--){
        
        printf(" | ");
        
        for(j=0;j<column;j++){
            
            if(tab[i][j] == -1){
                    printf(" ** ");
                }
            else{
                if((j==columnChercher)||((i-j)==angle45)||((-i-j)==angle135)){
                    printf(" xx ");
                }
                else{
                    printf(" ** ");
                }
            
            }
        
        }  
        printf(" | ");
        printf("\n");
    
    }

}

void viewQuestion(int row,int column,int tab[][column]){
    int i,j; 
    int horizontal[7]={0,0,0,0,0,0,0};
    
    /*angle45[0] est le plus bas,vers le plus haut*/
    int angle45[7]={0,0,0,0,0,0,0};
    int angle135[7]={0,0,0,0,0,0,0};
   
    for(i=row-1;i>=0;i--){       
        for(j=0;j<column;j++){
                if(tab[i][j] != -1){
                        switch(j){
                            case 0:
                                horizontal[0]=horizontal[0]+tab[i][j];
                                break;
                            case 1:
                                horizontal[1]=horizontal[1]+tab[i][j];
                                break;
                            case 2:
                                horizontal[2]=horizontal[2]+tab[i][j];
                                break;
                            case 3:
                                horizontal[3]=horizontal[3]+tab[i][j];
                                break;
                            case 4:
                                horizontal[4]=horizontal[4]+tab[i][j];
                                break;
                            case 5:
                                horizontal[5]=horizontal[5]+tab[i][j];
                                break;
                            case 6:
                                horizontal[6]=horizontal[6]+tab[i][j];
                                break;
                        }
                        switch(i-j){
                            case -4:
                                angle45[0]=angle45[0]+tab[i][j];
                                break;
                            case -3:
                                angle45[1]=angle45[1]+tab[i][j];
                                break;
                            case -2:
                                angle45[2]=angle45[2]+tab[i][j];
                                break;
                            case -1:
                                angle45[3]=angle45[3]+tab[i][j];
                                break;
                            case 0:
                                angle45[4]=angle45[4]+tab[i][j];
                                break;
                            case 1:
                                angle45[5]=angle45[5]+tab[i][j];
                                break;
                            case 2:
                                angle45[6]=angle45[6]+tab[i][j];
                                break;
                        }
                        switch(-i-j){
                            case -8:
                                angle135[0]=angle135[0]+tab[i][j];
                                break;
                            case -7:
                                angle135[1]=angle135[1]+tab[i][j];
                                break;
                            case -6:
                                angle135[2]=angle135[2]+tab[i][j];
                                break;
                            case -5:
                                angle135[3]=angle135[3]+tab[i][j];
                                break;
                            case -4:
                                angle135[4]=angle135[4]+tab[i][j];
                                break;
                            case -3:
                                angle135[5]=angle135[5]+tab[i][j];
                                break;
                            case -2:
                                angle135[6]=angle135[6]+tab[i][j];
                                break;
                        }
                    }         
        }  
        
    }
    printf("Horizontal : ");
    for(i=0;i<7;i++){
        printf(" %d ",horizontal[i] );
    }
    printf("\n");
    printf("Angle45 : ");
    for(i=0;i<7;i++){
        printf(" %d ",angle45[i] );
    }
    printf("\n");
    
    printf("Angle135 : ");
    for(i=0;i<7;i++){
        printf(" %d ",angle135[i] );
    }
    printf("\n");

}

void playGame(int row,int column,int tab[][column],int *result){
    int choix;
    int rowChercher,columnChercher;
    do{
                        result[0]=0;
                        result[1]=0;
                        result[2]=0;
                        printf("Hi please play \n");
                        printf("Press 1 to play \n");
                        printf("Press 2 to quit\n");
                        printf("Choice :");
                        scanf("%d",&choix);
           switch(choix){
               case 1: 
                        
                        viewTable(row,column,tab);
                        viewQuestion(row,column,tab);
                        printf("Select case number\n");
                        printf("Row's number : ");
                        scanf("%d",&rowChercher);
                        
                        printf("Column's number : ");
                        scanf("%d",&columnChercher);
                        
                        viewSelection(row,column,tab,rowChercher,columnChercher);
                        calculateResult(row,column,tab,result,rowChercher,columnChercher);
                        
                 break;
               case 2: break;
               default :
                   printf("Wrong number \n");   
                break;
                   
            }
    
    
    }while(choix != 2);

}









int main(int argc,char **argv){
  
    int row =6;
    int column =7;
    int tab[row][column];
    int result[3]={0,0,0};
   
    playGame(row,column,tab,result);
    
    
    
    return EXIT_SUCCESS;

}
