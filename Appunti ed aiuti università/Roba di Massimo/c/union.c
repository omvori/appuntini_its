#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//implementare un array con elementi diversi tra di loro (int, str e float)
//dichiarare ogni elemento come 8 byte (int=float=4byte e str=8byte)
union item{   //l'elemento della union può essere uno dei seguenti al suo interno
    int val_i;
    float val_f;
    char *val_s;
};

typedef union item item;
typedef struct object object;

struct object{ //type ci dirà cosa stiamo usando dei tre valori dell'union
    char type; // 'I'=int 'F'=float 'S'=*char
    item u;
};

object parse(char*);

void print(object);

int main(int n, char *args[]){
    object *a=malloc(sizeof(object)*(n-1));
    int i;

    for(i=1;i<n;i++){
        a[i-1] = parse(args[i]);
    }
    for(i=0;i<n-1;i++){
        print(a[i]);
    }
}
int cercapunto(char *s){
    int c=0,i=0;
    while(s[i]!='\0'){ //scorre la stringa fino all'ultimo carattere NULL
        if(s[i]=='.'){
            c++;
        }
        if(c==2){
            return 0;
        }
    }
    if(c==1){
        return 1;
    }
    return 0;
} 
object parse(char *s){
    object obj;
    if (cercapunto(s)== 0 && scanf(s,"%d",&(obj.u.val_i))==1){//se non c'è il punto lo provo a convertire 
        obj.type='I';
    }
    else if(cercapunto(s)==1 && scanf(s,"%f",&(obj.u.val_f))==1){//se c'è il punto forse è float
        obj.type='F';                                              

    }
    else{
        obj.type='S';
        obj.u.val_s=s;
    }
}

void print(object obj){
    if(obj.type == 'I'){        //vedo che stringa è e quindi il valore dell'union
        printf("%d\n",obj.u.val_i);
    }
    else if(obj.type == 'F'){
        printf("%f\n",obj.u.val_f);
    }
    else{
        printf("%s\n",obj.u.val_s);
    }    
}

int main0(){
    object obj;
    obj.type='I';
    obj.u.val_i=10;
    if(obj.type == 'I'){        //vedo che stringa è e quindi il valore dell'union
        printf("%d\n",obj.u.val_i);
    }
    else if(obj.type == 'F'){
        printf("%f\n",obj.u.val_f);
    }
    else{
        printf("%s\n",obj.u.val_s);
    }    
}