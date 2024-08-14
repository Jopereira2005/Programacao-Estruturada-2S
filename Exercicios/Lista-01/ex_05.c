// Calcular a área de uma esfera. A = 4 * π * r2

#include <stdio.h>

float areaEsfera(float raio) {
  return 4*3.14*(raio*raio);
} 

int main() {
  float raio;

  printf("Digite a raio da esfera (cm): ");
  scanf("%f", &raio);

  printf("A area da esfera é: %.1f cm2", areaEsfera(raio));
}
