#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct ME{
  int val;
  int col;
  struct ME *prox;
}No;
typedef No *pme;
typedef pme matriz[MAX];

void Inicializa(matriz m, int n){
  int i;
  for(i = 0; i <n; i++){
     m[i] = NULL;
  }
}

void Insere(matriz m){
  int line, col;
  int v;

  printf("Insira a linha e coluna que seu elemento ficará: ");
  scanf("%d %d", &line, &col);
  printf("Insira o valor do elemento: ");
  scanf("%d", &v);

  pme novo = (pme)malloc(sizeof(No));

  if(!novo){
    exit(1);
  }
  else{
    novo->val = v;
    novo->col = col;
    novo->prox = NULL;

    if(m[line] == NULL){
      m[line] = novo;
    }
    else{
      pme aux = m[line];
      while(aux->prox != NULL){
        aux = aux->prox;
      }
      novo->prox = aux->prox;
      aux->prox = novo;
    }
  } 
}

void Imprime(matriz m, int l, int c){
  int i, j;
  pme aux;

  for(i = 0; i < l; i++){
    aux = m[i];
    for(j = 0; j < c; j++){
      if(aux == NULL || aux->col != j){
        printf("0\t");
      }
      else{
        printf("%d\t", aux->val);
      }
    }
    printf("\n");
  }
  
}


void Libera(matriz m, int n){
  int i;
  pme aux;
  for(i = 0; i < n; i++){
    while(m[i] != NULL){
      aux = m[i];
      m[i] = m[i]->prox;
      free(aux);
    }
    
  }
      
}

void Insere_transposta(matriz m, int c, int v, int l){
  pme novo = (pme)malloc(sizeof(No));
  if(!novo){
    exit(1);
  }
  else{
    novo->val = v;
    novo->col = l;  
    novo->prox = NULL;

    if(m[c] == NULL){
      m[c] = novo;
    }
    else{
        pme aux = m[c];
        while(aux->prox != NULL){
          aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }
  }
}



void Transposta(matriz m, int l, int c){
  int i, j;
  pme aux;
  matriz mt;

  Inicializa(mt, c);

  for(i = 0; i < l; i++){
    aux = m[i];
    while(aux != NULL){
      Insere_transposta(mt, aux->col, aux->val, i);
      aux = aux->prox;
    }
    
  }
  Imprime(mt, c, l);
}


int main(void) {
  matriz m;
  int l, c;
  int op;
  
  printf("Insira a quantidade de linhas e colunas da matriz: ");
  scanf("%d %d", &l, &c);

  Inicializa(m, l);

  do{
  printf("\n1 - Inserir\n2 - Imprimir\n3 - Transposta\n0 - Sair\n\nInsira o que deseja: ");
  scanf("%d", &op);

  switch(op){
    case 1:
    Insere(m);
    break;

    case 2:
    Imprime(m, l, c);
    break;

    case 3:
    Transposta(m, l, c);
    break;

    case 0:
    Libera(m, l);
    break;

    default:
    printf("Opção inválida!\n");
    break;
  }
  

  }while(op != 0);
  
  return 0;
}