#include <stdio.h>
#include <stdlib.h>

void aloca(int **p_lista, int tamanho);
void mostra(int *p_lista, int tamanho);
void posititvo(int *p_lista, int tamanho, int **p_lista_pos, int *tam_pos);

int main() {
  int *p_lista = NULL;
  int *p_positivo = NULL;
  int tamanho = 0;
  int tam_pos = 0;

  char op = 'S';

  while(op == 'S' || op == 's') {
    aloca(&p_lista, tamanho+1);
    printf("Digite o %i numero: ", tamanho+1);
    scanf("%i", p_lista+tamanho);
    tamanho++;

    printf("Deseja continuar? (S/N): ");
    scanf(" %c", &op);
  }

  posititvo(p_lista, tamanho, &p_positivo, &tam_pos);
  mostra(p_lista, tamanho);

  printf("\n-----------------------------------\n");

  mostra(p_positivo, tam_pos);
}

void aloca(int **p_lista, int tamanho) {
  if((*p_lista = (int*) realloc(*p_lista, tamanho * sizeof(int))) == NULL) {
    printf("Erro de Alocacao");
    exit(1);
  }
}

void mostra(int *p_lista, int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    printf("[%i] ", *(p_lista+i));
  }
}

void posititvo(int *p_lista, int tamanho, int **p_lista_pos, int *tam_pos) {
  int soma = 0;
  for (int i = 0; i <= tamanho/2; i++) {
    soma = *(p_lista+(i*2)) + *(p_lista+(i*2) + 1);

    if(tamanho % 2 != 0) {
      if(i == (tamanho/2)) {
        soma = *(p_lista+tamanho-1);
      }
    }

    if(soma >= 0) {
      aloca(p_lista_pos, (*tam_pos)+1);
      *(*p_lista_pos+*tam_pos) = soma;
      (*tam_pos)++;
    }
  }
}



