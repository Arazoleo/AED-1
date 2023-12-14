#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue{
  int idade;
  char nome[20];
  struct queue *prox;
}No;
typedef No *pFila;

void inserir(pFila *fila){
  int i;
  char n[20];
  
  getchar();
  printf("Insira o nome: ");
  scanf("%[^\n]", n);

  printf("Insira a idade: ");
  scanf("%d", &i);

  pFila novo = (pFila)malloc(sizeof(No));

  if(!novo){
    exit(5);
  }
  else{
    printf("entrou\n");
    strcpy(novo->nome, n);
    novo->idade = i;
    if(!(*fila)){
      novo->prox = *fila;
      *fila = novo;
    }
    else{
      pFila aux = *fila;
      while(aux->prox != NULL){
        aux = aux->prox;
      }
      novo->prox = aux->prox;
      aux->prox = novo;
    }
  }
}

void Remover_fila(pFila *p){
  pFila aux = *p;
  if(aux){
    *p = aux->prox;
    free(aux);
  }
  else{
    printf("Fila vazia!\n");
  }
}

void furar_fila(pFila *p){
  char n[20];
  int i;
  pFila aux = *p;
  getchar();
   printf("Insira o nome: ");
  scanf("%[^\n]", n);
  printf("Insira a idade: ");
  scanf("%d", &i);

  pFila novo = (pFila)malloc(sizeof(No));
  if(!novo){
    exit(5);
  }
  else{
    strcpy(novo->nome, n);
    novo->idade = i;
      novo->prox = *p;
      *p = novo;
   
    }
  }

void imprimir(pFila fila){
  pFila aux = fila;
  if(aux){
    while(aux){
      printf("Nome: %s\n", aux->nome);
      printf("Idade: %d\n", aux->idade);
      aux = aux->prox;
      }
  }
  else{
    printf("Fila vazia!\n");
  }
  
}

void Libera(pFila f){
  pFila aux = f;
  while(aux){
    f = aux->prox;
    free(aux);
    aux = f;
  }

}
int main(void) {

  pFila fila = NULL;
  int op;
  
  do{
  printf("1 - Entrar na fila\n2 - Sair da fila\n3 - Furar fila\n4 - Mostrar\n0 - Sair\n\nInsira o que deseja: ");
  scanf("%d",&op);

  switch(op){
    case 1:
    inserir(&fila);
    break;

    case 2:
    Remover_fila(&fila);
    break;

    case 3:
    furar_fila(&fila);
    break;

    case 4:
    imprimir(fila);
    break;

    case 0:
    printf("Saindo...\n");
    Libera(fila);
    break;

    default:
    printf("Opção inválida!\n");
    break;
  }  
  }while(op != 0);
  
  
  return 0;
}