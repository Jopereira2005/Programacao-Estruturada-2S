// Ler 10 elementos de um vetor. Verificar e mostrar o maior elemento.

#include <stdio.h>

int main() {
  int lista[10], *p_lista, maior;
  p_lista = lista;

  for(int i = 0; i < 10; i++) {
    printf("Elemento %i: ", i+1);
    scanf("%i", p_lista++);
  }

  p_lista = lista;
  maior = *p_lista;

  for(int i = 0; i < 10; i++) {
    if (*p_lista > maior) {
      maior = *p_lista;
    }
    p_lista++;
  }

  p_lista = lista;

  printf("\nLista: ");
  for(int i = 0; i < 10; i++) {
    printf("\n num[%i] = %i", i+1, *(p_lista++));
  }

  printf("\nMaior elemento: %i", maior);
}