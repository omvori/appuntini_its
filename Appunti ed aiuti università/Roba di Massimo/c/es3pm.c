#include <stdio.h>
#include <stdlib.h>
//scrivi qui la funzione array_di_uno
int array_uno(int x[], int g){  //tanti 1 quanto la somma degli elementi dell'array in input
    int s=0;                    //g è il numero di elementi dell'array
    int *p=x;                   //puntatore che punta la primo elemento dell'array
    
    for (int i=0;i<g;i++){
        s+=*(p+i);             //scorro l'array tramite il puntatore    
    }
    printf("\n");
    printf("somma degli elementi: %d\n",s);
    printf("----------\n");
    
    int b[s];
    for (int i=0;i<s;i++){
        b[i]=1;
        printf("%d",b[i]); 
    }
  
}
int main(){
	// definisco gli array
    int a[4]={1,2,3,4};
    int n=sizeof(a)/sizeof(int);
    array_uno(a,n);    
}