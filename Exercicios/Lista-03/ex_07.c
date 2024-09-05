// Ler 10 elementos de um vetor. Verificar e mostrar a média dos elementos.

#include <stdio.h>

int main() {
  int lista[10], *p_lista, aux;
  p_lista = lista;

  for(int i = 0; i < 10; i++) {
    printf("Elemento %i: ", i+1);
    scanf("%i", p_lista++);
  }

  p_lista = lista;

  for(int i = 0, size_limit = 10; i < 10; i++, size_limit--) {
    for(int j = 0; j < size_limit - 1; j++) {
      if(*(p_lista+j+1) < *(p_lista+j)) {
        aux = *(p_lista+j+1);
        *(p_lista+j+1) = *(p_lista+j);
        *(p_lista+j) = aux;
      }  
    }
  }

  p_lista = lista;

  printf("\nLista Ordenada: ");
  for(int i = 0; i < 10; i++) {
    printf("\n num[%i] = %i", i+1, *(p_lista++));
  }

}