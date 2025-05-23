#include <stdio.h>
#include <stdlib.h>
int main(){
    int n1; //intero
    int n2; //intero
    int *p1; //puntatore a intero
    int *p2; //puntattore a intero
    printf("Inserisici due numeri:\n");
    scanf("%d %d",&n1,&n2);
    p1=&n1;
    p2=&n2;
    int sum=(*p1+*p2);  //somma tramite puntatori
    printf("%d",sum);
}