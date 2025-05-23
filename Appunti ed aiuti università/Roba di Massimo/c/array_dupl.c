#include <stdio.h>
 
int main() {
    // Dichiarazione e assegnamento di un array con duplicati
    int numeri[8] = {1, 2, 3, 2, 4, 3, 5, 6};
    int nuovi_numeri[8];
    int n = 0; // Numero di elementi unici
 
    // Rimozione dei duplicati
    for (int i = 0; i < 8; i++) {
        int duplicato = 0;
 
        // Verifica se l'elemento è già presente in nuovi_numeri
        for (int j = 0; j < n; j++) {
            if (numeri[i] == nuovi_numeri[j]) {
                duplicato = 1;
                break;
            }
        }
 
        // Se non è un duplicato, aggiungi a nuovi_numeri
        if (!duplicato) {
            nuovi_numeri[n++] = numeri[i];
        }
    }
 
    // Stampa degli elementi senza duplicati
    printf("Array senza duplicati: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nuovi_numeri[i]);
    }
    printf("\n");
 
    return 0;
}