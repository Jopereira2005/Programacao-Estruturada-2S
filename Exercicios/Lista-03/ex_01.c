// Idem ao exercício resolvido, porém a quantidade de nºs reais deverá ser estipulada pelo usuário. Lembrar que a matriz ao ser definida deve conter necessariamente o tamanho.

#include <stdio.h>

int main() {
  int tamanho;

  printf("Digite o tamanho do array: ");
  scanf("%i", &tamanho);

  int lista[tamanho], *p_lista;
  p_lista = lista;

  for(int i = 0; i < tamanho; i++) {
    printf("Elemento %i: ", i+1);
    scanf("%i", p_lista++);
  }

  p_lista = lista;
  printf("\nLista: ");
  
  for(int i = 0; i < tamanho; i++) {
    printf("\n num[%i] = %i", i, *(p_lista++));
  }
}