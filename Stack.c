#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int val;
    struct stack *prox;
}No;
typedef No *pPilha;

void Inicializa_pilha(pPilha *p){
  *p = NULL;
}

pPilha Push(pPilha topo){
  int value;
  
  printf("Insira o valor que deseja inserir: ");
  scanf("%d",&value);

  pPilha novo = (pPilha)malloc(sizeof(No));

  if(!novo){
    exit(5);
  }
  else{
    novo->val = value;
    novo->prox = topo;
    return novo;
  }
}

pPilha Pop(pPilha *topo){
  if(*topo == NULL){
    printf("Pilha vazia\n");
    return NULL;
  }
  else{
   pPilha remover = *topo;
   *topo = remover->prox;
   return remover;
  }
}

void Mostra_pilha(pPilha topo){
  pPilha aux = topo;
  if(topo){
    printf("\n----Stack----\n");
    while(aux){
      printf("%d\n", aux->val);
      aux = aux->prox;
    }
  }
  else{
    printf("Pilha vazia\n");
    return;
  }
}

void Libera_pilha(pPilha topo){
  pPilha temp = topo;
  while(temp){
    pPilha aux = temp->prox;
    free(temp);
    temp = aux;
  }
}

int main(void) {
  pPilha topo;
  pPilha remover;
  int op; 
  Inicializa_pilha(&topo);
do{
  printf("1 - Empilhar\n2 - Desempilhar\n3 - Mostrar Pilha\n0 - Sair\n\nInsira o que deseja: ");
  scanf("%d",&op);

  switch(op){
    case 1:
    topo = Push(topo);
    break;

    case 2:
    remover = Pop(&topo);
    printf("O valor %d foi desempilhado\n", remover->val);
    free(remover);  
    break;

    case 3:
    Mostra_pilha(topo);
    break;


    case 0:
    printf("Saindo . . .\n");
    Libera_pilha(topo);
    break;

    default:
    printf("Opção inválida\n");
    break;
  }
}while(op != 0);
  return 0;
}