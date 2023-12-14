#include <stdio.h>
#include <stdlib.h>
typedef struct list{
    int valor;
    struct list *prox;
}No;

void Insere_ordenado(No **lista, int num){
    No *novo = malloc(sizeof(No));
    No *temp = NULL;
    if(!novo){
        exit(1);
        
    }
    else{
        novo->valor = num;
         if(*lista == NULL){
             novo->prox = *lista;
             *lista = novo;
         }
         else{
             temp = *lista;
             while(temp->prox != NULL && novo->valor > temp->prox->valor){
                 temp = temp->prox;
             }
             if(temp->prox != NULL){
                 
                 novo->prox = temp->prox;
                 temp->prox = novo;
                 
             }
             else{
                 novo->prox = NULL;
                 temp->prox = novo;
             }
             
         }
    }
    
}

No* Merge_lists(No* lista1, No* lista2) {
    No* Lista_3 = NULL;

    while (lista1 != NULL && lista2 != NULL) {
        if (lista1->valor < lista2->valor) {
            Insere_ordenado(&Lista_3, lista1->valor);
            lista1 = lista1->prox;
        } else {
            Insere_ordenado(&Lista_3, lista2->valor);
            lista2 = lista2->prox;
        }
    }

    while (lista1 != NULL) {
        Insere_ordenado(&Lista_3, lista1->valor);
        lista1 = lista1->prox;
    }

    while (lista2 != NULL) {
        Insere_ordenado(&Lista_3, lista2->valor);
        lista2 = lista2->prox;
    }

    return Lista_3;
}

void Imprime_lista(No *lista){
    No *temp = NULL;
    
    temp = lista;
    printf("\t------LISTA------\n");
    while(temp != NULL){
        printf("%d\n",temp->valor);
        temp = temp->prox;
        
    }
    printf("\t-----Fim------\n");
}


int main()
{
    No *Lista_1 = NULL;
    No *Lista_2 = NULL;
    int numero;
    int opcao;
    do{
    printf("1 - Inserir na lista 1\n");
    printf("2 - Inserir na lista 2\n");
    printf("3 - União\n");
    printf("0 - Sair\n");
    scanf("%d",&opcao);
    
    switch(opcao){
        case 1:
        printf("Insira o valor que deseja colocar: ");
        scanf("%d",&numero);
        Insere_ordenado(&Lista_1,numero);
        break;
        
        case 2:
        printf("Insira o valor que deseja colocar: ");
        scanf("%d",&numero);
        Insere_ordenado(&Lista_2,numero);
        break;
        
        case 3:
        No* p = Merge_lists(Lista_1,Lista_2);
        Imprime_lista(p);
        break;
        
        
        
    }
    
}while(opcao != 0);
    return 0;
}

