// Alocar espaço para 10 números reais. Mostrar o endereço e receber do usuário os valores. Em 
// seguida, alterar esses valores, somando 30 a cada elemento. Mostrar novamente o endereço (que 
// deve ser o mesmo) com o novo valor. Utilizar função para alocação dinâmica.

#include <stdio.h>
#include <stdlib.h>

void aloca(float **p_num, int tam);
void ler_endereco(float *p_num, int tam);
void altera_valores(float *p_num, int tam);

int main() {
  float *p_num = NULL;

  aloca(&p_num, 10);
  ler_endereco(p_num, 10);
  altera_valores(p_num, 10);
}

void aloca(float **p_num, int tam) {
  if((*p_num = (float *) realloc(*p_num, tam * sizeof(float))) == NULL) {
    printf("Erro de alocacao de memoria\n");
    exit(1);
  }
}

void ler_endereco(float *p_num, int tam) {
  for (int i = 0; i < tam; i++) {
    printf("Endereco %p: ", p_num+i);
    scanf("%f", p_num+i);
  }
}

void altera_valores(float *p_num, int tam) {
  for (int i = 0; i < tam; i++) {
    *(p_num+i) += 30;
    printf("Endereco %p: %.1f\n", p_num+i, *(p_num+i));
  }
}
