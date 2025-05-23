#include <stdio.h>
int main(){
    int a1[5]={1,2,3,4,5};
    int a2[3]={6,7,8};
    int n=sizeof(a1)/sizeof(int); //numero elementi di a1
    int m=sizeof(a2)/sizeof(int); //numero di elementi di a2
    int a3[n+m];                  //creazione array di dimensione di a1+a2
    for(int i=0;i<n;i++){ //for per assegnare i valori del primo array
        a3[i]=a1[i];
    }
    for(int i=0;i<m;i++){ //for per assegnare i valori del secondo array
        a3[n+i]=a2[i];    //n+i perchè le prime n.posizioni sono gli elementi di a1

    }
    for(int i=0;i<n+m;i++){ //stampa
        printf("%d", a3[i]);
    }


}