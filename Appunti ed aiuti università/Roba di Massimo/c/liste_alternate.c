#include<stdio.h>
#include <stdlib.h>

struct nodo{  //creo una struttura nodo che contiene 3 elementi
    float info;   //un valore info (il numero vero e proprio)
    struct nodo*prec;  //un riferimento ad un altra struct nodo precedente
    struct nodo*succ;    //un riferimento ad una altra struct successivo
};
typedef struct nodo nodo;  //definisco la struct con il nome nodo per non ripetere sempre struct nodo ma solo nodo

//inizializzazione di tutte le funzioni che verranno poi definite dopo il main:
nodo * lista_vuota();   
nodo * lista_in0(nodo * lista,float valore);
nodo *lista_in1(nodo* x, float e);
void stampa_lista(nodo* lista);
nodo *lista_get(nodo *x, int posizione);
nodo *lista_in(nodo *x, int posizione, float e);
nodo *lista_out0(nodo *x );
nodo *lista_out1(nodo *x);
nodo *lista_out(nodo *x, int posizione);
int lista_len(nodo *lista );
nodo *liste_alternate(nodo *a, nodo *b);

nodo * lista_vuota(){   
    /*
    funzione che restituisce un nodo che si chiama lista_vuota
    */

    return NULL;  //restituisce una lista vuota quindi un nodo con tutti gli elemnti NULL
}

nodo * lista_in0(nodo * lista,float valore){ 
    /*
    funzione che aggiunge elementi in testa alla lista, quindi nel primo nodo che la compone
    */
   
    //creo un nuovo nodo
    nodo * n= malloc(sizeof(nodo));  //definizione e allocazione memoria ad un puntatore n di tipo nodo
    n->info = valore;  //definisco info di n con il valore inserito nella funzione
    n->prec=NULL;  //dato che è l'elemento in testa non ho alcun tipo di valore precedente quindi NULL
    n->succ=NULL;  //non conosciamo ancora il valore successivo quindi anche succ vale NULL

    //aggiungo il nodo in testa alla lista
    n->succ = lista;
    if (lista!=NULL){
        lista->prec=n;
    }
    lista=n;

    //ritorno la lista aggiornata
    return lista;
}

nodo *lista_in1(nodo* x, float e){   
	/*
    aggiunge al nodo puntato dalla lista x l'elemento e in posizione 1 
    (non come primo elemento, come testa,  ma come secondo elemento)
    */
    nodo *n, *p;  
	
	if ( x == NULL )  //se la lista input è vuota esco dalla funzione con return NULL
		return NULL;
	
	p = x->succ;  
	
	n = malloc(sizeof(nodo));  
	
	n->info = e;  
	n->prec = x;
	n->succ = p;
	
	x->succ = n;
	if ( p != NULL)  //se c'era un valore precedente allora lo riassegno con n (tutto il nodo)
		p->prec = n;
		
	return x;
}

void stampa_lista(nodo * lista){ 
    /*
    stampa la lista che prende in input
    */

	nodo * iteratore=lista;  //def di un nuovo nodo chiamato iteratore che è uguale alla lista di input per poter effettuare operazioni senza perdere dati

    printf("lista = "); //estetica
    while(iteratore!=NULL){   // fino a che la lista (iteratore) NON è vuota (!NULL) effettua le operazioni
        printf("%f -> ",iteratore->info);   //stampa l'elemento info di iteratore (della lista di input)
        iteratore = iteratore -> succ;  //modifico iteratore prendendo il valore successivo, facendolo quindi diventare la nuova info
    }
    printf(" null\n"); //estetica
}

nodo *lista_get(nodo *x, int posizione){
	/*
	 * ritorna il nodo che si trova nella posizione specificata all'interno della lista x.
	 * Se tale nodo non esiste, la funzione ritorna NULL.
	 * 
	*/ 
	nodo *p = x;
	int c = 0;
	
	while( p != NULL && c != posizione ) {
		p = p->succ;
		c++;
	}
	
	return p;
}

nodo *lista_in(nodo *x, int posizione, float e){
    /*
    inserisce l'elemento e nella posizione specificata della lista x
    */

	nodo *p;
	
	if (posizione == 0)
		return lista_in0(x, e);
	
	p = lista_get(x, posizione-1);
	
	if (p == NULL)
		return x;
		
	p = lista_in1(p, e);
	return x;
}

nodo *lista_out0(nodo *x ){
    /*
    elimina il primo nodo della lista di input
    */

	nodo *t = x;
	
	if ( x == NULL )
		return NULL;
		
	x = t->succ;
	
	if (x != NULL)
		x->prec = NULL;
		
	free(t);
	
	return x;
}

nodo *lista_out1(nodo *x){
    /*
    elimina il secondo nodo della lista inserita come input
    */

	nodo *t;
	
	if ( x == NULL || x->succ == NULL )
		return x;
		
	t = x->succ;
	
	x->succ = t->succ;
	if (t->succ != NULL)
		t->succ->prec = x;
		
	free(t);
	
	return x;
	
}

nodo *lista_out(nodo *x, int posizione){
    /*
    elimina il nodo nella posizione specificata nella lista x
    */

	nodo *p;
	
	if(posizione == 0)
		return lista_out0(x);
		
	p = lista_get(x, posizione-1);
	
	p = lista_out1(p);
	
	return x;
}

int lista_len(nodo *lista ){
    /*
    restituisce il numero di elementi in lista
    */
    int i=0;
    while (lista_get(lista , i) != NULL){
        i++;
    }

    return i;
}
/////////////////////////////////////////////////////7
nodo *liste_alternate(nodo *a, nodo *b){   //date due liste ne viene creata una che ne alterna i valori
    nodo *l=lista_vuota();
    int a_c=0; //contatatore per posizione in lista a
    int b_c=0; //contattore per posizione in lista b
    for(int i=0;i<lista_len(a)+lista_(b);i++){ 
        if(i%2==0){   //se i è pari inserisco il valore della lista a
            l=lista_in(l,i,lista_get(a, a_c)->info);
            a_c++;
        }
        else {       //se i è dispari inserisoc il valore della lista b
            l=lista_in(l,i,lista_get(b, b_c)->info);
            b_c++;
        }
        
        
        return l;  
    }

}