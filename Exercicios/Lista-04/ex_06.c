// Alocar  espaço  para  10  letras.  Mostrar  o  endereço  e  receber  do  usuário  as  letras.  Em  seguida, 
// alterá-las  da  seguinte  maneira:  se  o  usuário  digitou  MAIÚSCULA  deverá  transformar  para 
// minúscula e vice-versa.  Mostrar novamente o endereço (que deve ser o  mesmo)  com  as letras 
// modificadas. Utilizar função para alocação dinâmica. 
//  Dica: valores em ASCII 
//  A = 65   a = 97    MAIÚSCULA p/ minúscula = +32 
//  Z = 90   z = 122  minúscula p/ MAIÚSCULA = -32

#include <stdio.h>
#include <stdlib.h>

void aloca(char **p_letras, int tam);
void maiusculo_minusculo(char *p_letras, int tam);

int main() {
  char *p_letras = NULL;
  aloca(&p_letras, 10);

  for (int i = 0; i < 10; i++) {
    printf("Digite a letra %i: ", i+1);
    scanf(" %c", p_letras+i);
  }

  maiusculo_minusculo(p_letras, 10);

  for (int i = 0; i < 10; i++) {
    printf("\nLetra: %c ", *(p_letras+i));
  }
}

void aloca(char **p_letras, int tam) {
  if((*p_letras = (char *) realloc(*p_letras, tam * sizeof(char))) == NULL) {
    printf("Erro de alocacao de memoria\n");
    exit(1);
  }
}

void maiusculo_minusculo(char *p_letras, int tam) {
  for (int i = 0; i < tam; i++) {
    if (*(p_letras+i) >= 65 && *(p_letras+i) <= 90) {
      *(p_letras+i) += 32;
    } else if (*(p_letras+i) >= 97 && *(p_letras+i) <= 122) {
      *(p_letras+i) -= 32;
    }
  }
}