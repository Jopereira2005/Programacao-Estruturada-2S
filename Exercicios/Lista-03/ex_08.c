// Crie uma tabela (vetor) que armazene as temperaturas diárias registradas durante um mês e em 
// seguida elabore um programa que calcule : 
// • A maior temperatura e o dia em que ocorreu 
// • A temperatura média mensal 
// • As temperaturas inferiores à média e os dias em que ocorreram. 

#include <stdio.h>

void ler_temp(int *p_temp);
void vmaior_temp(int *p_temp, int *maior_temp);
float vmedia_mensal(int *p_temp);
int vtemp_inferior_media(int *p_temp, int *temp_inferior_media, float media);

int main() {
  int temp[31], maior_temp[2], temp_inferior_media[31], cont;
  float media;

  ler_temp(temp);

  vmaior_temp(temp, maior_temp);
  printf("A maior temperatura foi %i \xA7 C no dia %i\n", *(maior_temp), *(maior_temp+1));

  media = vmedia_mensal(temp);
  printf("A temperatura media mensal foi %.0f\xA7 C\n", media);

  cont = vtemp_inferior_media(temp, temp_inferior_media, media);

  printf("As temperaturas inferiores a media foram: \n");

  for (int i = 0; i < cont; i++) {
    printf("%i\xA7 C no dia %i\n", *(temp_inferior_media+i), i+1);
  }
}

void ler_temp(int *p_temp) {
  for (int i = 0; i < 31; i++)  {
    printf("Temperatura do dia %i: ", i+1);
    scanf("%i", p_temp+i);
  }
}

void vmaior_temp(int *p_temp, int *maior_temp) {
  *maior_temp = *p_temp;
  for(int i = 0; i < 31; i++) {
    if(*(p_temp+i) > *maior_temp) {
      *maior_temp = *(p_temp+i);
      *(maior_temp+1) = i;
    }
  }
}

float vmedia_mensal(int *p_temp) {
  float m = 0;
  for(int i = 0; i < 31; i++) {
    m += *(p_temp+i);
  }
  return m/31;
}

int vtemp_inferior_media(int *p_temp, int *temp_inferior_media, float media) {
  int j = 0;
  for(int i = 0; i < 31; i++) {
    if(*(p_temp+i) < media) {
      *(temp_inferior_media++) = *(p_temp+i);
      j++;
    }
  }
  return j;
}

