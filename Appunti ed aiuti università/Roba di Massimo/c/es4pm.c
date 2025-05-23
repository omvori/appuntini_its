#include <stdio.h>
#include <stdlib.h>
void stampaArray(int *array, int size){ //prende in input un puntatore/array e la sua dimensione
  printf("Array: ");
  for (int i=0; i< size; i++){
  	printf("%d_",array[i]);
  }
  printf("\n");
}
int main(){
    int *arr=malloc(10*sizeof(int)); //allocazione dinamica di memoria per un array di 10 interi
    int dimensione_corrente=0;
    int dim_max=10;
    while(1){
        int input;
        if (scanf("%d",&input)!=1){   //verifica che l'input è un intero (input!=tipo di 1)
            break;                    //l'input non è un numero
        }
        if(dimensione_corrente==dim_max){ //aumento la dimensione massima se si arriva al limite fissato
            dim_max+=5;
            arr=realloc(arr,10*sizeof(int));
        }
        arr[dimensione_corrente]=input;
        dimensione_corrente++;                //aumento anche la dimensione corrente 
        stampaArray(arr,dimensione_corrente);  //stampa
    }
    free(arr);
    return 0;

}