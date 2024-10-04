#include <stdio.h>
#include <stdlib.h>

void aloca(int **p_num, int tam);
void leitura(int *p_num);
void par(int *p_num, int tam, int **p_num_par, int *tam_par);
void mostrar(int *p_num, int tam);

int main() {
  int *p_lista = NULL;
  int *p_lista_par = NULL;

  int tam = 0;
  int tam_lista_par = 0;

  char op = 'S';

  while (op == 'S' || op == 's') {
    aloca(&p_lista, tam+1);

    printf("\nDigite o %i numero: ", tam+1);
    leitura(p_lista+tam);
    tam++;
    printf("----------------------");

    printf("\nDeseja continuar? (S/N): ");
    scanf(" %c", &op);
    fflush(stdin);
  }

  printf("\nLista: \n");
  mostrar(p_lista, tam);
  
  printf("\nLista Par: \n");
  par(p_lista, tam, &p_lista_par, &tam_lista_par);
  mostrar(p_lista_par, tam_lista_par);
}

void aloca(int **p_num, int tam) {
  if((*p_num = (int *) realloc(*p_num, tam * sizeof(int))) == NULL) {
    printf("Erro de alocacao de memoria\n");
    exit(1);
  }
}

void leitura(int *p_num) {
  scanf("%i", p_num);
}

void par(int *p_num, int tam, int **p_num_par, int *tam_par) {
  int soma = 0;
  for(int i = 0; i <= (tam/2); i++) {
    if(i == (tam/2)) {
      soma = *(p_num+i);
    } else {
      soma = *(p_num+i) + *(p_num+tam-i-1);
    }

    if(soma % 2 == 0) {
      aloca(p_num_par, *tam_par+1);
      *(*p_num_par + *tam_par) = soma;
      (*tam_par)++;
    }
  }
}

void mostrar(int *p_num, int tam) {
  for (int i = 0; i < tam; i++) {
    printf("[%i] ", *(p_num+i));
  }
}
