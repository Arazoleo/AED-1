#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue{
   int idade;
   char nome[20];
   char prioridade[15];
   struct queue *prox;

}No;
typedef No *pfila;

void Inicializa_fila(pfila *f){
  *f = NULL;
}

pfila Cria_no(int i, char *n, char *p){
  pfila novo = (No*)malloc(sizeof(No));
  if(!novo){
    exit(5);
  }
  else{
    novo->idade = i;
    strcpy(novo->nome, n);
    strcpy(novo->prioridade, p);
    novo->prox = NULL;
    return novo;
  }
}
void Insere_fila(pfila *f, pfila p){
  pfila aux = *f;
  if(*f == NULL){
    p->prox = NULL;
    *f = p;
      }

  else{
    if(p->idade > 60 || strcmp(p->prioridade, "sim") == 0){
      if((*f)->idade > 60 || strcmp((*f)->prioridade, "sim") == 0){
        while(aux->prox != NULL && (aux->prox->idade > 60 || strcmp(aux->prox->prioridade, "sim") == 0)){
          aux = aux->prox;
        }
        if(aux->prox != NULL){
          p->prox = aux->prox;
          aux->prox = p;
        }
        }
      else{
        p->prox = *f;
        *f = p;
      }
      
    }
    else{
      while(aux->prox != NULL){
        aux = aux->prox;
      }
      p->prox = aux->prox;
      aux->prox = p;
    }
    }
}

void Remover_fila(pfila *f){
  pfila aux = *f;
  if(*f == NULL){
    printf("Fila vazia\n");
    return;
  }
  else{
    *f = aux->prox;
    free(aux);
  }
  }
  


 void Mostra_fila(pfila f){
   pfila aux = f;
   if(f == NULL){
     printf("Fila vazia\n");
     return;
   }
   else{
   while(aux != NULL){
     printf("Nome: %s\n", aux->nome);
     printf("Idade: %d\n", aux->idade);
     printf("Prioridade: %s\n", aux->prioridade);
     aux = aux->prox;
   }
   }
 }
 
void Libera_fila(pfila *f){
  
}


int main(void) {
  pfila p; 
  pfila fila;
  int op;
  char name[20];
  int old;
  char prio[15];
   Inicializa_fila(&fila);

  do{
  printf("1 - Entrar na fila\n2 - Sair da fila\n3 - Mostrar fila\n0 - Sair\n\nInsira o que deseja: ");
  scanf("%d", &op);

  switch(op){
    case 1:
    getchar();
    printf("Insira seu nome: ");
    scanf("%[^\n]", name);
    printf("Insira sua idade: ");
    scanf("%d", &old);
    printf("É portador de deficiência ou é gestante? ");
    scanf("%s", prio);  
    
    p = Cria_no(old, name, prio);
    Insere_fila(&fila, p);
    break;

    case 2:
    Remover_fila(&fila);
    break;

    case 3:
    Mostra_fila(fila);
    break;

    case 0:
    printf("Saindo. . .\n");
    break;

    default:
    printf("Opção inválida. Tente novamente.\n");
    break;
    
  }
}while(op != 0);
  
  return 0;
}