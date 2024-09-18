// Aloque dinamicamente a seqüência de números reais digitados pelo usuário, até que este escolha 
// a opção N (Deseja continuar? (S/N)). Em seguida, exiba a média dos elementos (não considerar 
// as ocorrências com valor = 0). Utilizar função para alocação dinâmica.

#include <stdio.h>
#include <stdlib.h>

void aloca(float **p_num, int tam);
void calc_media(float *p_num, int tam);

int main() {
  float *p_num = NULL;
  int tam = 0;
  char op;

  do {
    aloca(&p_num, tam+1);
    printf("Digite o numero %i: ", tam+1);
    scanf("%f", p_num+tam);
    tam++;

    printf("Deseja continuar? (S/N): ");
    scanf(" %c", &op);

  } while(op != 'N' && op != 'n');

  calc_media(p_num, tam);
}

void aloca(float **p_num, int tam) {
  if((*p_num = (float *) realloc(*p_num, tam * sizeof(float))) == NULL) {
    printf("Erro de alocacao de memoria\n");
    exit(1);
  }
}

void calc_media(float *p_num, int tam) {
  float media = 0;
  for (int i = 0; i < tam; i++) {
    if(*(p_num+i) != 0) {
      media += *(p_num+i);
    }
  }
  media /= tam;
  printf("A media dos numeros digitados e: %.1f\n", media);
}