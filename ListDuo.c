#include <stdio.h>
#include <stdlib.h>

typedef struct list{
  char letra;
  struct list *prox;
  struct list *ant;
}No;
typedef No * pLista;



void Insere_lista(pLista *l, char c){
  pLista novo = (pLista)malloc(sizeof(No));
  if(!novo){
    exit(5);
  }
  else{
    novo->letra = c;
    if(*l == NULL){
      novo->prox = NULL;
      novo->ant = NULL;
      *l = novo;
    }
    else{
      pLista aux = *l;
      while(aux->prox != NULL){
        aux = aux->prox;
      }

        novo->ant = aux;
        novo->prox = aux->prox;
        aux->prox = novo;

    }
  }
}
void Imprime_lista(pLista l){
  pLista aux = l;
  if(!l){
    printf("Lista vazia");
    return;
  }
  while(aux != NULL){
    printf("%c", aux->letra);
    aux = aux->prox;
  }
  printf("\n");
}

int Verifica_palindromo(pLista l){
  if(!l){
    return 0;
  }
  else{
    pLista aux = l;
    while(aux->prox != NULL){
      aux = aux->prox;
    }
    pLista aux2 = l;
    while(aux2 != aux){
      if(aux2->letra != aux->letra){
        return 0;
      }
      aux2 = aux2->prox;
      aux = aux->ant;
    }
    return 1;
  }
}

void Libera_lista(pLista l){
  pLista aux = l;
  pLista aux2;
  while(aux != NULL){
    aux2 = aux->prox;
    free(aux);
    aux = aux2;
  }
}

int main(void) {
  int i;
  char palavra [20];
  pLista lista = NULL;
  int palindromo;
  
  printf("Insira uma palavra: ");
  scanf("%s", palavra);
    for(i = 0; palavra[i] != '\0'; i++){
      Insere_lista(&lista, palavra[i]);
    }
  printf("Sua palavra é : ");
  Imprime_lista(lista);

  palindromo = Verifica_palindromo(lista);

  if(palindromo == 0){
    printf("Sua palavra não é um palindromo\n");
  }
  else{
    printf("Sua palavra é um palindromo\n");
  }

  Libera_lista(lista);
  return 0;
}