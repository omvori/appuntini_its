#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct nodo{
    float info;
    struct nodo *prec,*succ;
};
typedef struct nodo nodo;
nodo *coda_new(){
    return NULL;
}
nodo *coda_in(nodo* x,float e){ //il nodo x non è il primo ma l'ultimo aggiunto
    nodo *n=malloc(sizeof(nodo));
    n->info = e; 
    (*n).succ = x;                  //il puntatore succ del nuovo nodo punta ad x che lo precede
	n->prec = NULL;                 //visto che il nuovo nodo è in cima alla lista non c'è nessun predente e quindi assegnamo NULL
	if ( x != NULL )                //se la lista non era vuota imposta il campo prec sul nodo appena creato
		(*x).prec = n;
    return n;   
}

float coda_get(nodo*x){ //il nodo x è l'ultimo aggiunto.L'elemento più vecchio si trova in cima alla coda dove succ non punta a niente
    nodo *p=x;
    while((*p).succ!=NULL){
        p=(*p).succ;
    }
    printf("%f",p->info);
}
nodo* coda_del(nodo*x){//x è l'ultimo nodo aggiunto ed elimina il nodo con l'elemento più vecchio
    nodo *p=x;
    while((*p).succ!=NULL){
        p=(*p).succ;
    }
    free(p);

}


    