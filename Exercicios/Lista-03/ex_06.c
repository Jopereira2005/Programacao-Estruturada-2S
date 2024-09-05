// Ler 10 elementos de um vetor. Verificar e mostrar a média dos elementos.

#include <stdio.h>

int main() {
  int lista[10], *p_lista;
  float media = 0;
  p_lista = lista;

  for(int i = 0; i < 10; i++) {
    printf("Elemento %i: ", i+1);
    scanf("%i", p_lista++);
  }

  p_lista = lista;

  for(int i = 0; i < 10; i++) {
    media += *p_lista;
    p_lista++;
  }
  media /= 10;

  p_lista = lista;

  printf("\nLista: ");
  for(int i = 0; i < 10; i++) {
    printf("\n num[%i] = %i", i+1, *(p_lista++));
  }

  printf("\nA media dos elementos: %.1f", media);
}