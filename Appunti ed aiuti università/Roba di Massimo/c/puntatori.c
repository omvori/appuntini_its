#include <stdio.h>
int main(){
    //tipo_dato *nome_puntatore. Il tipo di dato è dello stesso tipo dell'elemento a cui il puntatore punterà. Il puntatore per sè non ha un tipo
    int x=5;
                 // inizializzazione puntatore
    int *p = &x; // & serve per riferirsi all'indirizzo di memoria dell'elemento (x).
    printf("%d",*p); //stampa il valore associato a quell'indirizzo di memoria

    *p=4; // quando modifico il valore del puntatore modifico sto modificando il valore della variabile a cui punto
    //------------------------------
    int i = 10;
    int *j=&i;
    printf("%p",j); //%p stampa l'indirizzo, in questo caso, dell'elemento a cui j punta 
    return 0;
}