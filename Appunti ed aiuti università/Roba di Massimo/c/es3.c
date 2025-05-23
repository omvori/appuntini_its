#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    printf("Elementi nell'array\n"); //grandezza dell'array
    scanf("%d",&n);
    int arr[n];                      //inizializzazione array 
    printf("\nInseriscili\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);        //inserimento elementi dell'array
    }
    printf("\nSTAMPA:\n");
    for(int i=0;i<n;i++){
        int *p=&arr[i];            //stampa valori tramite puntatore
        printf("%d\n",*p);
    }
}