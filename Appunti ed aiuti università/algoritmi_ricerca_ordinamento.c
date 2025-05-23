#include <stdio.h>
#include <stdlib.h>

void merge(int arr[],int sx,int cx,int rx){
        int n1 = cx - sx + 1;
        int n2 = rx - cx;

        int L[n1], R[n2];

        for(int i = 0;i < n1;i++){
            L[i] = arr[sx+i];
        }
        for(int j = 0 ; j < n2; j++){
            R[j] = arr[cx+1+j];
        }

        int i= 0 ,j = 0, k = sx;

        //ora bisogna fondere L ed R in modo che l'array principale 'arr' sia ordinato   
        while(i<n1 && j<n2){ //fintanto che vi siano elementi da ordinare
            if(L[i]<= R[j]){ //confronta gli elementi dei due sotto array L ed R 
                arr[k] = L[i];  //nel caso L[0] sia minore o uguale ad R[0], allora inserisci L[0] in 'arr'
                i++; //scorre il sotto array L
            } else{ //nel caso in cui un elemento di R sia minore,allora sarà quello ad essere inserito in 'arr'
                arr[k] = R[j];
                j++; //scorre R
            }
            k++; //incrementa l'indice che scorre l'array 'arr' cosi da scegliere la prossima posizione nel quale inserire un elemento di L o R
        } 
       
        
    }

    void merge_sort(int arr[], int sx, int dx){ // 'arr' è l'array che deve essere ordinato, sx l'indice sinistro e dx l'indice destro (sx sarà la posizione del primo elemento,dx l'ultimo elemento)
        if(sx<dx){ //condizione base,valuta che ci sia almeno un elemento per eseguire la ricorsione
            int cx = (dx+sx)/2; //calcola l'indice centrale 
            merge_sort(arr,sx,cx); //ordina la partre sinistra fino alla centrale con l'array e le posizioni degli elementi come input
            merge_sort(arr,cx+1,dx); //ordina la parte centrale fino a destra con l'array e le posizioni degli elementi come input
            merge(arr,sx,cx,dx); //fonde gli array in un unico array ordinato
        }
    } 
    //tempo O(n x log(n)) algoritmo efficiente che dimezza il tempo necessario di riordino di un array
    
    void print_array(int a[],int size){ //funzione che stampa un array
        for(int i = 0;i < size; i++){ //ciclo per stampare ogni singolo elemento di un array
            printf("%d",a[i]);
        }

    }

    int binary_search(int a[],int sx,int dx,int target){ //input sono : array ordinato,posizione sinistra, posizione destra,numero da cercare
        
        if(sx<=dx){ //valuta se esiste più di un elemento nell'array
         int cx = (dx + sx)/2; //cerco il centro
         if (a[cx] == target){ //se la posizione cx nell'array combacia con il numero da cercare,torniamo cx
            return cx;
         } else if(a[cx] > target){ //se non si dovesse verficare allora cx può essere maggiore del numero da cercare
            binary_search(a,0,cx-1,target); //nel caso cambiamo gli input con : array,posizione 0,cx-1 ed il numero da cercare
         } else{ //oppure può essere minore dal numero da cercare
             binary_search(a,cx+1,dx,target); //nel caso cambiamo gli input con: array,cx+1,fino a destra e il numero da cercare
         }
         }
        return -1; //nel caso non si entri nell'if,non sarà presente l'elemento e quindi si torna errore
    }
    //tempo O(log_n) algoritmo molto ottimale,permette di trovare abbastanza velocemente all'interno di grandi array

    void bbsort(int a[],int n){ //input sono: l'array, e la sua lunghezza
        int ordinata = 0; //Si inizializza una variabile presupponendo non sia ordinata la lista
        int i = 0; //contatori
        int c = 0;
        int t; //variabile temporanea che serve a "salvare" il valore dell'elemento da scambiare per evitare di perderlo

        while (ordinata == 0){ //nel frattempo che la lista non è ordinata
            for(i=0;i<n-1-c;i++){ //ciclo che scorre lungo tutto l'array: n = la lunghezza,-1 per considerare tutto l'array, -c = tiene traccia del numero degli scambi
                if(a[i]>a[i+1]){ //caso in cui il precedente è maggiore del successivo
                    ordinata = 0; 
                    t = a[i]; //si assegna alla variabile temporale l'elemento da spostare
                    a[i] = a[i+1]; //si scambiano i valori
                    a[i+1] = t; //si assegna il precedente elemento da assegnare alla posizione 0 (o precedente)
                }
            }
            c++; //incrementa il ciclo
        }
            
    }
    //tempo O(n^2) algoritmo poco ottimale,serve solamente per piccoli dati



    

int main(){
    
    int a[8] = {4,6,2,6,1,1,3,9};
    int size = sizeof(a)/sizeof(a[0]);
    
    merge_sort(a,0,size-1);

    print_array(a,size);





}