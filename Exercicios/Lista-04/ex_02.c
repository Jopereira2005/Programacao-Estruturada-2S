// Aloque espaço para uma seqüência de números reais escolhida pelo usuário. Receba os valores 
// e imprima-os em ordem inversa. Utilizar função para alocação dinâmica.

#include <stdio.h>
#include <stdlib.h>

void aloca(float **p_num, int tam);
void recebe(float *p_num, int tam);

int main() {
  int tam;
  float *p_num = NULL;

  printf("Digite o tamanho da lista: ");
  scanf("%i", &tam);

  aloca(&p_num, tam);
  recebe(p_num, tam);

  printf("Lista em ordem inversa: \n");

 for(int i = tam-1; i >= 0; i--) {
    printf("[%.1f] ", *(p_num+i));
  }
}

void aloca(float **p_num, int tam) {
  if((*p_num = (float *) realloc(*p_num, tam * sizeof(float))) == NULL) {
    printf("Erro de alocacao de memoria\n");
    exit(1);
  }
}

void recebe(float *num, int tam) {
  for (int i = 0; i < tam; i++) {
    printf("Digite o numero %i: ", i+1);
    scanf("%f", num+i);
  }
}
