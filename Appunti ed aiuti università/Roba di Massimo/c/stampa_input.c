#include <stdio.h>
#include <stdlib.h>
int main(int n, char *args[]){ //char *args[] è un array di stringhe, sono input che possimao scirvere sulla linea di comando prima di avviare il codice
    
    for(int i=1;i<n;i++){
        printf("%s",args[i]);
        printf("\n");
    }
   

}