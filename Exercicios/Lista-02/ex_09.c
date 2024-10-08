// Nome JEDI – para compor um nome conforme o costume JEDI, do filme Guerra nas Estrelas, é necessário fazer a seguinte composição:
// - Nome Jedi: as 3 primeiras letras do primeiro nome + as 2 primeiras letras do sobrenome
// - Sobrenome Jedi: as 2 primeiras letras do nome da mãe + as 3 primeiras letras da cidade em que nasceu
// - Nome composto: as 3 primeiras letras do nome Jedi + as 3 últimas letras do sobrenome Jedi.
// Exemplo:
// Nome: José da Silva
// Nome da mãe: Maria da Silva
// Cidade em que nasceu: Sorocaba
// Nome Jedi: Jossi Masor
// Nome composto: Jos-Sor

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void formatador(int tamanho, char string[]) {
  for(int i = tamanho; i >= 1; i--) {
    if(string[i] == ' ' || string[i] == '-') {
      string[i + 1] = toupper(string[i + 1]);
    } else {
      string[i] = tolower(string[i]); 
    }
  }
  string[0] = toupper(string[0]);
}

int main() {
  char nome[100], nome_mae[100], nome_cidade[100], nome_jedi[12], nome_comp[8];
  int tamanho;
  printf("Nome: ");
  gets(nome);

  printf("Nome da mãe: ");
  gets(nome_mae);

  printf("Cidade: ");
  gets(nome_cidade);

  tamanho = strlen(nome);

  for(int i = 0; i < tamanho; i++) {
    if(nome[tamanho - i - 1] == ' ') {
      for(int j = 0, cont = 0; j < 5; j++) {
        if(j < 3) {
          nome_jedi[j] = nome[j];
        } else {
          nome_jedi[j] = nome[tamanho - i - cont];
          cont--;
        }
      }
      break;
    }
  }

  nome_jedi[5] = ' ';

  for(int i = 0, j = 6, cont = 0; i < 5; i++, j++) {
    if(i < 2) {
      nome_jedi[j] = nome_mae[i];
    } else {
      nome_jedi[j] = nome_cidade[cont];
      cont++;
    }
  }

  nome_jedi[11] = '\0';
  
  for (int i = 0, cont = 8; i < 7; i++) {
    if(i < 3) {
      nome_comp[i] = nome_jedi[i];
    } else if(i == 3) {
      nome_comp[i] = '-';
    } else {
      nome_comp[i] = nome_jedi[cont];
      cont++;
    }
  }

  nome_comp[7] = '\0';

  formatador(11, nome_jedi);
  formatador(7, nome_comp);

  printf("\Nome Jedi: %s", nome_jedi);
  printf("\nNome Composto: %s", nome_comp);
}
