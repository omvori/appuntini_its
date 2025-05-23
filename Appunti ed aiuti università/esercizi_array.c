#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int main(){ //stampa array
//     int a[5] = {1,4,2,5,5};
    
//     for(int i = 0 ; i < 5; i++){
//         printf("\n%d",a[i]);
//     }
//     printf("\n");
//     return 0;
// }

// int main(){ //somma array
//     int f[9] = {1,5,6,3,4,1,6,3,4};
//     int somma = 0;

//     for(int k = 0; k < 9; k++){
//         somma += f[k];
//     }

//     printf("%d",somma);

// }

// int main(){ //trova il max di un array
//     int b[5] = {1,45,6,3,77};
//     int maxel = b[0];

//     for(int i = 0; i < 5; i++){
//         if (maxel < b[i]){
//             maxel = b[i];
//         }
//     }
//     printf("%d",maxel);
//     return 0;
// }

// int main(){ //ricerca elemento 
//     int g[10] = {5,7,4,3,3,6,4,1,6,7};
//     int elemfound = 4;
//     int f = 0;

//     for(int i = 0; i < 10; i++){
//         if(elemfound == g[i]){
//             f = 1;
            
//         }
//     }
//     if(f){
//         printf("Element found: %d",elemfound);
//     }else{
//         printf("Element Not Found");
//     }
//     return 0;


// }


// int main(){ //copia di un array
//     int g[5] = {1,5,3,2,5};
//     int e[5];
//     for(int i = 0; i < 5; i++){
//         e[i] = g[i];
//     }

//     for(int i = 0; i < 5;i++){
//         printf("%d",e[i]);
//     }
//     return 0;
// // }


// int main(){ //somma tra elementi dell'array
//     int array1[5] = {1,2,3,4,5};
//     int array2[5] = {6,7,8,9,10};
//     int somma[5];

//     for(int i = 0; i < 5 ;i++){
//         somma[i] = array1[i]+array2[i];        
//     }

//     for(int k = 0; k < 5;k++){
//      printf("%d ",somma[k]);
        
//     }
//     return 0;

// }

// int main(){ //array ordinato con bbsort
//     int f[5] = {1,5,2,6,3};
//     int temp;

//     for(int i = 0; i<5-1;i++){
//         for(int j = 0;j < 5-i-1;j++){
//             if(f[j]>f[j+1]){
//                 temp = f[j];
//                 f[j] = f[j+1];
//                 f[j+1] = temp;
//             }
//         }
//     }

//     for(int i = 0; i <5; i++ ){
//         printf("%d",f[i]);
//     }

//     return 0;


// }


// int main(){ //rimuove duplicato nell'array
//     int a[6] = {1,1,5,6,7,5};
//     int nnumeri[6];
//     int n = 0;

//     for(int i = 0; i < 6;i++){
//        int j;
//        for(j = 0; j < n; j++){
//             if(a[i]==nnumeri[j]){
//                 break;
//             }
//        }
//        if(j==n){
//         nnumeri[n] = a[i];
//         n++;
//        }
        
//     }
//     for(int i = 0; i < n; i++){
//         printf("%d ",nnumeri[i]);
//     }
//     return 0;
// }

// int main(){ //shift a Sx di un array
//     int a[5] = {1,2,3,4,5};
//     int temp = a[0];
//     int i;

//     for(i = 0; i<5-1;i++){
//         a[i]=a[i+1];
//     }
//     a[4] = temp;

//     for(i=0;i<5;i++){
//         printf("%d",a[i]);
//     }
// }

int main(){ //concatenazione array
    int a1[5] = {1,2,3,4,5};
    int a2[3] = {6,7,8};
    int achain[8];
    int i;

    for(i = 0; i < 5;i++){
        achain[i] = a1[i];   
    }
    for(i = 0; i < 5; i++){
        achain[i+5] = a2[i];
    } 

    for(i=0;i<8;i++){
        printf("%d",achain[i]);
    }
}