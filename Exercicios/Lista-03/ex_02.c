// Idem ao exercício resolvido, porém perguntar ao usuário se ele deseja continuar (S/N). Lembrar que a matriz ao ser definida deve conter necessariamente o tamanho.

#include <stdio.h>

int main() {
  int lista[100], *p_lista, tamanho = 0;
  char continuar= 'S';
  p_lista = lista;

  while (continuar == 'S')  {
    printf("Elemento %i: ", tamanho+1);
    scanf("%i", p_lista++);
    tamanho++;
    
    fflush(stdin);

    printf("Deseja continuar? (S/N): ");
    scanf("%c", &continuar);
  }

  p_lista = lista;
  printf("\nLista: ");
  
  for(int i = 0; i < tamanho; i++) {
    printf("\n num[%i] = %i", i, *(p_lista++));
  }
}