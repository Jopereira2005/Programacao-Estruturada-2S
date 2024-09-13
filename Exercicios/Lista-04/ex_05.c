// Alocar espaço para armazenar as temperaturas diárias registradas durante um mês. O programa 
// deve mostrar diariamente (a medida que as temperaturas são incluídas) a maior temperatura e o 
// dia em que ocorreu. Utilizar função para alocação dinâmica.

#include <stdio.h>
#include <stdlib.h>

void aloca(float **p_temp, int tam);
void maior_temp(float *p_temp, int tam);

int main() {
  float *p_temp = NULL;
  int tam = 0;

  while (tam <= 30) {
    aloca(&p_temp, tam + 1);
    printf("Digite a temperatura do dia %i: ", tam + 1);
    scanf("%f", p_temp+tam);
    tam++;

    maior_temp(p_temp, tam);
  }
  
  free(p_temp);
}

void aloca(float **p_temp, int tam) {
  if((*p_temp = (float *) realloc(*p_temp, tam * sizeof(float))) == NULL) {
    printf("Erro de alocacao de memoria\n");
    exit(1);
  }
}

void maior_temp(float *p_temp, int tam) {
  float maior = *p_temp;
  int dia = 1;
  for (int i = 0; i < tam; i++) {
    if (*(p_temp+i) > maior) {
      maior = *(p_temp+i);
      dia = i+1;
    }
  }  
  printf("A maior temperatura registrada foi %.1f no dia %i\n", maior, dia);
}