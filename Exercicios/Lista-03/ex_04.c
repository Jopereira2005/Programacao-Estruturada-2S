// Ler e armazenar 2 notas, verificar se estão no intervalo de 0 à 10. Calcular a média para 100 alunos (utilizar matrizes) e verificar :
// se m >= 7 – imprimir APROVADO
// se 4 <= m < 7 – imprimir EXAME
// se m < 4 – imprimir REPROVADO.

#include <stdio.h>

int main() {
  float notas[2][100], media[5], tamanho = 100;
  float *p_notas, *p_media;

  p_notas = notas;
  p_media = media;

  for(int i = 0; i < tamanho; i++) {
    printf("Digite as notas do aluno %i: \n", i+1);
    for(int j = 0; j < 2; j++) {
      printf("Nota %i: ", j+1);
      scanf("%f", p_notas + i*2 + j);
      while (*p_notas < 0 || *p_notas > 10) {
        printf("Nota invalida. Digite uma nota entre 0 e 10: ");
        scanf("%f", p_notas);      
      }
    }
    printf("\n");
  } 

  p_notas = notas;
  p_media = media;

  for(int i = 0; i < tamanho; i++) {
    *p_media = (*p_notas + *(p_notas + 1)) / 2;
    p_media++;
    p_notas += 2;
  }

  p_notas = notas;
  p_media = media;

  for(int i = 0; i < tamanho; i++) {
    printf("Aluno %i: ", i+1);

    if (*p_media >= 7) {
      printf("APROVADO\n");
    } else if (*p_media >= 4 && *p_media < 7) {
      printf("EXAME\n");
    } else {
      printf("REPROVADO\n");
    }
  }
}