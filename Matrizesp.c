#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct ME{
   int num;
   int col;
   struct ME *prox;
}No;
typedef No *pme;
typedef pme matriz[MAX];
void Inicializa_matriz(matriz m, int l){
  int i;
  for(i = 0; i < l; i++){
    m[i] = NULL;
  }
}

pme cria_no(int c, int v){
  pme novo = (No*)malloc(sizeof(No));
  if(!novo){
    exit(1);
  }
  else{
    novo->num = v;
    novo->col = c;
    novo->prox = NULL;
    return novo;
  }
}

void Insere_matriz(matriz m, pme p, int l){
  if(m[l] == NULL){
    m[l] = p;
  }
  else{
    pme temp = m[l];
    while(temp->prox){
      temp = temp->prox;
    }
    temp->prox = p;
  }
}
void Printa_matriz(matriz m, int l, int c){
  int i, j;
  pme temp;
  for(i = 0; i < l; i++){
    temp = m[i];
    for(j = 0; j < c; j++){
      if(temp==NULL || temp->col != j){
        printf("0\t");
      }
      else{
        printf("%d\t", temp->num);
      }
    }
    printf("\n");
  }
}


void Remove_valor(matriz m, int l, int v) {
  int i;
  pme temp, ant;

  for (i = 0; i < l; i++) {
    ant = NULL;
    temp = m[i];

    while (temp && temp->num != v) {
      ant = temp;
      temp = temp->prox;
    }

    if (temp && temp->num == v) {
      if (ant == NULL) {
        m[i] = temp->prox;
      } else {
        ant->prox = temp->prox;
      }

      free(temp);
  
    } 
    
    
  }
}


void Libera(matriz m, int l){
  int i;
  pme aux, aux2;
  for(i = 0; i < l; i++){
    aux = m[i];
    while(aux){
       aux2 = aux;
       aux = aux->prox;
       free(aux2);
  }

    m[i] = NULL;
}
}
int main(void) {
  int linhas, colunas;
  int op;
  int line, column;
  int value;
  int remover;
  pme p;
  matriz m;
  printf("Insira a quantidade de linhas e colunas da Matriz: ");
  scanf("%d %d", &linhas, &colunas);

  Inicializa_matriz(m, linhas);
do{
  printf("1 - Inserir\n2 - Remover\n3 - Mostrar\n0 - Sair\n\nInsira o que deseja: ");
  scanf("%d",&op);
  switch(op){
    case 1:
     printf("Insira a linha e a coluna que deseja inserir o elemento: ");
     scanf("%d %d", &line, &column);
     printf("Insira o valor que deseja inserir: ");
    scanf("%d", &value);
     p = cria_no(column, value);
    Insere_matriz(m, p ,line);
    break;
  
  case 2:
    printf("Insira o valor que deseja remover: ");
    scanf("%d", &remover);
    Remove_valor(m, linhas, remover);
    break;
  

  case 3:
    Printa_matriz(m, linhas, colunas);
    break;

  case 0:
    Libera(m, linhas);
    break;

  default:
    printf("Opção inválida");
    break;
  }
}while(op != 0);
  
  return 0;
}