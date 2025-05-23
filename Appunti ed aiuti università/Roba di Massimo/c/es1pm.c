#include <stdio.h>
#include <stdlib.h>
float aumenta(float *puntatore, int n){ //accetta un puntatore float e un intero di cui aumentare il valore puntatto
    *puntatore+=n; 
}
int main(){
    float a=3.14;
    float *p=&a;
    aumenta(p,2);
    printf("%f",a); //ho modificato il puntatore e quindi la variabile a cui punta
}
