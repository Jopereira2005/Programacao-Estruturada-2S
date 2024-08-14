// Ler 2 notas e calcular a média

#include <stdio.h>

float media(float nota1, float nota2) {
  return (nota1 + nota2)/2;
}

int main() {
  float nota1, nota2;

  printf("Digite a primeira nota: ");
  scanf("%f", &nota1);
  
  printf("Digite a segunda nota: ");
  scanf("%f", &nota2);

  printf("A media é: %1.f", media(nota1, nota2));
  
}