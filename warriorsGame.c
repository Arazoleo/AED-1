#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct guerreiro{
    char nome[20];
    struct guerreiro *prox;
}No;
typedef No* Plista;

void Insere_lista(Plista *lista, char nome[]){
  Plista novo = (Plista)malloc(sizeof(No));

  if(!novo){
    return;
  }
  else{
    strcpy(novo->nome, nome);
    if(*lista == NULL){
      novo->prox = novo;
      *lista = novo;
    }
    else{
      Plista aux = *lista;
      while(aux->prox != *lista){
        aux = aux->prox;
      }
      novo->prox = aux->prox;
      aux->prox = novo;
    }
  }
}

void Imprime(Plista lista){
  if(!lista){
    return;
  }
  else{
    Plista aux = lista;
    do{
      printf("%s\n", aux->nome);
      aux = aux->prox;
    }while(aux != lista);
  }
}


void Libera(Plista lista){
  if(!lista){
    return;
  }
  else{
    Plista aux = lista;
    do{
      lista = aux->prox;
      free(aux);
      aux = lista;
    }while(aux != lista);
  }
}

void Aplica_Ponteiro(Plista *lista, char nome[]){
  if(strcmp((*lista)->nome, nome) == 0){
    return;
  }
  else{
    Plista aux = (*lista)->prox;
    while(aux != *lista && strcmp(aux->nome, nome) != 0){
      aux = aux->prox;
    }
    *lista = aux;
  }
}

void Remove_lista(Plista *lista, char nome[]){
  if(strcmp((*lista)->nome, nome) == 0){
    Plista aux = *lista;
    *lista = (*lista)->prox;
    free(aux);
  }
  else{
    Plista aux = *lista;
    while(aux->prox != *lista && strcmp(aux->prox->nome, nome) != 0){
      aux = aux->prox;
    }
    if(aux->prox != *lista){
      Plista aux2 = aux->prox;
      aux->prox = aux2->prox;
      free(aux2);
    }
  }
}


int main(void){
  int guerreiros, sort;
  char name[20];
  char inicio[20];
  Plista lista = NULL;

  printf("Digite a quantidade de guerreiros: ");
  scanf("%d", &guerreiros);

  for(int i = 0; i < guerreiros; i++){
    printf("Digite o nome do guerreiro %d: ", i+1);
    scanf("%s", name);
    Insere_lista(&lista, name);
  }

  printf("Digite o nome do guerreiro que iniciará: ");
  scanf("%s", inicio);

  Aplica_Ponteiro(&lista, inicio);
  //Imprime(lista);

  do{
  printf("Insira o número sorteado: ");
  scanf("%d", &sort);
  Plista aux = lista;
    while(sort != 0){
      aux = aux->prox;
      sort--;
    }
    printf("%s foi eliminado\n", aux->nome);
    Remove_lista(&lista, aux->nome);
    guerreiros--;
    
  }while(guerreiros > 1);

  printf("O vencedor é %s", lista->nome);
  
  Libera(lista);
  return 0;
}