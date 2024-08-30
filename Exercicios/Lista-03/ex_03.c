// Realizar a soma de 2 vetores A e B de nºs reais e de tamanho igual ou inferior a 100 (n<=100) e gerar um vetor resultante C onde
// C[i] = A[i] + B[i]

#include <stdio.h>

int main() {
  int vetor_A[100], vetor_B[100], vetor_C[100], tamanho;
  int *p_vetor_A, *p_vetor_B, *p_vetor_C;

  p_vetor_A = vetor_A;
  p_vetor_B = vetor_B;
  p_vetor_C = vetor_C;

  printf("Digite o tamanho dos vetores: ");
  scanf("%i", &tamanho);


  printf("Vetor A \n");
  for(int i = 0; i < tamanho; i++) {
    printf("Elemento A[%i]: ", i+1);
    scanf("%i", p_vetor_A);
  }

  printf("Vetor B \n");
  for(int i = 0; i < tamanho; i++) {
    printf("Elemento A[%i]: ", i+1);
    scanf("%i", p_vetor_B);
  }

  p_vetor_A = vetor_A;
  p_vetor_B = vetor_B; 

  printf("Vetor C (Soma entre A e B) \n");
  for(int i = 0; i < tamanho; i++) {
    *(p_vetor_C) = *(p_vetor_A) + *(p_vetor_B);
    printf("Elemento C[%i]: %i\n", i+1, *(p_vetor_C));
  }
}