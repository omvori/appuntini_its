#include <stdio.h>
int main(){
    int a[]={33,77,44,193,492,342};
    int max;
    int min;
    max = min = a[0];     //setto a[0] come max e min dell'array
    for(int i=1;i<=5;i++) //scorro tutti i valori. Tempo O(n)
    {
        if (a[i]<min)     //se il prossimo numero è più piccolo di MIN lo diventerà lui
            min=a[i];
        
             
        if (a[i]>max)     //se il prossimo numero è più grande di MAX lo diventerà lui
            max=a[i];
        }
    printf("&d",max);
    return 0;
    }
    
