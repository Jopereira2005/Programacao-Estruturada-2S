#include <stdio.h>
#include <stdlib.h>

void aloca(int **p_lista, int tam);
void mostrar(int *p_lista, int tam);
void impar(int *p_lista, int tam, int **p_impar, int *tam_impar);

int main() {
  int *p_lista = NULL;
  int *p_impar = NULL;

  int tam = 0;
  int tam_impar = 0;

  char op = 'S';

  while(op == 'S' || op  == 's') {
    aloca(&p_lista, tam+1);
    printf("Digite o %i numero: ", tam+1);
    scanf("%i", p_lista + tam);

    tam++;

    printf("Deseja continuar? (S/N): ");
    scanf(" %c", &op);
  }

  impar(p_lista, tam, &p_impar, &tam_impar);

  printf("\nLista: \n");
  mostrar(p_lista, tam);

  printf("\nLista soma impar: \n");
  mostrar(p_impar, tam_impar);
}

void aloca(int **p_lista, int tam) {
  if((*p_lista = (int*) realloc(*p_lista, tam * sizeof(int))) == NULL) {
    printf("Erro de Alocacao");
    exit(1);
  }
}

void mostrar(int *p_lista, int tam) {
  for(int i = 0; i < tam; i++) {
    printf("[%i] ", *(p_lista+i));
  }
}

void impar(int *p_lista, int tam, int **p_impar, int *tam_impar) {
  int sub = 0;
  for (int i = 0, cont = 0; i <= (tam/2); i++, cont++) {
    sub = *(p_lista+i+cont+1) - *(p_lista+i+cont);

    if(tam % 2 != 0) {
      if(i == tam/2) 
        sub = *(p_lista + tam - 1);
    }

    if(sub % 2 != 0) {
      aloca(p_impar, (*tam_impar)+1);
      *(*p_impar + *tam_impar) = sub;
      (*tam_impar)++;
    } 
  }
  
}
