#include <stdio.h>
#include <stdlib.h>
int main(){
    int a[3]={7,3,5};
    int *b=a;
    for(int i =0;i<3;i++){
        printf("%d",*(b+i));  //accedere ai valori di un array con puntatore
    }
}