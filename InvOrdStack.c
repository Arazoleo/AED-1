#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

typedef struct pile{
    char caractere;
    struct pile * prox;
}No;

No * Push(No * topo, char c){
    No * novo = malloc(sizeof(No));
   
    if(!novo){
        exit(1);
    }
    else{
        novo->caractere = c;
        novo->prox = topo;
        return novo;
    }
}

No * Pop(No ** topo){
    No * remover = NULL;
    
    if(*topo != NULL){
        remover = *topo;
        *topo = remover->prox;
        return remover;
    }
    else{
        printf("PIlha vazia\n\n");
    }
}

void Inverte_frase(char * string){
    No * topo = NULL;
    No * remover = NULL;
    
    for(int i = 0; i < strlen(string); i++){
        if(string[i] != ' '){
            topo = Push(topo, string[i]);
        }
        else{
            while(topo != NULL){
                remover = Pop(&topo);
                printf("%c",remover->caractere);
                free(remover);
            }
            printf(" ");
        }
    }
    while(topo != NULL){
        remover = Pop(&topo);
        printf("%c",remover->caractere);
        free(remover);
}
}
int main()
{
    char x[MAX];
    printf("Insira uma frase: ");
    scanf("%[^\n]", x);
    
    Inverte_frase(x);
    return 0;
}

