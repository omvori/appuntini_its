#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct d_item {    
	char *k;    //puntatpre a una stringa che rappresenta la chiave 
	float v;    //valore associato alla chiave
};
typedef struct d_item d_item;

struct nodo {        //lista
	d_item info;     //un elemento del dizionario, composto da chiave e valore
	struct nodo *succ;  //puntatore al nodo successivo  
};
typedef struct nodo nodo;

struct dict {   //il dizionario è un array di liste, le liste contengono i puntatori prec e succ mentre l'informazione del nodo è composto da chiave e valore associati tra loro
	nodo **a;   //puntatore che punta ad un array di puntatori a nodi, rappresenta la tabella hash
	int m; // numero di liste(dimensione dell'array)
	int n; // numero di elementi del dizionario
};
typedef struct dict dict;

int h(char*, dict);
dict dict_init(int);
dict dict_update(dict, d_item);
nodo *lista_cerca_k(nodo*, char*);
nodo *lista_in0(nodo*, d_item );
void dict_mostra(dict);
void lista_mostra(nodo*);


int main(int n, char *args[]){
	dict d = dict_init(3);
	int i;
	d_item e;
	
	for (i = 1; i < n; i++){
		e.k = args[i];
		e.v = i;
		d = dict_update(d, e); 
	}
	
	dict_mostra(d);
}


int h(char *x, dict d){  //prende in input un puntatore a chiave e restituisce la sua posizione nell'array di liste del dizionario
	int out = 0;         //variabile per accumulare risultato dello XOR
	int i = 0;           //indice per accedere ai caratteri della chiave
	
	while( x[i] != '\0'){  //finchè non viene raggiunto il terminatore di stringa "\0"
		out = x[i]^out;    //"^" equivale all'operatore XOR
		i++;               //passare al carattere successivo
	}
	
	return out % 11;      //restituisce il modulo di d.m per assicurarsi che l'hash rientri tra 0 e d.m
}

dict dict_init(int m){     //creazione di un dizionario vuoto
	dict d;               //crea un dizionario
	int i;
	
	d.a = malloc(m*sizeof(nodo*));    //alloca la memoria per l'array di liste di dimensione m. d.a punterà ad un array di puntatori a nodo
	d.m = m;                          //numero di liste del dizionario
	d.n = 0;                          //il dizionario è stato appena creato e quindi il numero di elementi è uguale a 0 
	for(i = 0; i < m; i++){           //ogni elemento dell'array di liste è NULL perchè ogni lista è vuota
		d.a[i] = NULL;
	}
	
	return d;
}

dict dict_update(dict d, d_item e){  //prende in input un dizionario e una coppia chiave valore
/*
 * Se e.k e' nel dizionario ne modifica il valore in e.v.
 * Altrimenti inserisce in d la nuova coppia e
 * 
 * */
	nodo *p;               
	int lis = h(e.k, d);   //calcola l'indice della lista in cui dovrebbe appartenere la chiave
	
	
	p = lista_cerca_k(d.a[lis], e.k);  //cerca nella lista corrispondente alla chiave il nodo che contiene la chiave cercata
	
	if ( p == NULL ) { // la chiave non è nel dizionario
		/*
		 * inseriamo e in d
		 * */
		 d.a[lis] = lista_in0(d.a[lis], e); //inserisco un nuovo nodo all'inzio della lista con nuova coppia chiave valore
		 d.n++;                             //incrementa il numero di elementi nel dizionario
	} else {
		/* se presente allora
		 * aggiorno il valore associato a e.k
		 * */
		p->info.v = e.v;
	}
	
	return d;
}


nodo *lista_cerca_k(nodo *x, char *k){
	/*
	 * Cerca una chiave k nel dizionario e ritorna il puntatore al nodo contenente l'item con chiave k, 
	 * oppure NULL se k non e' una chiave del dizionario
	 * */
	nodo *p = x;    //inizializza puntatore alla testa della lista
	
	while ( p != NULL ){   //continua finchè il nodo non è vuoto
		if ( strcmp(p->info.k, k) == 0 ) {   //confronta la chiave del nodo corrente (info.k) con la chiave cercata(k). STRCMP restituisce 0 se le stringhe sono uguali
			return p;
		}
		p = p->succ;          //il puntatore p passa al nodo successivo
	}
	
	return NULL;
}
dict dict_del(dict d, d_item e, char*k){ //data una chiave elimina la coppia chiave valore dal dizionario
    /*
 * Se k e' una chiave del dizionario d, elimina da d la coppia con chiave k.
 * Ritorna il dizionario modificato
 * 
 * */
	nodo *p; 
	int lis = h(k, d);  /*la lista in cui dovrebbe stare la coppia con chiave k*/
	d_item e;
	
	p = lista_cerca_k(d.a[lis], k);
		
	if ( p != NULL ) { // la chiave è nel dizionario
		/*
		 * Visto che non interessa mantenere un particolare ordine tra
		 * gli elementi delle liste di trabocco, scambia il contenuto
		 * del nodo puntato da p con il primo nodo della lista in modo
		 * da cancellare in testa.
		 * 
		 * */
		e = p->info;
		p->info = d.a[lis]->info;
		d.a[lis]->info = e;
		
		d.a[lis] = lista_out0(d.a[lis]);
		d.n--;
	}
	
	return d;
}
dict dict_resize(dict d, int new_m){ //nuovo dizionario con dimensione diversa
	dict d1 = dict_init(new_m);
	int lis;
	nodo *p;
	
	for (int i = 0; i < d.m; i++){
		while(d.a[i] != NULL){
			/* lis e' l'indice della lista in d1 dove inserire
			 * il nuovo elemento*/
			lis = h(d.a[i]->info.k, d1);
			/* nell'insierimento in d1 non e' necessario eseuire la
			 * ricerca in quanto le chiavi inserite sono tutte uniche in quanto stiamo inserendo elementi da un dizionario*/
			d1.a[lis] = lista_in0(d1.a[lis], d.a[i]->info);
			d.a[i] = lista_out0(d.a[i]);
		}
	}
	d1.n = d.n;
	free(d.a);
	return d1;
}

nodo *lista_out0(nodo *x ){ //canacella il primo nodo
	/*
	 * Cancella il primo nodo della lista. Rispetto alla versione vista
	 * nelle lezioni precedenti questa non deve gestire il campo prec
	 * che in questo caso non e' presente
	 *  
	 * */
	nodo *t = x;   //crea un puntatore a nodo
	
	if ( x == NULL )
		return NULL;
		
	x = t->succ;
		
	free(t);
	
	return x;
}

nodo *lista_in0(nodo* x, d_item e){  //inserisci un nuovo nodo all'inzio di una lista
	nodo *n = malloc(sizeof(nodo));  //crea nuovo nodo
	
	n->info = e; //la info del nuovo nodo n è "e" 
	n->succ = x; //il puntatore succ punterà al vecchio nodo in cima alla lista
	             // non vi è nessun prec perchè il nodo è in cima alla lista
	
	return n;
}


void dict_mostra(dict d){ //mostra il dizionario
	int i;
	
	for (i = 0; i < d.m; i++){
		printf("%d - ", i);
		lista_mostra(d.a[i]);
	}
}

void lista_mostra(nodo *x){ //mostra la lista
	nodo *p = x;
	
	while( p != NULL ){
		printf("(%s, %.2f) ", p->info.k, p->info.v);
		p = p->succ;
	}
	printf("\n");
}