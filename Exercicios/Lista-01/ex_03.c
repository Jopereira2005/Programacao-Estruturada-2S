// Pedir a idade para o usuário e calcular quantos meses e dias de vida ele tem aproximadamente.

#include <stdio.h>

int idadeEmMes(int idade) {
  return idade*12;
}

int idadeEmDia(int idade) {
  return idade*12*30;
}

int main() {
  int idade;

  printf("Digite a sua idade: ");
  scanf("%i", &idade);

  printf("A sua idade em meses e em dias é aproximadamente: %i e %i", idadeEmMes(idade), idadeEmDia(idade));
}