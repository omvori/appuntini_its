#include <stdio.h>

int main(){
    int arr[5]; //TIPO_DATO+NOME_ARRAY[numero_elementi]
                //il compilatore ha allocato un blocco di memorria: 5*sizeof(int)
                //la lunchezza di un array deve essere sempre un intero, anche sotto forma di espressione(5+(4/2))
                
    //--------------------------------------------------
   
    arr[0]=0;   //accedere agli elementi dell'array
    arr[1]=1; 
    arr[2]=2;
    arr[3]=3;
    arr[4]=4;
    
    //--------------------------------------------------
    
    int arr3[5]={12,34,11,4,78}; //definire dimensione ed elementi dell'array
    int arr[]={1,2,3,4,5,6,7}; //si può anche non specificare la grandezza e specificare gli elementi
    
    //--------------------------------------------------
    
    int a;
    int arr2[a=7];  //oppure deifinire una variabile come la sua grandezza
    int i;
    for(i=0;i<7;i++){
        printf("inserisci gli elementi dell'array di dimensione 7:");
        scanf("%d",&arr2[i]); //inserisco manualmente ogni elemento dell'array

    }
    
    // se inserisco un numero di elementi minore rispetto alla lunghezza dell'array il resto delle poszione avrà valore=0
    
    // ma non posso inserire un numero di elementi maggiore rispetto alla lunghezza dell'array
    
    int arr5[10]={[0]=1,[5]=3,[7]=4}; //*INIZIALIZZAZIONE MIRATA* il resto delle poszioni sranno =0
    int arr6[]={[1]=3,[49]=7}; // se non specifico la lunghezza il compilatore darà all'array lunghezza=posizione più grande che abbiamo specificato +1
    
    //-------------------------------------------------------------------
    
    sizeof(arr6)/sizeof(arr6[0]); //grazie al sizeof possiamo farci dire quanti elementi ci sono nell'array in considerazione
    
    //------------------------------
    
    const arr7[3]={1,2,3}; // se è const non possiamo modificare gli elemtni dell'array
    
    //--------------------------------
    
    int n;
    int a[n]; // la grandezza può essere variabile ed essere specificata dall'utente
}