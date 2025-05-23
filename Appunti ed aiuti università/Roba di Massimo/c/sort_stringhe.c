#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
// quale stringa viene prima in ordine alfabetico 

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int i;

    printf("Quante parole vuoi ordinare?\n");
    scanf("%d", &n);

    char *arr[n]; //array di stringhe

    printf("Inserisci le parole:\n");
    for (i = 0; i < n; i++) {
        arr[i] = (char *)malloc(50 * sizeof(char)); //ogni parola può avere max 50 caratteri
        scanf("%s", arr[i]); //inserimento dellaa parola
    }

    // Ordina le parole in base al primo carattere
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {   //bubble sort O(n^2)

            if (arr[j][0] > arr[j + 1][0]) { //confronta il primo carattere dell'elemento [j] dell'array di stringhe
                // Scambia i puntatori alle stringhe
                char *temp = arr[j]; // temp funge da copia per la prima parola che poi cambierà, purtoppo non funziona come python con la doppia assegnazione
                arr[j] = arr[j + 1]; //in caso li scambia come per il bubble_sort
                arr[j + 1] = temp;
            }
        }
    }
    printf("--------\n");
    printf("Parole ordinate:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
        free(arr[i]);
    }

    return 0;
}