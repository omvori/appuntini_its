#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// struct punto{
//     float a;
//     float b;
// };

// void printpoint(struct punto x){
//     printf("%.2f ",x.a);
//     printf("%.2f ",x.b);
// }


// int main(){
//     struct punto a1;
//     struct punto b1;

//     a1.a = 3;
//     a1.b = 4;

//     b1.a = 1;
//     b1.b = 9;

  
//     printpoint(a1);

// }

// void printarray(int *a, int size){

//     for(int i = 0; i < size;i++){
//         printf("%d ",a[i]);
//     }
// }


// int main(){
//     int intero; //variabile input dell'utente
//     int *a = malloc(10*sizeof(int)); //alloca memoria per la dimensione di 10 interi
//     int maxdim = 10; //tiene conto della dimensione massima corrente dell'array
//     int currentdim = 0;//tiene conto degli elementi presenti all'interno dell'array
    
//     while(1){ //ciclo infinito
//         printf("Inserire un intero : ");
//         if(scanf("%d",&intero)!=1){ //se l'espressione tra parentesi non è vera allora si ferma il ciclo 
//             printf("Errore nella richiesta, END");
//             break;
//         }
//         if(currentdim == maxdim){ //verifica che vi sia abbastanza spazio nell'array
//           a = realloc(a,10*sizeof(int)); //rialloca spazio
//           maxdim += 5;
//         }
//         a[currentdim] = intero; //inserimento dell'input nell'array
//         currentdim++; //aumento del counter degli elementi dell'array
//         printarray(a,currentdim); //stampa l'array
//         }
//     free(a);
// }


/************************************ESAME 15 FEBBRAIO 2024*****************************/

//Si scriva una funzione avente il seguente prototipo:
//char *get_format(char *a);
//dove a è una stringa che può essere definita come array statico o come puntatore ad un array
//dinamico di char . La stringa a contiene n interi (più precisamente, contiene la codifica decimale di
//n interi) separati da n-1 caratteri ';' . La funzione deve modificare a sostituendo ad ogni intero il
//carattere p o d a seconda che l'intero sia pari o dispari; deve ritornare il puntatore alla stringa
//modificata.
//Esempio: Se a = "7;90;0;123;8;4" , la funzione deve ritornare un puntatore alla stringa "d;p;p;d;p;p


/*
char *get_format(char *a){
    char *p = a;
    int i = 0;

    while(a[i]!= '\0'){
        if(a[i] == ';'){
            i++;
        }
        if((a[i]%2)==0){
            a[i] = 'p';
            i++;
        }else{
            a[i] = 'd';
            i++;
        }
    }
    return p;
}

void print_array(char *a){
    printf("%s",a);
}

int main(){
    char a[] = "7;90;0;123;8;4";
    char *arraypd = get_format(a);
    print_array(arraypd);

    return 0;
}
*/

/**************************ESAME 26 SETTEMBRE 2022**°********************/

/*1) C
Si considerino le strutture dati definite dal seguente frammento di codice:

struct point {
float x, y;
};
typedef struct point point;

struct segment {
 point *a;
 point *b;
};
typedef struct segment segment;

Si scriva una funzione che abbia il seguente prototipo:

segment *new_segment(float ax, float ay, float bx, float by)

e restituisca un puntatore ad un nuovo segment tale che i due point che lo
compongono abbiano coordinate ax e ay per il primo e bx e by per il secondo. */



// struct point{
//     float x;
//     float y;
// };
// typedef struct point point;

// struct segment{
//     point *a;
//     point *b;
// };
// typedef struct segment segment;

// segment *new_seg(float ax, float ay, float bx, float by){
//     point *a1 = malloc(sizeof(point));
//     point *b1 = malloc(sizeof(point));

//     if(a1 == NULL || b1 == NULL){
//         return NULL;
//     }

//     a1->x = ax;
//     a1->y= ay;

//     b1->x = bx;
//     b1->y = by;

//     segment *n1 = malloc(sizeof(segment));
    
//     if(n1 == NULL){
//         return NULL;
//     }
//     n1->a = a1;
//     n1->b = b1;

//     return n1;  
// }

/*****ESAME 4 LUGLIO 2022*****/


/*L’array di interi a rappresenta una matrice con r righe e n colonne. Ogni riga
è composta da una sequenza di 1 seguita da tutti 0. 

L’esempio mostra uno di
questi array con 6 righe e 5 colonne.

int a[] = {
1,1,0,0,0,
1,0,0,0,0,
1,1,1,0,0,
1,1,0,0,0,
1,1,1,1,0,
1,1,1,1,1
};
int r = 6, c = 5; 

Scrivere una funzione C che prenda in input un array a come descritto sopra
e lo modifichi spostando le sequenze di 1 al centro delle righe riempiendo di 0
gli spazi lasciati liberi.

La funzione abbia il seguente prototipo:
void centering(int *a, int r, int c);

Esempio: centering(a, 6, 5) sull’array a dell’esempio lo modifichi nel seguente
modo:
0 1 1 0 0
0 0 1 0 0
0 1 1 1 0
0 1 1 0 0
1 1 1 1 0
1 1 1 1 1
o nel seguente modo:
0 0 1 1 0
0 0 1 0 0
0 1 1 1 0
0 0 1 1 0
0 1 1 1 1
1 1 1 1 1 */



/* void centering(int *a, int r, int c){
    int i,j;
    int *p;
    int posizione1;

    for(i = 0; i< r; i++){
        if(r[i] != 0){
            
        }
    }
}
*/

int main(){
    
    char a[] = "ciapo";
    int n = strlen(a);
    printf("len A prima del puntatore: %d  \n",strlen(a));
    char *b =  a+n/2;
    printf("len A dopo del puntatore: %d  \n",strlen(a));
    
    *b = '\0';
    printf("A : %d, B: %d\n",strlen(a), strlen(b));
    printf("%ld\n",strlen(a)-strlen(b));

}
