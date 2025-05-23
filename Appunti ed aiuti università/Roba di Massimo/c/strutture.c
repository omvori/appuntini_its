#include <stdio.h>
#include <stdlib.h>
struct punto{
        float x;     //campi della struct
        float y;       
    };
typedef struct punto punto;   //punto adesso è di tipo struct punto. Utile per semplificare

struct sequenza{
    float *a;
    int n;
};


typedef struct sequenza sequenza;
void mostra_sequenza(sequenza);
sequenza nuova_sequenza(int){
};

int main(){
    

    struct punto p={1.0,2.9};   // p è ora una variabile dello stesso tipo dello struct punto. Il primo valore viene asseganto al primo campo ecc..
    punto q=p;                  //copia campo per campo
    p.x=3.9;                    // il campo x di p ora vale 3.9
    p.y=p.x+1;                  // il campo y di p ora vale p.x+1
    printf("%f %f",p.x,p.y);  
    printf("%f %f",q.x,q.y);
    printf("-----------------------");
    sequenza s=nuova_sequenza(10); 
    mostra_sequenza(s);

}
sequenza nuova_sequenza(int d){
    /*
    ritorna nuova sequenza di d float tutti nulli
    */
   sequenza v;
   v.a=malloc(sizeof(float)*d); //allocare spazio per d-float
   v.n=d;
   int i;

   for (i=0;i< v.n;i++){
    v.a[i]=0;
    
   }
   return v;

};
void mostra_sequenza(sequenza v){
    int i;
    for (i=0;i<v.n;i++){
        printf("%.2f",v.a[i]);  //%.2f=due cifre decimale dopo il punto
    }

}    