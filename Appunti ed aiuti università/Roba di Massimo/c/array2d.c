#include<stdio.h>
int main(){
   
   int disp[2][3]; //array a due dimensioni
   int i, j;
   for(i=0; i<2; i++) {
      for(j=0;j<3;j++) {
         printf("Inserisci l'elemento[%d][%d]:", i, j); //inserimento elementi
         scanf("%d", &disp[i][j]);
      }
   }
   //Stampa
   printf("Array a due dimensioni:\n");
   for(i=0; i<2; i++) {
      for(j=0;j<3;j++) {
         printf("%d ", disp[i][j]); //stampa elementi
         if(j==2){
            printf("\n");           //se è arrivato a fine riga va a capo così da stampare una matrice
         }
      }
   }
   return 0;
}
