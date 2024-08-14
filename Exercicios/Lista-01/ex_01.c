// Calcular e mostrar o produto de 2 números

#include <stdio.h>

int mult(int num1, int num2) {
  return num1*num2;
}

int main() {
  int num1, num2;
  printf("Digite o primeiro numero: ");
  scanf("%i", &num1);
  
  printf("Digite o segundo numero: ");
  scanf("%i", &num2);

  printf("O produto de %i e %i é %i.", num1, num2, mult(num1, num2));
}