// Idem ao exercício anterior, porém a seqüência de números reais deverá ser digitada pelo usuário, 
// até  que  este  escolha  a  opção  N  (Deseja  continuar?  (S/N)).  Utilizar  função  para  alocação 
// dinâmica. 

#include <stdio.h>
#include <stdlib.h>

void aloca(float **p_num, int tam);

int main() {
  float *p_num = NULL;
  int tam = 1;
  char op = 'S';

  while(op == 'S' || op == 's') {
    aloca(&p_num, tam);
    printf("Digite o numero %i: ", tam);
    scanf("%f", p_num+tam-1);
    tam++;

    printf("Deseja continuar? (S/N): ");
    scanf(" %c", &op);
  }

  for (int  i = 0; i < tam-1; i++) {
    printf("[%.1f] ", *(p_num+i));
  }
}

void aloca(float **p_num, int tam) {
  if((*p_num = (float *) realloc(*p_num, tam * sizeof(float))) == NULL) {
    printf("Erro de alocacao de memoria\n");
    exit(1);
  }
}