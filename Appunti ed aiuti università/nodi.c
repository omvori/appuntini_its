    #include <stdio.h>
#include <stdlib.h>
// int main(){


//     nodo f; // f ora ha la struttura : info,succ e prec
    
//     //riempire i campi del nodo
//     f.info = 9; 
//     f.succ = NULL;
//     f.prec = NULL;

//     printf("%d",f.info);

//     nodo *lista; //lista è un puntatore a nodo : 
//     lista = &f;
//     printf("\n%d",lista -> info);
// }
   
   
   //****SPIEGAZIONE****

// nodo *lista 

// lista
//   |
//   V
// +------+
// | NULL |  (o valore indefinito)
// +------+



// lista = (nodo*)malloc(sizeof(nodo));
// 
// lista
//   |
//   V
// +------------------+
// |   indirizzo_nodo | --> +------------+------------+------------+
// +------------------+     |            |            |            |
//                          +------------+------------+------------+





struct Nodo{ //struttura dati nodo
    int info; //campo del valore
    struct Nodo *succ; // succ è un puntatore a nodo per l'elemento successivo
    struct Nodo *prec; //prec è un puntatore a nodo per l'elemento successivo
};
    
typedef struct Nodo nodo;

//funzione che torna una lista vuota
nodo *emptylist(){ //la funzione è un puntatore a nodo sottoforma di funzione,nessun input
    return NULL; //l'output sarà un puntatore a nodo vuoto
}

//funzione per inserire in testa
nodo *inhead(float v, nodo * list){ //la funzione prende il valore da inserire,e la lista di nodi
    
    nodo *n = malloc(sizeof(nodo)); //creazione del nodo vuoto,glielo facciamo puntare da "n"
    //inserimento dei valori nei campi
    n->info = v; 
    n->succ = list;
    n->prec = NULL;
    
    //questa flag vede se la lista è vuota o ha elementi
    if(list != NULL){
      list->prec = n; // rende "n" il primo elemento della lista

    } 

    return n; //ritornerà la lista con il nuovo elemento inserito


    

}

//la funzione stampa la lista di nodi
void printlist(nodo *list){ //input una lista puntata da un puntatore a nodo
    nodo *iteratore = list; //puntatore che scorrerà tutta la lista

    //condizione per far scorrere il puntatore
    while(iteratore!=NULL){  
        printf("%d -> ",iteratore->info); //essendo un puntatore a list,può accedere a tutti i suoi campi
        iteratore = iteratore -> succ; //aggiornamento del puntatore a list,ora punta all'elemento successivo
    }
    printf(" NULL");
}

int main(){
    nodo *l = emptylist(); //puntatore a nodo che crea una lista vuota puntata da l per accedervi
    
    //aggiunta in testa di 2 elementi
    l = inhead(5,l); 
    l = inhead(7,l);
    
    printlist(l);

}