#include <stdio.h>
 
int main() {
    // Dichiarazione e assegnazione di un array
    int numeri[5] = {1, 2, 3, 4, 5};
    int temp = numeri[0]; //ci teniamo da parte il primo elemento perchè dovrà diventare l'ultimo dell'array
 
    // Rotazione a sinistra di un passo
    for (int i = 0; i < 4; i++) {
        numeri[i] = numeri[i + 1]; //spostamento di tutti gli elementi verso sinistra di 1 passo
                                   //adesso l'array=[2,3,4,5,5];
    }
 
    // Assegnazione del primo elemento alla fine
    numeri[4] = temp;   //array=[2,3,4,5,1]
 
    // Stampa dell'array dopo la rotazione
    printf("Array dopo la rotazione: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeri[i]);
    }
    printf("\n");
 
    return 0;
}