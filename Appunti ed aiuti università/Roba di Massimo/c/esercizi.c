
#include <stdio.h>
#include <stdlib.h>
struct punto{
    int x;
    int y;
    
};
//              stampa valori struttura
void stampa(struct punto a){
    
    printf("%d\n",a.x);
    printf("%d\n",a.y);
}
int main(){

struct punto p;
p.x=1;
p.y=2;
stampa(p);
return 0;
} 


//----------------------stringhe
int main(){
    char str1[6]="python"; //dichiarazione stringa
    char str2[8]={'c','a','s','e','t','t','a'}; 
    char *A=(malloc(100*sizeof(char))); //Allocazione dinamica di memoria per un puntatore che punta a 100 caratteri. Array di caratteri che può essere visto come una stringa 
    printf("stringa 1:%s\n",str1);
    printf("stringa 2:%s",str2);
    return 0;
}


