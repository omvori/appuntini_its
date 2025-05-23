#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

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

int main(int n, char *args[]){
     printf("n = %d\n",n); 
    printf("Array = { ");
    for (int i=1 ; i < n ; i++){
        printf("%s ",args[i]);
    } 
    printf("}\n");

    int numero;
    int somma = 0;
    for (int i=1 ; i < n ; i++){
        str_to_int(args[i] , &numero);
        somma = somma + numero;
        printf("%d\n",numero);
    } 

    printf ("La somma dei numeri interi e' %d",somma);
}
