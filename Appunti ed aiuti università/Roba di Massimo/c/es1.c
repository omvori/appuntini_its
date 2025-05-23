#include <stdio.h>
#include <stdlib.h>
struct studente{ //struttura studente composta da nome, età e numero voti
    char nome[20];
    int eta;
    int nvoti;
};
int main(){
    struct studente std1;
    struct studente std2;
    printf("Inserisci i dati del primo alunno:\n:nome-eta-numero voti\n");
    scanf("%s %d %d",std1.nome, &std1.eta, &std1.nvoti);
    printf("Inserisci i dati del secondo alunno:\n:nome-eta-numero voti\n");
    scanf("%s %d %d",std2.nome,&std2.eta, &std2.nvoti); 
    float media=((std1.nvoti+std2.nvoti)/2); //numero medio di numero di voti
    printf("%f",media);   
}