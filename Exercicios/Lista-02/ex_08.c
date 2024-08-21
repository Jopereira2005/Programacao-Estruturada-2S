// Faça um programa que, dado um string qualquer, procure dentro dele a ocorrência de outro string.
// Exemplo: String: Facens – Computação Procurar pelo string: put
// Resultado: O string put foi encontrado.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char palavra[100], procura[100];
  int tamanho, tamanho_trecho, word_found = 0, cont = 0;
      
  printf("Digite uma palavra: ");
  gets(palavra);
          
  fflush(stdin);
              
  printf("Digite um trecho para a procura: ");
  gets(procura);
            
  tamanho = strlen(palavra);
  tamanho_trecho = strlen(procura);
                        
  for(int i = 0; i < tamanho; i++) {
    if(tolower(palavra[i]) == tolower(procura[0])) {
      for(int j = 0, k = i; j < tamanho_trecho; j++, k++) {
        printf("\nprocura %c | palavra %c.", palavra[k], procura[j]); 
        if(palavra[k] == procura[j]) {
          cont++;  
        }
      }
      if(cont == tamanho_trecho) {
        word_found = 1;
        break;
      } else {
        word_found = 0;
      }
    }
  }

  if(word_found) {
    printf("\nA string %s foi encontrada.", procura); 

  } else {
    printf("\nString não encontrado.");
  }                                                 
}