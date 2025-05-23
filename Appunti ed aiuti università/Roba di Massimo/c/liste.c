#include <stdio.h>
#include <stdlib.h>
//LISTA SEMPLICE
struct nodo{          //una lista è formata da strutture concatenate legate da puntatori.L'ultimo puntatore punta a NULL
    int elemento;
    struct nodo* successivo; //il puntatore punta al nodo successivo. Lo struct davanti serve per dire che punta ad uno struct
};
//LISTA DOPPIA
struct nodo2{
    int elemento;
    struct nodo2* successivo; //punta al nodo successivo
    struct nodo2* precedente; //punta al nodo precedente
};
//Nelle LISTE CIRCOLARI l'ultimo puntatore punta al primo nodo della lista anzichè a NULL

//Nelle LISTE CIRCOLARI DOPPIE si può scorrere una lista in entrambe le direzioni

//la funzione free() libera la memoria a cui un puntatore punta, non modifica il valore di quest'ultimo

int main(){
    struct nodo *lista; //dichiarazione nuova lista. Sarebbe un puntatore alla struttura nodo
}