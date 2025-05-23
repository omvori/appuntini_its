#include <stdio.h>
#include <stdlib.h>

// Funzione che genera tutte le sequenze binarie di lunghezza n
void genera_sequenze_binarie(int n) {
    // Crea un array di interi di dimensione n
    int sequenza[n];

    // Inizializza l'array con tutti gli zeri
    for (int i = 0; i < n; i++) {
        sequenza[i] = 0;
    }

    // Genera tutte le sequenze binarie di lunghezza n
    while (1) { 
        // Stampa la sequenza binaria corrente
        for (int i = 0; i < n; i++) {            
            printf("%d", sequenza[i]);
        }
        printf("\n");

        // Incrementa la sequenza binaria corrente
        int i = n - 1;
        while (i >= 0 && sequenza[i] == 1) {         
            sequenza[i] = 0;                        //se incontra un 1 lo trasforma in 0 e il suo bit a sinistra diventa 1
            i--;
        }
        if (i < 0) {
            break;
        }
        sequenza[i] = 1;
    }
}

// Funzione principale
int main() {
    // Chiede all'utente di inserire la lunghezza delle sequenze binarie da generare
    int n;
    printf("Inserisci la lunghezza delle sequenze binarie da generare: ");
    scanf("%d", &n);

    // Genera tutte le sequenze binarie di lunghezza n
    genera_sequenze_binarie(n);

    return 0;
}