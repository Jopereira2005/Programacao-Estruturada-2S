// Ler um vetor (A) com 15 elementos. Construir um vetor B do mesmo tipo e tamanho, sendo que  cada elemento de B seja o fatorial 
// do elemento correspondente de A. (utilizar a função recursiva direta p/ fatorial).

#include <stdio.h>

void mostrar(int *p) {
  for(int i = 0; i < 15; i++) {
    printf("lista[%i] = %i\n", i+1, *(p++));
  }
}

int fatorial(int n) {
  if(n == 0) return 1;
  return n * fatorial(n-1);
}

int main () {
  int a[15], b[15], *p_a, *p_b;

  p_a = a;
  p_b = b;

  for(int i = 0; i < 15; i++) {
    printf("Elemento %i: ", i+1);
    scanf("%i", p_a++);
  }

  p_a = a;

  for(int i = 0; i < 15; i++) {
    *p_b++ = fatorial(*p_a++);
  }

  printf("\nLista A: ");
  mostrar(a);

  printf("\n ");

  printf("\nLista B: ");
  mostrar(b);
}