#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct punto{
    float x;
    float y;
};
//calcolo del perimetro dati n punti in input

int main(){
    int numero;
    float perimetro=0;
    printf("Inserire numero di punti:\n");
    scanf("%d",&numero);
    struct punto arr[numero];   //uso un array per memorizzare un numero indefinito di input dell'utente
    for (int i=0; i<numero;i++){
        printf("Inserisci coordinate del numero:\n");
        scanf("%f",&arr[i].x);
        scanf("%f",&arr[i].y);
    }
    for (int n=0;n<numero-1;n++){
        perimetro=perimetro+sqrt(pow(arr[n+1].x-arr[n].x,2)+pow(arr[n+1].y-arr[n].y,2)); //manca da calcolare la distanza tra il primo e l'ultimo punto dato
        printf("%f\n",perimetro);

    }     

    }
