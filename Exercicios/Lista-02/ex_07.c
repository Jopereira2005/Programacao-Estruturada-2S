// Melhore o seu programa e mostre as posições em que as letras aparecem.

// Receba uma frase e uma letra do usuário, conte quantas ocorrências da letra existem na frase 

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char palavra[100], letra;
  int tamanho, letra_found = 0, quantidade = 0;
      
  printf("Digite uma palavra: ");
  gets(palavra);
          
  fflush(stdin);
              
  printf("Digite um caracter para a procura: ");
  scanf("%c", &letra);
                    
  tamanho = strlen(palavra);
  int posicoes[tamanho];
                        
  for(int i = 0; i < tamanho - 1; i++) {
    if(tolower(palavra[i]) == tolower(letra)) {
      posicoes[quantidade] = i;
      letra_found = 1;
      quantidade++;
    }
  }

  if(letra_found) {
    printf("Foram encontradas %i ocorrências da letra desejada, nas posições:", quantidade);
    for (int i = 0; i < quantidade; i++) {
      printf(" [%i]", posicoes[i]);
    }
  } else {
    printf("Carater não encontrado.");
  }                                                  
}