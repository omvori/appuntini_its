#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *a = "Programma C";
    int len = strlen(a);      //lunghezza stringa

    int j = 0;                
    char **arr = malloc(10 * sizeof(char*)); //creazioni array di puntatori

    for (int i = 0; i < len; i++) {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') { //conteggio numero di vocali della stringa
            j++;
        }
    }
    j++; //aumento j di uno per l'ultimo puntatatore che punterà a NULL
    arr = realloc(arr, j * sizeof(char*)); //ridimensionamento array di puntatori in base al numero di vocali trovate

    j = 0;

    for (int i = 0; i < len; i++) { 
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') {
            arr[j] = &a[i]; //puntatore j-esimo punta alla vocale
            j++;
        }
    }
    arr[j+1]=NULL;
    for (int i = 0; i < j; i++) {
        printf("Indirizzo carattere vocale %c: %p\n", *arr[i], (void *)arr[i]);
    }
    return 0;
}