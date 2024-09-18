// Receber  do  usuário  seu  primeiro  nome  em  uma  string  auxiliar,  alocar  espaço  suficiente  para 
// armazenar  o  nome.  Mostrar  o  endereço  e  o  nome  armazenado.  Em  seguida,  alterar  o  nome  da 
// seguinte maneira: 1ª letra com a última, a 2ª com a penúltima e assim sucessivamente (utilizar uma 
// variável auxiliar). Mostrar novamente o endereço (que deve ser o mesmo) com o nome modificado. 
// Utilizar função para alocação dinâmica.

#include <stdio.h>
#include <stdlib.h>

void aloca(char **p_nome, int tam);
void pegar_nome(char **p_nome, int *tam);

int main() {
  char *p_nome = NULL;
  int tamanho = 0;

  printf("Digite seu primeiro nome: ");
  pegar_nome(&p_nome, &tamanho);
  
  printf("Endereco: %p ", p_nome);
  printf("\nNome: %s ", p_nome);

  for (int i = 0; i < (tamanho)/2; i++) {
    char c = *(p_nome+i);
    *(p_nome+i) = *(p_nome+tamanho-i-1);
    *(p_nome+tamanho-i-1) = c;
  }

  printf("\n\nEndereco: %p ", p_nome);
  printf("\nNome: %s ", p_nome);
  free(p_nome);
}

void aloca(char **p_nome, int tam) {
  if((*p_nome = (char *) realloc(*p_nome, tam * sizeof(char))) == NULL) {
    printf("Erro de alocacao de memoria\n");
    exit(1);
  }
}

void pegar_nome(char **p_nome, int *tam) {
  char c;
  while((c = getchar()) != '\n') {
    aloca(p_nome, *tam+1);
     *(*p_nome + *tam) = c;
    (*tam)++;
  }
  *(*p_nome + *tam) = '\0';
}