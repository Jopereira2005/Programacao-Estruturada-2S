// Fazer  um  programa  para  Diário  Eletrônico  –  este  programa  se  destina  a  controlar  as 
// notas  e  a  média  dos  alunos.  Consultar  o  usuário  para  continuar.  Utilizar  alocação 
// dinâmica e ponteiros para a estrutura. 
 
// [1] Cadastro - receber os valores digitados pelo usuário, inicialmente notas e média=0. Apenas 
// um registro é cadastrado por vez. 
 
// [2] Controle de Notas - o acesso deve ser feito através do RA. Buscar o registro, mostrar o 
// nome  do  aluno  para  simples  conferência,  fazer  as  alterações  das  notas,  calcular  a  média  e 
// apresentar na tela as notas e a média. 
 
// struct aluno{ 
//   char nome[80]; 
//   char RA[7]; 
//   float nota[2]; <- notas de provas – considerar 2 provas 
//   float media;   <- média aritmética das provas 
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno { 
  char nome[80]; 
  char RA[7]; 
  float nota[2];
  float media;  
} aluno;

void aloca(aluno **p_aluno, int tam);
void cadastro(aluno *p_aluno);
int buscar(aluno *p_aluno, int tam);
void notas(aluno *p_aluno);
void mostrar(aluno *p_aluno, int tam);

int main() {


  int tam = 0, op, indice;
  aluno *p_aluno = NULL;

  do{
    printf("\nEscolha umas das opcoes:\n");
    printf("Cadastro [1]\n");
    printf("Notas    [2]\n");
    printf("Alunos   [3]\n");
    printf("Sair     [4]\n");
    scanf("%i", &op);
    fflush(stdin);

    switch (op) {
      case 1:
        aloca(&p_aluno, tam+1);
        cadastro(p_aluno+tam);
        tam++;
        break;
      case 2:
        if((indice = buscar(p_aluno, tam)) >= 0)
          notas(p_aluno+indice);
        break;
      case 3:
        mostrar(p_aluno, tam);
        break;
      default:
        printf("Opcao invalida");
        break;
    }
  } while(op != 4);  
}

void aloca(aluno **p_aluno, int tam) {
  if ((*p_aluno = (aluno*) realloc(*p_aluno, tam * sizeof(aluno))) == NULL) {
    printf("Erro de alocação");
    exit(1);
  }
}

void cadastro(aluno *p_aluno) {
  printf("Digite o nome: ");
  fgets(p_aluno->nome, 80, stdin);

  fflush(stdin);

  printf("Digite o RA: ");
  fgets(p_aluno->RA, 7, stdin);

  p_aluno->nota[0] = 0;
  p_aluno->nota[1] = 0;
  p_aluno->media = 0;

  fflush(stdin);
}

int buscar(aluno *p_aluno, int tam) {
  char ra[7];
  printf("Digite o RA: ");
  fgets(ra, 7, stdin);

  for (int i = 0; i < tam; i++) {
    if(strcmp((p_aluno+i)->RA, ra) == 0) {
      return i;
    }
  }

  fflush(stdin);
  printf("Aluno não encontrado");
  return -1;
}

void notas(aluno *p_aluno) {
  do {
    fflush(stdin);
    printf("\nDigite a nota da primeira prova (0 a 10): ");
    scanf("%f", &p_aluno->nota[0]);
        
    if(p_aluno->nota[0] < 0 || p_aluno->nota[0] > 10) {
      printf("\nNota invalida\n");
    }

  } while(p_aluno->nota[0] < 0 || p_aluno->nota[0] > 10);

  fflush(stdin);

  do {
    fflush(stdin);
    printf("\nDigite a nota da segunda prova (0 a 10): ");
    scanf("%f", &p_aluno->nota[1]);
        
    if(p_aluno->nota[1] < 0 || p_aluno->nota[1] > 10) {
      printf("\nNota invalida\n");
    }
  } while(p_aluno->nota[1] < 0 || p_aluno->nota[1] > 10);

  p_aluno->media = (p_aluno->nota[0] + p_aluno->nota[1])/2;

  printf("\nNome: %sRA: %s\n", p_aluno->nome, p_aluno->RA);
  printf("Nota 1: %.1f\nNota 2: %.1f\nMedia: %.1f\n", p_aluno->nota[0], p_aluno->nota[1], p_aluno->media);
}

void mostrar(aluno *p_aluno, int tam) {
  system("cls");
  for (int i = 0; i < tam; i++) {
    printf("Nome: %sRA: %s\n", (p_aluno+i)->nome, (p_aluno+i)->RA);
    printf("Nota 1: %.1f\nNota 2: %.1f\nMedia: %.1f\n", (p_aluno+i)->nota[0], (p_aluno+i)->nota[1], (p_aluno+i)->media);
    printf("\n-------------------\n");
  }
}