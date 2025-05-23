#include <stdio.h>
int main(){
    int a[12]={1,2,3,5,8,13,17,22,34,39,234,300};
    //cercare numero in array ordinato. Complessità temporale= log(n)
    int sx=0;
    int dx=sizeof(a)/sizeof(int);
    int k=34; //chiave da cercare
    while (sx<dx){
        int m=(sx+dx)/2; //elemento a metà
        if (a[m]==k){  
            printf("%d = la posizione dell'elemento cercato",m);
            break;
        }
        if (k<a[m]){  //se la chiave è più piccola di m vuol dire che si trova nella prima metà
            dx=m;     //quindi dimezzo il campo di ricerca fino a metà dell'array
        }

        
        if (k>a[m]){  //se la chiave è più grande di m vuol dire che si trova nella seconda metà
            sx=m+1;   //quindi mando avanti il campo di ricerca partendo dalla metà dell'array
        }

    }
    return -1;
    
}

