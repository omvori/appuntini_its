#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){
    char a[]="python";
    char *b=malloc(100);
    int i=0;
    while(a[i]!= '\0'){
        b[i]=a[i];
        i++;
    }
    printf("%d", strlen(b));
    char s[]="7+2";
    for (int i=0;i<strlen(s);i++){
        printf("%c",s[i]);
    }
}