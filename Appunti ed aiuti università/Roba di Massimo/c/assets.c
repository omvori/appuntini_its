#include<stdio.h>
#include <stdlib.h>
float abs_val( float x ){ //valore assoluto
	if ( x < 0 ) 
		return -x; /* unica istruzione nel blocco,
					posso omettere le parentesi*/
	else
		return x;
}

float radice2(float x){  //radice senza math.h
	float g = x;
	
	while ( abs_val(g*g - x) > 0.00001 ) {
		g = (g + x/g)/2;
	}

	return g;
}

char *cat(char *x, char *y){
	/*
	 * ritorna una nuova stringa che equivale alla concatenazione di x ed y
	 * 
	 * oppure NULL non e' possibile allocare spazio per la nuova stringa
	 * */
	char *w;
	int n = len(x);
	int m = strlen(y); /* come len, ma nella libriria string  */
	int i;
	
	w = (char*)malloc((n+m+1)*sizeof(char));
	
	if (w != NULL) {
		for(i = 0; i < n; i++){
			w[i] = x[i];
		}
		for(; i < n+m; i++){
			w[i] = y[i-n];
		}
		w[i] = '\0'; /* perche' i e' n+m*/
	}
		
	return w;
}

int str_to_int(char *a, int *q){
/*
 * Converte a in int. Ritorna 0 in caso di errore, 1 in caso di successo.
 * 
 * In caso di successo, l'intero viene scritto in posizione q
 * 
 * */
	
	int p = strlen(a)-1;
	int k = 1;
	
	*q = 0;
	while( p >= 0){
		if (  isdigit(a[p]) ) {
			(*q) += (a[p]-'0')*k;
			p--;
			k *= 10;
			
		} else {
			return 0;
		}
	}
	
	return 1;
	
}

int buble_sort(){
	
    int n[6] = {1 , 28 , 5 , 8 , 3 , -1};
    int ordinata = 1 ; //variabile che vale 0 se non ordinata e 1 se è ordinata

    for (int i=0 ; i<5 ; i++){      //controllo se è già ordinato
        if (ordinata == 1){
            if(n[i] > n[i+1]){
                ordinata = 0;
            }
        }        
    }

    while (ordinata == 0) {   //buble_sort effettivo (operazioni di ordinamento)
        ordinata = 1;
        for (int i = 0; i < 5; i++) {
            if (n[i] > n[i + 1]) {
                // Scambia gli elementi se non sono in ordine
                int temp = n[i];
                n[i] = n[i + 1];
                n[i + 1] = temp;

                ordinata = 0; // L'array non è ancora ordinato completamente
            }
        }
    }

    for (int i=0 ; i<6 ; i++){       //stampa del array ordinato
        printf("%d ", n[i]);     
    }
}
//------------------------------------------
#include <stdlib.h>
#include <stdio.h>

#define max 100

void merge(int a[], int p, int q, int r) {
  int i, j, k=0, b[max];
  i = p;
  j = q+1;

  while (i<=q && j<=r) {
    if (a[i]<a[j]) {
      b[k] = a[i];
      i++;
    } else {
      b[k] = a[j];
      j++;
    }
    k++;
  }
  while (i <= q) {
    b[k] = a[i];
    i++;
    k++;
  }
  while (j <= r) {
    b[k] = a[j];
    j++;
    k++;
  }
  for (k=p; k<=r; k++)
    a[k] = b[k-p];
  return;
}

void mergeSort(int a[], int p, int r) {
  int q;
  if (p < r) {
    q = (p+r)/2;
    mergeSort(a, p, q);
    mergeSort(a, q+1, r);
    merge(a, p, q, r);
  }
  return;
}
