#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*Si scriva una funzione avente il seguente prototipo:
char *str_cat(char *a, int n, char *b);
dove a e b sono due stringhe e n è la dimensione dell'array contenente a . La funzione deve
concatenare b ad a , modificando a . Restituisce la stringa a modificata.*/
char *str_cat(char *a, int n, char *b){
    int l_b=strlen(b); //trovo la lunghezza della stringa b
    char *a2=realloc(a, n+l_b+1); //aumento la memoria di a così che abbia la lunghezza necessaria per contenere entrambe le stringhe + il carattere finale '\0'
    if(a2 == NULL) {
    // Mi assicuro che l'aggiornamento della memoria di a avvenga
    } else {
    a = a2;    
    }                                      
    for (int i = 0; i < l_b; i++){
        a[n+i]=b[i];               //aggiungo i caratteri di b alla fine della stringa a
    }
    a[n+l_b]='\0'; //aggiungo il carattere di terminazione della stringa
    for(int i=0;i<n+l_b;i++){
        printf("%c",a[i]);
    }
    return a;   
}
// la complessità spaziale è uguale a O(n+m) dove n+m è la somma delle lunghezze rispettivamente della stringa di a e di b.
// La comlessità temporale è uguale a quella spaziale perchè modifichiamo la lista a affinchè abbia la lunghezza pari alla somma tra la lunghezza di e la lunghezza di b
int main() {
    char *a = malloc(50 * sizeof(char)); // Allocazione dinamica della memoria per la stringa a
    strcpy(a, "pooooooorcooooo"); // Inizializzazione della stringa a
    char *b = "diooooo"; // Stringa b da concatenare a a
    a = str_cat(a, strlen(a), b); // Chiamata alla funzione str_cat
    // Stampa la stringa a dopo la concatenazione
    free(a); // Libera la memoria allocata per a
    return 0;
}