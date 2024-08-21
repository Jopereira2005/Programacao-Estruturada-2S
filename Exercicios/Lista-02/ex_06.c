// Receba uma frase e uma letra do usuário, conte quantas ocorrências da letra existem na frase 

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char palavra[100], letra;
  int tamanho, letra_found = 0, quantidade = 0;
      
  printf("Digite uma palavra: ");
  fgets(palavra, 100, stdin);
          
  fflush(stdin);
              
  printf("Digite um caracter para a procura: ");
  scanf("%c", &letra);
                    
  tamanho = strlen(palavra);
                        
  for(int i = 0; i < tamanho - 1; i++) {
    if(tolower(palavra[i]) == tolower(letra)) {
      letra_found = 1;
      quantidade++;
    }
  }

  if(letra_found) {
    printf("Foram encontradas %i ocorrências da letra desejada.", quantidade);
  } else {
    printf("Carater não encontrado.");
  }                                                  
}