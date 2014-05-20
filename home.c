#include <stdio.h>
#include <stdlib.h>

#include <libsx.h>

/*
 * compile et execute
 * gcc -Wall -o calc calc.c -lsx && ./calc
 */

/*
 * role : afficher des widgets
 */


/*
 * role : afficher le contenu d'un fichier
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

void calculateSomme(int row,int column,int tab[][column],int rowCherche,int columnCherche,int *result){
    int i,j;
    int angle45=rowCherche-columnCherche;
    int angle135=-rowCherche-columnCherche;
    
    for(i=row-1;i>=0;i--){
        
        for(j=0;j<column;j++){
            if(j==columnCherche){
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
                        printf("Select case number\n");
                        printf("Row's number : ");
                        scanf("%d",&rowChercher);
                        
                        printf("Column's number : ");
                        scanf("%d",&columnChercher);
                        
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
