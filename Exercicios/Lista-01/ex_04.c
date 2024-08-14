// Calcular o consumo médio de gasolina de um tanque de automóvel. Pedir para o usuário entrar com a distância (km) e volume (litros). Cm = d (km) / v (litros)

#include <stdio.h>

float consumo(float distancia, float volume) {
  return distancia/volume;
}

int main() {
  float distancia, volume;

  printf("Digite a distancia que o automovel percorre (km): ");
  scanf("%f", &distancia);
  
  printf("Digite a volume do tanque do automovel (litros): ");
  scanf("%f", &volume);

  printf("O consumo médio de gasolina do automovel e : %.1f km/L", consumo(distancia, volume));
}
