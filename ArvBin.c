#include <stdio.h>
#include <stdlib.h>

typedef struct arv{
  int num;
  struct arv *esq;
  struct arv *dir;
}No;
typedef No * parv;
void Inicializa(parv *raiz){
  raiz = NULL;
}

void Insere(parv *raiz, int num){
  if(*raiz == NULL){
    *raiz = (parv)malloc(sizeof(No));
    (*raiz)->esq = NULL;
    (*raiz)->dir = NULL;
    (*raiz)->num = num;
  
  }else{
      if(num < (*raiz)->num){
        Insere(&(*raiz)->esq, num);
      
      }else{
        Insere(&(*raiz)->dir, num);
      }
  }
}

void Imprime(parv raiz){
   if(raiz){
     
     Imprime(raiz->esq);
     printf("%d\n",raiz->num);
     Imprime(raiz->dir);
   }
}

parv Busca(parv raiz, int num){
  if(raiz != NULL){
    if(num == raiz->num){
        return raiz;
    
    }else{
      if(num < raiz->num){
        return Busca(raiz->esq, num);
      }
      else{
        return Busca(raiz->dir, num);
      }
    }
  }
  return NULL;
}
int Soma_arvore(parv raiz){
  if(raiz != NULL){
    int soma_esq = Soma_arvore(raiz->esq);
    int soma_dir = Soma_arvore(raiz->dir);

    return raiz->num + soma_esq + soma_dir;
  } else {
    return 0;
  }
}

int Acha_maior(parv raiz, int maior_atual){
  if(raiz != NULL){
      if(raiz->num > maior_atual){
          maior_atual = raiz->num;
        
      }
    int maior_esq = Acha_maior(raiz->esq, maior_atual);
    int maior_dir = Acha_maior(raiz->dir, maior_atual);

     if(maior_esq > maior_dir){
        maior_atual = maior_esq;
     }
    else if(maior_esq < maior_dir){
      maior_atual = maior_dir;
    }
  }
  return maior_atual;
} 

int Nos_pares(parv raiz){
  if(raiz){
    int cont = 0;

    if(raiz->num % 2 == 0){
      cont++;
    }

    int cont_esq = Nos_pares(raiz->esq);
    int cont_dir = Nos_pares(raiz->dir);

    return cont + cont_esq + cont_dir;
  } else {
    return 0;
  }
}


int N_maiores(parv raiz, int x){
  if(raiz){
    int cont = 0;
    if(raiz->num >= x){
      cont++;
    }

    int cont_esq = N_maiores(raiz->esq, x);
    int cont_dir = N_maiores(raiz->dir, x);

    return cont + cont_esq + cont_dir;
  }
  else{
    return 0;
  }
}




    


void Libera_arv(parv raiz){
  if(raiz){
    Libera_arv(raiz->esq);
    Libera_arv(raiz->dir);
    free(raiz);
  }
  
}
int main(void) {
int op; 
parv raiz;
int v;
  int value;
  int maior;
  int nos_maiores;
Inicializa(&raiz);
  
 do{ 
  printf("1 - Inserir\n2 - Imprimir\n3 - Buscar\n4 - Maior elemento\n5 - Soma\n6 - Nós pares\n7 - Nós maiores\n\n0 - Sair\n\nInsira o que deseja: ");
  scanf("%d", &op);
  switch(op){
    case 1:
    printf("Insira o valor que deseja inserir: ");
    scanf("%d",&v);
    Insere(&raiz, v);
    break;
    

    case 2:
      printf("\n------Árvore------\n");
     Imprime(raiz); 
    break;

    case 3:
      printf("Insira o valor que deseja buscar: ");
      scanf("%d", &v);
      parv p;
      p = Busca(raiz, v);
      if(p){
        printf("Valor encontrado: %d\n", p->num);
      }
      else{
        printf("Valor não encontrado\n");
      }
    
    break;

    case 4:
     maior = Acha_maior(raiz, raiz->num);
      printf("O maior valor é: %d\n", maior);
    break;

    case 5:
      printf("Soma: %d\n", Soma_arvore(raiz));
    break;

    case 6:
      printf("Número de nós pares: %d\n", Nos_pares(raiz));
    break;
    

    case 7:
      printf("Insira o valor parâmetro: ");
      scanf("%d",&value);
      nos_maiores = N_maiores(raiz, value);
      printf("A árvore possui %d nós maiores que %d\n",nos_maiores, value);  
    break;

    case 0:
      printf("Saindo...\n");
      Libera_arv(raiz);
    break;
    
    default:
    printf("Opção inválida\n");
    break;
  }
   
 }while(op != 0);
  return 0;
}