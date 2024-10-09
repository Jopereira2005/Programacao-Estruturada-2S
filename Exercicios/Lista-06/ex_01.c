// Dado a estrutura abaixo, implemente uma rotina de cadastro, deve-se consultar o usuário 
// para  continuar.  O  registro  deve  ser  gerado  automaticamente  pelo  sistema.  Utilizar 
// alocação dinâmica e ponteiros para a estrutura. 
 
// struct agenda{ 
//   int reg; 
//   char nome[80]; 
//   float nota; 
// };

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct agenda {
  int reg; 
  char nome[80]; 
  float nota; 
} agenda;

void aloca(agenda **p_agenda, int tam);
void cadastro(agenda *p_agenda);
void mostrar(agenda *agenda, int tam);

int main() {
  int tam = 0;
  agenda *p_agenda = NULL;
  char op = 'S';

  while(op != 'N' && op != 'n') {
    aloca(&p_agenda, tam+1);
    cadastro(p_agenda+tam);
    tam++;

    printf("Deseja fazer mais um cadastro (S/N): ");
    scanf("%c", &op);
    fflush(stdin);
  }
  
  mostrar(p_agenda, tam);
}

void aloca(agenda **p_agenda, int tam) {
  if((*p_agenda = (agenda*) realloc(*p_agenda, tam * sizeof(agenda))) == NULL) {
    printf("Erro de alocação");
    exit(1);
  }
}

void cadastro(agenda *p_agenda) {
  static int registro = 1000;
  p_agenda->reg = registro;
  registro += 100;
  printf("--------------\n");
  printf("Digite o nome: ");
  fgets(p_agenda->nome, 80, stdin);

  fflush(stdin);

  printf("Digite uma nota: ");
  scanf("%f", &p_agenda->nota);

  printf("--------------\n");
  fflush(stdin);
}

void mostrar(agenda *agenda, int tam) {
  system("cls");
  for (int i = 0; i < tam; i++) {
    printf("Nome: %sNota: %.1f \nRegistro: %i\n\n", (agenda+i)->nome, (agenda+i)->nota, (agenda+i)->reg);
  }
}