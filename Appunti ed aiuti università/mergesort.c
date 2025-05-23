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
    
    void print_array(int a[],int size){ //funzione che stampa un array
        for(int i = 0;i < size; i++){ //ciclo per stampare ogni singolo elemento di un array
            printf("%d",a[i]);
        }

    }

    int binary_search(int a[],int sx,int dx,int target){
        int cx = (dx + sx)/2;
        if(sx<=dx){
         if (a[cx] == target){
            return cx;
         } else if(a[cx] > target){
            binary_search(a,0,cx-1,target);
         } else if(cx < target){
            binary_search(a,cx+1,dx,target);
         }
        }
        
        return -1;


    }

int main(){
    
    int a[8] = {4,6,2,6,1,1,3,9};
    int size = sizeof(a)/sizeof(a[0]);
    
    merge_sort(a,0,size-1);

    print_array(a,size);





}