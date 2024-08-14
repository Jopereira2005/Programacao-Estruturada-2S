// Receber um nº inteiro longo do usuário e calcular o fatorial. Utilizar função recursiva direta.

long int fatorial(int num) {
  if(num == 1 || num == 0) {
    return 1;
  } else {
    return (num * fatorial(num-1));
  } 
}

int main() {
  long int numero;

  printf("Digite um numero: ");
  scanf("%i", &numero);

  printf("O fatorial de %i e: %i", numero, fatorial(numero));
}