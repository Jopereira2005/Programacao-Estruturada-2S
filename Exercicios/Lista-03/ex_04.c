// Ler e armazenar 2 notas, verificar se estão no intervalo de 0 à 10. Calcular a média para 100 alunos (utilizar matrizes) e verificar :
// se m >= 7 – imprimir APROVADO
// se 4 <= m < 7 – imprimir EXAME
// se m < 4 – imprimir REPROVADO.

#include <stdio.h>

int main() {
  float notas[2][5], media[5], tamanho = 5;
  float *p_notas, *p_media;

  p_notas = notas;
  p_media = media;

  for(int i = 0; i < tamanho; i++) {
    printf("Digite as notas do aluno %i: \n", i+1);
    for(int j = 0; j < 2; j++) {
      printf("Nota %i: ", j+1);
      scanf("%f", p_notas++);
      while (*p_notas < 0 || *p_notas > 10) {
        printf("Nota inválida. Digite uma nota entre 0 e 10: ");
        scanf("%f", p_notas);      
      }
    }
  } 
}