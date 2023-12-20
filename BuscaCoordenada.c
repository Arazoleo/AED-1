#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *ant;
    struct lista *prox;
}No;
typedef No *Plista;


void Insere(Plista *l, int v){
    Plista novo = (Plista)malloc(sizeof(No));
    if(!novo){
      exit(1);
    }
  else{
    novo->info = v;
    if(*l == NULL){
      novo->prox = novo;
      novo->ant = novo;
      *l = novo;
    }
    else{
       Plista aux = *l;
       while(aux->prox != *l && aux->prox->info < v){
         aux = aux->prox;
       }
       if(aux->prox == *l){
         novo->prox = *l;
         novo->ant = aux;
         aux->prox = novo;
         (*l)->ant = novo;
       }
      else{
        novo->prox = aux->prox;
        novo->ant = aux->ant;
        aux->prox = novo;
        novo->prox->ant = novo;
      }
    }
  }
}


int Busca_elemento(Plista l, int v){
  int contador = 1;
  Plista aux = l;

  

  
  if(l != NULL){
    while(aux->prox != l && contador < v){
      aux = aux->prox;
      contador++;
    }
    if(aux->prox != l){
      return aux->info;
    }
    else if(v > contador){
      printf("Valor não encontrado\n");
      return -1;
    }
  }
  
  else{
    return -1;
  }
}



void Imprime(Plista l){
  Plista aux = l;
  if(l != NULL){
    do{
      printf("%d\n", aux->info);
      aux = aux->prox;
        
  }while(aux != l);
}
  else{
    printf("Lista vazia\n");
  }
}

void Libera_lista(Plista l){
  Plista aux = l;
  if(l != NULL){
    do{
      aux = aux->prox;
      free(l);
      l = aux;
    }while(aux != l);
  }
}


int main(void) {
  int v, j;
  int op;
  Plista lista = NULL;
  int coordenada;

  do{
  printf("\n1 - Inserir\n2 - Buscar\n3 - Imprimir\n0 - Sair\n\nInsira a opção desejada: ");
  scanf("%d", &op);

  switch(op){
    case 1:
    printf("Insira o valor a ser inserido: ");
    scanf("%d", &v);
    Insere(&lista, v);
    break;

    case 2:
    printf("Insira a posição da lista: ");
    scanf("%d", &j);
    coordenada = Busca_elemento(lista, j);
      if(coordenada != -1){
    printf("O valor da coordenada é: %d", coordenada);
      }
    break;

    case 3:
    Imprime(lista);
    break;

    case 0:
    printf("Saindo...\n");
    Libera_lista(lista);
    break;

    default:
    printf("Opção inválida\n");
    break;
  }
    
  
  }while(op != 0);
  return 0;
}