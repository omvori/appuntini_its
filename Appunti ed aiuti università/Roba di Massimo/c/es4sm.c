#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * concatena(char ** array_di_stringhe,int numero_stringhe){
    int total_size=0;
    //trova la dimensione totale
    for(int i=0;i<numero_stringhe;i++){
        total_size +=strlen(array_di_stringhe[i]);
    }
    //printf("%d\n",total_size);
    //alloca la stringa
    char * stringa_concatenata= malloc(sizeof(char)*total_size); //crea un array dove inserire le singole stringhe
    //controlla che l'allocazione sia andata a buon fine
    if(stringa_concatenata!=NULL){
        int k=0;
        for(int i=0;i< numero_stringhe;i++){ //per ogni stringa nell'array di stringhe
            for (int j=0;j<strlen(array_di_stringhe[i]);j++){//per ogni carattere della stringa
                stringa_concatenata[k]=array_di_stringhe[i][j];
                k++;
            }
        }
        stringa_concatenata[k]='\0';
    }
    return stringa_concatenata;
}
int main(){
    char * a="ciao ";
    char * b="come ";
    char * c="va?";
    char ** array_di_stringhe;
    array_di_stringhe[0]=a;
    array_di_stringhe[1]=b;
    array_di_stringhe[2]=c;
    printf("%s\n",concatena(array_di_stringhe,3));
}