// Faça um programa que, dado um string qualquer, procure dentro dele a ocorrência de um determinado caracter. 
// Exemplo: String: Facens – Computação Procurar pela letra: x
// Resultado: O caracter x não foi encontrado.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char palavra[100], letra;
  int tamanho, letra_found = 0;
      
  printf("Digite uma palavra: ");
  fgets(palavra, 100, stdin);
          
  fflush(stdin);
              
  printf("Digite um caracter para a procura: ");
  scanf("%c", &letra);
                    
  tamanho = strlen(palavra);
                        
  for(int i = 0; i < tamanho - 1; i++) {
    if(tolower(palavra[i]) == tolower(letra)) {
      letra_found = 1;
      break;
    }
  }

  if(letra_found) {
    printf("Caracter encotrado.");
  } else {
    printf("Carater não encontrado.");
  }                                                  
}