// Melhore o programa, trocando as maiúsculas por minúsculas e vice-versa, quando necessário.
// Exemplo - Resultado: Snecaf Ad Sonula
//   Será necessário utilizar as funções toupper(char) e tolower(char), que transformam um caracter
// para maiúscula e minúscula respectivamente, ou
//   Utilizar os valores da tabela ASCII:A = 65, Z = 90 a = 97, z = 122, portanto para passar de
// MAIÚSCULA para minúscula basta somar 32 e o inverso, subtrair 32.

#include <stdio.h>
#include <string.h>

int main() {
  char palavra[100], palavra_invertida[100];
  int tamanho, if_espaco;

  printf("Digite uma palavra de até 100 caracteres: ");
  gets(palavra);

  tamanho = strlen(palavra);

  for(int i = 0; i < tamanho; i++) {
    if(palavra[tamanho - i - 1] == ' ') {
      if_espaco = 1;
      palavra_invertida[i] = ' ';
    
    } else {
      if(if_espaco) {
        palavra_invertida[i] = toupper(palavra[tamanho - i - 1]);
        if_espaco = 0;

      } else {
        palavra_invertida[i] = tolower(palavra[tamanho - i - 1]);
      }
    }
  }

  palavra_invertida[tamanho] = '\0';

  printf("A palavra invertida é: %s", palavra_invertida);
}


