#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int a=3;
    int *b=&a;
    int c=a+*b;
    printf("%d",c);
}
//1.dizionario efficente se n/m è costante

//2.quanto vale c alla fine del codice=2*n

//3.L lista concatenata ci vuole complessità temporale lineare O(n) per trovare il massimo se già ordinati

//4.il frammento di codice ha complessità temporale lineare nel peggiore dei casi(sotto)

int i;
float *a=malloc(n*sizeof(float));
for(i=0;i<n;i++){
    a[i]=i;
}
a=realloc(a,2*n);

//5.x lineare n-p

//6.sia h la funzione hash. Non è vera:il dominio di h è l'insieme delle chiavi del dizionario


//7.la lunghezza di strlen(a)=n/2
char *a=malloc(n*sizeof(char));
a[n/2]='\0';

//8. lineare O(n)

//9. la somma delle cifre in a
int i =0, n=0;
while(a[i]!='\0'){
    n+=a[i]-'0';
    i++;
}
//10. sizeof(a)>sizeof(b)
int a[123]={0};
int *b=a;

d={}
for x in range(n):
    d[x%2]=d.get(x%2,0)+1

struct astruct{
    double x;
    int *y;

};
a.y=malloc(100*sizeof(int))

char *a=malloc(n*sizeof(char))