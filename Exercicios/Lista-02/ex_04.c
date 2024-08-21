// Faça um programa que, dado um string qualquer, inverta e armazene todas as suas letras sem auxílio de uma string auxiliar, ou seja, utilizando a mesma string. Apresente isso ao usuário.


#include <stdio.h>
#include <string.h>

int main() {
  char palavra[100], troca;
  int tamanho;

  printf("Digite uma palavra de até 100 caracteres: ");
  gets(palavra);

  tamanho = strlen(palavra) - 1;

  for(int i = 0; i < tamanho; i++, tamanho--) {
    troca = palavra[i];
    palavra[i] = palavra[tamanho];
    palavra[tamanho] = troca;
  }

  printf("A palavra invertida é: %s", palavra);
}
