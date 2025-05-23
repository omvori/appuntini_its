#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct punto{ //struttura punto con coordinata x e y 
    float x;
    float y;    
};
void punto_medio(struct punto a, struct punto b){    //trovo il punto medio tra due punti
    float M=sqrt(abs((pow(b.x-a.x,2))+(pow(b.y-a.y,2))));
    printf("%f",M);
}
int main(){
    struct punto p1;
    struct punto p2;
    p1.x=3.0;
    p1.y=6.0;
    p2.x=8.0;
    p2.y=12.0;
    punto_medio(p1,p2);
}