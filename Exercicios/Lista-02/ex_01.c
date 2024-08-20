// Faça um programa que, dado um string qualquer, inverta todas as suas letras e apresente isso ao usuário.
// Exemplo:
// String: Alunos da Facens
// Resultado: snecaF ad sonulA

#include <stdio.h>
#include <string.h>

int main() {
  char palavra[100], palavra_invertida[100];
  int tamanho;

  printf("Digite uma palavra de até 100 caracteres.");
  gets(palavra);

  tamanho = strlen(palavra);

  for(int i = 0; i < tamanho; i++) {
    palavra_invertida[i] = palavra[tamanho - i - 1];
  }

  palavra_invertida[tamanho] = '\0';

  printf("A palavra invertida é: %s", palavra_invertida);
  
}


