#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int str_to_int(char *a);
int main(int n, char *args[]){
    int somma=0;
    
    for(int i=1;i<n;i++){
        printf("%d",args[i]);
        somma+= str_to_int(args[i]);
    }
    printf("%d\n",somma);
}
// se input "123" (stringa) output = 123
int str_to_int(char *a){
    int p= strlen(a)-1;  // p=ultima posizione della stringa
                 
    int n=0;             //output
    int m=1;
    while(p>=0){

        n+=(a[p]-'0')*m;
        p--;
        m *= 10;
    }
        return n;

}
